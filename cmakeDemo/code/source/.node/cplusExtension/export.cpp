#include "myAddon.h"

//�����ӿ�
Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
	return MyAddon::Init(env, exports);
}

NODE_API_MODULE(MyAddon, InitAll)
