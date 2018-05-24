#include <napi.h>
#include "Mduser.h"
#include "Trader.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Mduser::Init(env, exports);
  Trader::Init(env, exports);
  return exports;
}

NODE_API_MODULE(ctp, Init)