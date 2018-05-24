#include "Mduser.h"

Napi::Reference<Napi::Function> Mduser::constructor;
std::map<std::string, int> Mduser::eventMap;
std::map<int, Napi::Reference<Napi::Function> *> Mduser::cbMap;
bool Mduser::isDebug = false;
SafeQueue<uv_work_t *> Mduser::queue;

// std::string getString(Napi::Object params, std::string key) {
//   if (params.Get(key).IsUndefined()) {
//     std::string space("");
//     return space;
//   }
//   return params.Get(key).As<Napi::String>().Utf8Value();
// };

// double getNumber(Napi::Object params, std::string key) {
//   if (params.Get(key).IsUndefined()) {
//     return 0;
//   }
//   return (double)(params.Get(key).As<Napi::Number>());
// };

// char getChar(Napi::Object params, std::string key) {
//   if (params.Get(key).IsUndefined()) {
//     return '\0';
//   }
//   std::string str = params.Get(key).As<Napi::String>().Utf8Value();
//   return str.c_str()[0];
// };

// double roundFunc(double x, int n) { return round(x * pow(10, n)) / pow(10, n); };

Mduser::Mduser(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Mduser>(info) {
  if (info[0].IsObject()) {
    Napi::Object obj = info[0].As<Napi::Object>();
    bool _isDebug    = obj.Get("debug").ToBoolean();
    Mduser::isDebug  = _isDebug;
  } else {
    Mduser::isDebug = false;
  }
  Mduser::InitEventMap();
  uv_async_init(uv_default_loop(), &async_t, NULL);
}
Mduser::~Mduser(void){};

void Mduser::InitEventMap() {
  eventMap["frontConnected"]      = ON_FRONT_CONNECTED;
  eventMap["frontDisconnected"]   = ON_FRONT_DISCONNECTED;
  eventMap["heartBeatWarning"]    = ON_HEART_BEAT_WARNING;
  eventMap["rspUserLogin"]        = ON_RSP_USER_LOGIN;
  eventMap["rspUserLogout"]       = ON_RSP_USER_LOGOUT;
  eventMap["rspError"]            = ON_RSP_ERROR;
  eventMap["rspSubMarketData"]    = ON_RSP_SUB_MARKET_DATA;
  eventMap["rspUnSubMarketData"]  = ON_RSP_UN_SUB_MARKET_DATA;
  eventMap["rspSubForQuoteRsp"]   = ON_RSP_SUB_FOR_QUOTE_RSP;
  eventMap["rspUnSubForQuoteRsp"] = ON_RSP_UN_SUB_FOR_QUOTE_RSP;
  eventMap["rtnDepthMarketData"]  = ON_RTN_DEPTH_MARKET_DATA;
  eventMap["rtnForQuoteRsp"]      = ON_RTN_FOR_QUOTE_RSP;
};
Napi::Object Mduser::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  Napi::Function ctor = DefineClass(env, "Mduser",
                                    {
                                        InstanceMethod("On", &Mduser::On), InstanceMethod("Call", &Mduser::Call),
                                    });

  constructor = Napi::Persistent(ctor);
  constructor.SuppressDestruct();
  exports.Set("Mduser", ctor);
  return exports;
};

Napi::Value Mduser::On(const Napi::CallbackInfo &info) {
  if (Mduser::isDebug) {
    std::cout << "[DEBUG in C++]: "
              << "Mduser::On called" << std::endl;
  }
  if (!info[0].IsString()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  if (!info[1].IsFunction()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  std::string eventName = info[0].As<Napi::String>();
  std::map<std::string, int>::iterator eIt = Mduser::eventMap.find(eventName);
  if (eIt == Mduser::eventMap.end()) {
    throw Napi::Error::New(info.Env(), "没有被注册的事件类型");
  }
  int eventId = eIt->second;
  std::map<int, Napi::Reference<Napi::Function> *>::iterator cIt = Mduser::cbMap.find(eIt->second);
  if (cIt != Mduser::cbMap.end()) {
    throw Napi::Error::New(info.Env(), "此事件已经被绑定过");
  }
  Mduser::cbMap[eventId] = new Napi::Reference<Napi::Function>();
  Mduser::cbMap[eventId]->Reset(info[1].As<Napi::Function>(), 1);

  return info.Env().Null();
};
