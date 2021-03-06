#include <node_api.h>
#include <assert.h>
#include "../prime_number/prime_number.hpp"

napi_value Method(napi_env env, napi_callback_info info)
{
  napi_status status;
  size_t argc = 1;
  napi_value args[0];

  status = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
  assert(status == napi_ok);

  // 引数の数をチェック
  if (argc == 0) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return nullptr;
  }

  // 引数の型をチェック
  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  if (valuetype != napi_number) {
    napi_throw_type_error(env, "Wrong arguments");
    return nullptr;
  }

  int32_t number;
  status = napi_get_value_int32(env, args[0], &number);
  assert(status == napi_ok);

  bool data;
  PrimeNumber primeNumber;
  data = primeNumber.isPrime((int)number);

  napi_value result;
  status = napi_get_boolean(env, data, &result);
  assert(status == napi_ok);

  return result;
}

void Init(napi_env env, napi_value exports, napi_value module, void* priv) {
  napi_status status;
  napi_value fn;
  status =  napi_create_function(env, NULL, Method, NULL, &fn);
  if (status != napi_ok) return;
  status = napi_set_named_property(env, exports, "isPrimeNumber", fn);
  if (status != napi_ok) return;
}

NAPI_MODULE(isPrimeNumber, Init)
