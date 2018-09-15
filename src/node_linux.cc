#include "mechine_linux.cc"
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
		map<string, string> infos = getInfo();
		const char * cpuId = infos["cpuId"].data();
		const char * baseBoard = infos["baseBoard"].data();
		const char * macAddress = infos["macAddress"].data();
		cout << "cpuId---->" <<cpuId;
		cout << "baseBoard---->" <<baseBoard;
		cout << "macAddress---->" <<macAddress;
		Local<Object> obj = Object::New(isolate);
		obj->Set(String::NewFromUtf8(isolate, "processorId"), String::NewFromUtf8(isolate, cpuId));
		obj->Set(String::NewFromUtf8(isolate, "baseBoard"), String::NewFromUtf8(isolate, baseBoard));
		obj->Set(String::NewFromUtf8(isolate, "macAddress"), String::NewFromUtf8(isolate, macAddress));
		args.GetReturnValue().Set(obj);
	}

	void init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "exports", Method);
	}

	NODE_MODULE(addon, init);
}