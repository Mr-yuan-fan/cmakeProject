#ifndef __MY_ADDON_H_
#define __MY_ADDON_H_

#include <napi.h>

struct identityInfo
{
	std::string name;
	int32_t age;
	double height;
};

class MyAddon : public Napi::ObjectWrap<MyAddon> {

public:

	//µ¼³öº¯Êý
	static Napi::Object Init(Napi::Env env, Napi::Object exports);
	static Napi::FunctionReference constructor;

	MyAddon(const Napi::CallbackInfo& info);

public:

	Napi::Value getNumber(const Napi::CallbackInfo& info);
	Napi::Value setNumber(const Napi::CallbackInfo& info);

	Napi::Value getString(const Napi::CallbackInfo& info);
	Napi::Value setString(const Napi::CallbackInfo& info);


	Napi::Value setObj(const Napi::CallbackInfo& info);
	Napi::Value getObj(const Napi::CallbackInfo& info);


	Napi::Value getArray(const Napi::CallbackInfo& info);
	Napi::Value setArray(const Napi::CallbackInfo& info);
	Napi::Value generateCustomArray(const Napi::CallbackInfo& info);

	void asyncCall(const Napi::CallbackInfo& info);
	void syncCall(const Napi::CallbackInfo& info);

private:

	int m_value = 10;
	std::string m_str = "hello addon";

	identityInfo idInfo;
	std::vector<std::string> m_vec;
};

#endif
