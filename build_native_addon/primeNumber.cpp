#include <node.h>
#include <v8.h>
#include "../prime_number/prime_number.hpp"

void Method(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  double number = args[0]->NumberValue();
  bool data;
  PrimeNumber primeNumber;

  data = primeNumber.isPrime(number);
  v8::Local<v8::Boolean> result = v8::Boolean::New(isolate, data); 

  args.GetReturnValue().Set(result);
}

void init(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "isPrimeNumber", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)
