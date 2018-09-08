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
		Local<Object> obj = Object::New(isolate);
		obj->Set(String::NewFromUtf8(isolate, "macAddressRoot"), String::NewFromUtf8(isolate, infos["macAddressRoot"]));
		obj->Set(String::NewFromUtf8(isolate, "diskDriveSerialNumber"), String::NewFromUtf8(isolate, infos["diskDriveSerialNumber"]));
		obj->Set(String::NewFromUtf8(isolate, "baseBoardSerialNumber"), String::NewFromUtf8(isolate, infos["baseBoardSerialNumber"]));
		obj->Set(String::NewFromUtf8(isolate, "processorId"), String::NewFromUtf8(isolate, infos["processorId"]));
		obj->Set(String::NewFromUtf8(isolate, "biosSerialNumber"), String::NewFromUtf8(isolate, infos["biosSerialNumber"]));
		obj->Set(String::NewFromUtf8(isolate, "baseBoard"), String::NewFromUtf8(isolate, infos["baseBoard"]));
		obj->Set(String::NewFromUtf8(isolate, "macAddress"), String::NewFromUtf8(isolate, infos["macAddress"]));
		args.GetReturnValue().Set(obj);
	}

	void init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "exports", Method);
	}

	NODE_MODULE(addon, init);
}