#include "mechine_windows.cc"
#include<node.h>
#include<iostream>
namespace demo {
	using std::cout;
	using std::endl;
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;
	using v8::Exception;

	void Method(const FunctionCallbackInfo<Value>& args) {
		Isolate * isolate = args.GetIsolate();
		map<const char *, char *> infos = getAllInfo();
		const char * macAddressRoot = infos["macAddressRoot"];
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, macAddressRoot));
	}

	void init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "hello", Method);
	}

	NODE_MODULE(addon, init);
}