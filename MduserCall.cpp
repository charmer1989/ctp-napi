#include "Mduser.h"

int MdReqID = 1;

Napi::Value Mduser::Call(const Napi::CallbackInfo &info) {
  // 第一个参数, 函数名
  if (!info[0].IsString()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  std::string funcName = info[0].As<Napi::String>();

  if (funcName == "checkLoop") {
    uv_work_t *req;
    while (queue.try_pop(req)) {
      uv_queue_work(uv_default_loop(), req, AsyncFn, (uv_after_work_cb)AsyncAfterFn);
    }
    return Napi::Number::New(info.Env(), STATUS_SUCCESS);;
  }

  if (Mduser::isDebug) {
    std::cout << "[DEBUG in C++]: "
              << "Mduser::Call called" << std::endl;
  }

  // 第二个参数, 参数对象
  if (!info[1].IsObject()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  Napi::Object params = info[1].As<Napi::Object>();

  if (funcName == "connect") {
    MD_DEBUG_LOG("call function connect begin");
    this->api = CThostFtdcMdApi::CreateFtdcMdApi("");
    char address[50];
    strcpy(address, getString(params, "IP").c_str());
    this->api->RegisterSpi(this);
    this->api->RegisterFront(address);
    this->api->Init();
    MD_DEBUG_LOG("call function connect done!!!");
  } else if (funcName == "subscribeMarketData") {
    MD_DEBUG_LOG("call function subscribeMarketData");
    MdReqID++;
    char param[50];
    strcpy(param, getString(params, "InstrumentID").c_str());
    char *args[1] = {param};
    int ret       = this->api->SubscribeMarketData(args, 1);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "unSubscribeMarketData") {
    MD_DEBUG_LOG("call function unSubscribeMarketData");
    MdReqID++;
    char param[50];
    strcpy(param, getString(params, "InstrumentID").c_str());
    char *args[1] = {param};
    int ret       = this->api->UnSubscribeMarketData(args, 1);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "subscribeForQuoteRsp") {
    MD_DEBUG_LOG("call function subscribeForQuoteRsp");
    MdReqID++;
    char param[50];
    strcpy(param, getString(params, "InstrumentID").c_str());
    char *args[1] = {param};
    int ret       = this->api->SubscribeForQuoteRsp(args, 1);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "unSubscribeForQuoteRsp") {
    MD_DEBUG_LOG("call function unSubscribeForQuoteRsp");
    MdReqID++;
    char param[50];
    strcpy(param, getString(params, "InstrumentID").c_str());
    char *args[1] = {param};
    int ret       = this->api->UnSubscribeForQuoteRsp(args, 1);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqUserLogin") {
    MD_DEBUG_LOG("call function reqUserLogin");
    MdReqID++;
    CThostFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(CThostFtdcReqUserLoginField));
    strcpy(req.TradingDay, getString(params, "TradingDay").c_str());
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.Password, getString(params, "Password").c_str());
    strcpy(req.UserProductInfo, getString(params, "UserProductInfo").c_str());
    strcpy(req.InterfaceProductInfo, getString(params, "InterfaceProductInfo").c_str());
    strcpy(req.ProtocolInfo, getString(params, "ProtocolInfo").c_str());
    strcpy(req.MacAddress, getString(params, "MacAddress").c_str());
    strcpy(req.OneTimePassword, getString(params, "OneTimePassword").c_str());
    strcpy(req.ClientIPAddress, getString(params, "ClientIPAddress").c_str());
    strcpy(req.LoginRemark, getString(params, "LoginRemark").c_str());
    int ret = this->api->ReqUserLogin(&req, MdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqUserLogout") {
    MD_DEBUG_LOG("call function reqUserLogout");
    MdReqID++;
    CThostFtdcUserLogoutField req;
    memset(&req, 0, sizeof(CThostFtdcUserLogoutField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    int ret = this->api->ReqUserLogout(&req, MdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else {
    return Napi::Number::New(info.Env(), NONE_TRADER_API_FUNC);
  }

  return Napi::Number::New(info.Env(), STATUS_SUCCESS);
}