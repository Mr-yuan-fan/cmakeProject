#include "myAddon.h"
#include "myAsyncWorker.h"


Napi::FunctionReference MyAddon::constructor;


MyAddon::MyAddon(const Napi::CallbackInfo& info) : Napi::ObjectWrap<MyAddon>(info)
{
}

Napi::Value MyAddon::getNumber(const Napi::CallbackInfo& info)
{
	return Napi::Number::New(info.Env(), m_value);
}

Napi::Value MyAddon::setNumber(const Napi::CallbackInfo& info)
{
	int len = info.Length();

	Napi::Env env = info.Env();

	if (len <= 0 || !info[0].IsNumber()) {
		Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
	}

	Napi::Number value = info[0].As<Napi::Number>();
	m_value = value.Int32Value();

	std::string msg = "number " + std::to_string(value.Int32Value()) + " set success";
	return Napi::String::New(info.Env(), msg);
}

Napi::Value MyAddon::setString(const Napi::CallbackInfo& info)
{
	if (info.Length() < 1 || !info[0].IsString())
	{
		Napi::TypeError::New(info.Env(), "String expected").ThrowAsJavaScriptException();
		return info.Env().Null();
	}

	std::string str = info[0].As<Napi::String>();
	m_str = str;

	std::string msg = "str " + str + " set success";
	return Napi::String::New(info.Env(), msg);
}

Napi::Value MyAddon::getString(const Napi::CallbackInfo& info)
{
	return Napi::String::New(info.Env(), m_str);
}

Napi::Value MyAddon::setObj(const Napi::CallbackInfo& info)
{
	if (info.Length() <1 || !info[0].IsObject())
	{
		Napi::TypeError::New(info.Env(), "right id info expected").ThrowAsJavaScriptException();
		return info.Env().Null();
	}

	Napi::Object request = info[0].As<Napi::Object>();

	std::string name = request.Get(static_cast<napi_value>(Napi::String::New(info.Env(), "name"))).As<Napi::String>();
	int32_t age = request.Get(static_cast<napi_value>(Napi::String::New(info.Env(),"age"))).As<Napi::Number>();
	int32_t height = request.Get(static_cast<napi_value>(Napi::String::New(info.Env(),"height"))).As<Napi::Number>();

	idInfo.name = name;
	idInfo.age = age;
	idInfo.height = height;

	std::string msg = "name : " + name + " set success ; " + "age : " + std::to_string(age) + " set success ;" + "height : " + std::to_string(height) + " set success";
	return Napi::String::New(info.Env(), msg);
}

Napi::Value MyAddon::getObj(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();
	Napi::Object response = Napi::Object::New(env);
	response.Set(Napi::String::New(env, "name"), Napi::String::New(env, idInfo.name));
	response.Set(Napi::String::New(env, "age"), Napi::Number::New(env, idInfo.age));
	response.Set(Napi::String::New(env, "height"), Napi::Number::New(env, idInfo.height));

	return response;
}

Napi::Value MyAddon::getArray(const Napi::CallbackInfo& info)
{

	Napi::Env env = info.Env();
	Napi::Array response = Napi::Array::New(env);
	for (int32_t i = 0; i < m_vec.size(); ++i)
	{
		response.Set(Napi::Number::New(env, i), Napi::String::New(env, m_vec[i]));
	}

	return response;
}

Napi::Value MyAddon::setArray(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	int32_t paramLen = info.Length();
	if (paramLen < 1 || !info[0].IsArray())
	{
		Napi::TypeError::New(env, "right array expected").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (paramLen == 1 || !info[1].IsBoolean() || info[0].As<Napi::Boolean>())
	{
		m_vec.clear();
	}

	Napi::Array arr = info[0].As<Napi::Array>();

	int32_t arrLen = arr.Length();

	//vector元素为string
	for (int32_t i = 0; i < arrLen; ++i)
	{
		std::string arrElement = arr.Get(static_cast<napi_value>(Napi::Number::New(info.Env(), i))).As<Napi::String>();
		m_vec.push_back(arrElement);
	}

	std::string msg = "array set success";
	return Napi::String::New(info.Env(), msg);
}

Napi::Value MyAddon::generateCustomArray(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	// 准备返回给js，c++数组
	Napi::Array response = Napi::Array::New(env);

	// 准备一个对象
	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "name"), Napi::String::New(env, "zhangsan"));

	// 给数组填充值
	response.Set(Napi::Number::New(env, 0), Napi::String::New(env, "balabala"));
	response.Set(Napi::Number::New(env, 1), Napi::Number::New(env, 36));
	response.Set(Napi::Number::New(env, 2), Napi::Number::New(env, 66.5));
	response.Set(Napi::Number::New(env, 3), obj);

	return response;
}

void MyAddon::asyncCall(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	int32_t runtime = info[0].As<Napi::Number>();
	Napi::Function callback = info[1].As<Napi::Function>();

	MyAsyncWorker::getInstance(callback, runtime)->Queue();
}


void MyAddon::syncCall(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	int32_t runtime = info[0].As<Napi::Number>();
	Napi::Function callback = info[1].As<Napi::Function>();

	std::this_thread::sleep_for(std::chrono::seconds(runtime));
	callback.Call(env.Global(), { Napi::String::New(env, "this is syncCall pushback!") });
}

Napi::Object MyAddon::Init(Napi::Env env, Napi::Object exports)
{
	Napi::HandleScope scope(env);

	Napi::Function func =
		DefineClass(env,
			"MyAddon",
			{
				InstanceMethod("getNumber", &MyAddon::getNumber),
				InstanceMethod("setNumber", &MyAddon::setNumber),

				InstanceMethod("asyncCall", &MyAddon::asyncCall),
				InstanceMethod("syncCall", &MyAddon::syncCall),

				InstanceMethod("getString", &MyAddon::getString),
				InstanceMethod("setString", &MyAddon::setString),

				InstanceMethod("setObj", &MyAddon::setObj),
				InstanceMethod("getObj", &MyAddon::getObj),

				InstanceMethod("setArray", &MyAddon::setArray),
				InstanceMethod("getArray", &MyAddon::getArray),
				InstanceMethod("generateCustomArray", &MyAddon::generateCustomArray),
			});

	constructor = Napi::Persistent(func);
	constructor.SuppressDestruct();

	exports.Set("MyAddon", func);

	return exports;
}
