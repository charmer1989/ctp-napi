#include "Trader.h"

Napi::Reference<Napi::Function> Trader::constructor;
std::map<std::string, int> Trader::eventMap;
std::map<int, Napi::Reference<Napi::Function> *> Trader::cbMap;
bool Trader::isDebug = false;

std::string getString(Napi::Object params, std::string key) {
  if (params.Get(key).IsUndefined()) {
    std::string space("");
    return space;
  }
  return params.Get(key).As<Napi::String>().Utf8Value();
};

double getNumber(Napi::Object params, std::string key) {
  if (params.Get(key).IsUndefined()) {
    return 0;
  }
  return (double)(params.Get(key).As<Napi::Number>());
};

char getChar(Napi::Object params, std::string key) {
  if (params.Get(key).IsUndefined()) {
    return '\0';
  }
  std::string str = params.Get(key).As<Napi::String>().Utf8Value();
  return str.c_str()[0];
};

double roundFunc(double x, int n) { return round(x * pow(10, n)) / pow(10, n); };

Trader::Trader(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Trader>(info) {
  if (info[0].IsObject()) {
    Napi::Object obj = info[0].As<Napi::Object>();
    bool _isDebug    = obj.Get("debug").ToBoolean();
    Trader::isDebug  = _isDebug;
  } else {
    Trader::isDebug = false;
  }
  Trader::InitEventMap();
  uv_async_init(uv_default_loop(), &async_t, NULL);
}
Trader::~Trader(void){};

void Trader::InitEventMap() {
  eventMap["frontConnected"]                          = ON_FRONT_CONNECTED;
  eventMap["frontDisconnected"]                       = ON_FRONT_DISCONNECTED;
  eventMap["heartBeatWarning"]                        = ON_HEART_BEAT_WARNING;
  eventMap["rspAuthenticate"]                         = ON_RSP_AUTHENTICATE;
  eventMap["rspUserLogin"]                            = ON_RSP_USER_LOGIN;
  eventMap["rspUserLogout"]                           = ON_RSP_USER_LOGOUT;
  eventMap["rspUserPasswordUpdate"]                   = ON_RSP_USER_PASSWORD_UPDATE;
  eventMap["rspTradingAccountPasswordUpdate"]         = ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE;
  eventMap["rspOrderInsert"]                          = ON_RSP_ORDER_INSERT;
  eventMap["rspParkedOrderInsert"]                    = ON_RSP_PARKED_ORDER_INSERT;
  eventMap["rspParkedOrderAction"]                    = ON_RSP_PARKED_ORDER_ACTION;
  eventMap["rspOrderAction"]                          = ON_RSP_ORDER_ACTION;
  eventMap["rspQueryMaxOrderVolume"]                  = ON_RSP_QUERY_MAX_ORDER_VOLUME;
  eventMap["rspSettlementInfoConfirm"]                = ON_RSP_SETTLEMENT_INFO_CONFIRM;
  eventMap["rspRemoveParkedOrder"]                    = ON_RSP_REMOVE_PARKED_ORDER;
  eventMap["rspRemoveParkedOrderAction"]              = ON_RSP_REMOVE_PARKED_ORDER_ACTION;
  eventMap["rspExecOrderInsert"]                      = ON_RSP_EXEC_ORDER_INSERT;
  eventMap["rspExecOrderAction"]                      = ON_RSP_EXEC_ORDER_ACTION;
  eventMap["rspForQuoteInsert"]                       = ON_RSP_FOR_QUOTE_INSERT;
  eventMap["rspQuoteInsert"]                          = ON_RSP_QUOTE_INSERT;
  eventMap["rspQuoteAction"]                          = ON_RSP_QUOTE_ACTION;
  eventMap["rspBatchOrderAction"]                     = ON_RSP_BATCH_ORDER_ACTION;
  eventMap["rspCombActionInsert"]                     = ON_RSP_COMB_ACTION_INSERT;
  eventMap["rspQryOrder"]                             = ON_RSP_QRY_ORDER;
  eventMap["rspQryTrade"]                             = ON_RSP_QRY_TRADE;
  eventMap["rspQryInvestorPosition"]                  = ON_RSP_QRY_INVESTOR_POSITION;
  eventMap["rspQryTradingAccount"]                    = ON_RSP_QRY_TRADING_ACCOUNT;
  eventMap["rspQryInvestor"]                          = ON_RSP_QRY_INVESTOR;
  eventMap["rspQryTradingCode"]                       = ON_RSP_QRY_TRADING_CODE;
  eventMap["rspQryInstrumentMarginRate"]              = ON_RSP_QRY_INSTRUMENT_MARGIN_RATE;
  eventMap["rspQryInstrumentCommissionRate"]          = ON_RSP_QRY_INSTRUMENT_COMMISSION_RATE;
  eventMap["rspQryExchange"]                          = ON_RSP_QRY_EXCHANGE;
  eventMap["rspQryProduct"]                           = ON_RSP_QRY_PRODUCT;
  eventMap["rspQryInstrument"]                        = ON_RSP_QRY_INSTRUMENT;
  eventMap["rspQryDepthMarketData"]                   = ON_RSP_QRY_DEPTH_MARKET_DATA;
  eventMap["rspQrySettlementInfo"]                    = ON_RSP_QRY_SETTLEMENT_INFO;
  eventMap["rspQryTransferBank"]                      = ON_RSP_QRY_TRANSFER_BANK;
  eventMap["rspQryInvestorPositionDetail"]            = ON_RSP_QRY_INVESTOR_POSITION_DETAIL;
  eventMap["rspQryNotice"]                            = ON_RSP_QRY_NOTICE;
  eventMap["rspQrySettlementInfoConfirm"]             = ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM;
  eventMap["rspQryInvestorPositionCombineDetail"]     = ON_RSP_QRY_INVESTOR_POSITION_COMBINE_DETAIL;
  eventMap["rspQryCfmmcTradingAccountKey"]            = ON_RSP_QRY_CFMMC_TRADING_ACCOUNT_KEY;
  eventMap["rspQryEWarrantOffset"]                    = ON_RSP_QRY_E_WARRANT_OFFSET;
  eventMap["rspQryInvestorProductGroupMargin"]        = ON_RSP_QRY_INVESTOR_PRODUCT_GROUP_MARGIN;
  eventMap["rspQryExchangeMarginRate"]                = ON_RSP_QRY_EXCHANGE_MARGIN_RATE;
  eventMap["rspQryExchangeMarginRateAdjust"]          = ON_RSP_QRY_EXCHANGE_MARGIN_RATE_ADJUST;
  eventMap["rspQryExchangeRate"]                      = ON_RSP_QRY_EXCHANGE_RATE;
  eventMap["rspQrySecAgentAcidMap"]                   = ON_RSP_QRY_SEC_AGENT_ACID_MAP;
  eventMap["rspQryProductExchRate"]                   = ON_RSP_QRY_PRODUCT_EXCH_RATE;
  eventMap["rspQryProductGroup"]                      = ON_RSP_QRY_PRODUCT_GROUP;
  eventMap["rspQryMmInstrumentCommissionRate"]        = ON_RSP_QRY_MM_INSTRUMENT_COMMISSION_RATE;
  eventMap["rspQryMmOptionInstrCommRate"]             = ON_RSP_QRY_MM_OPTION_INSTR_COMM_RATE;
  eventMap["rspQryInstrumentOrderCommRate"]           = ON_RSP_QRY_INSTRUMENT_ORDER_COMM_RATE;
  eventMap["rspQryOptionInstrTradeCost"]              = ON_RSP_QRY_OPTION_INSTR_TRADE_COST;
  eventMap["rspQryOptionInstrCommRate"]               = ON_RSP_QRY_OPTION_INSTR_COMM_RATE;
  eventMap["rspQryExecOrder"]                         = ON_RSP_QRY_EXEC_ORDER;
  eventMap["rspQryForQuote"]                          = ON_RSP_QRY_FOR_QUOTE;
  eventMap["rspQryQuote"]                             = ON_RSP_QRY_QUOTE;
  eventMap["rspQryCombInstrumentGuard"]               = ON_RSP_QRY_COMB_INSTRUMENT_GUARD;
  eventMap["rspQryCombAction"]                        = ON_RSP_QRY_COMB_ACTION;
  eventMap["rspQryTransferSerial"]                    = ON_RSP_QRY_TRANSFER_SERIAL;
  eventMap["rspQryAccountregister"]                   = ON_RSP_QRY_ACCOUNTREGISTER;
  eventMap["rspError"]                                = ON_RSP_ERROR;
  eventMap["rtnOrder"]                                = ON_RTN_ORDER;
  eventMap["rtnTrade"]                                = ON_RTN_TRADE;
  eventMap["errRtnOrderInsert"]                       = ON_ERR_RTN_ORDER_INSERT;
  eventMap["errRtnOrderAction"]                       = ON_ERR_RTN_ORDER_ACTION;
  eventMap["rtnInstrumentStatus"]                     = ON_RTN_INSTRUMENT_STATUS;
  eventMap["rtnBulletin"]                             = ON_RTN_BULLETIN;
  eventMap["rtnTradingNotice"]                        = ON_RTN_TRADING_NOTICE;
  eventMap["rtnErrorConditionalOrder"]                = ON_RTN_ERROR_CONDITIONAL_ORDER;
  eventMap["rtnExecOrder"]                            = ON_RTN_EXEC_ORDER;
  eventMap["errRtnExecOrderInsert"]                   = ON_ERR_RTN_EXEC_ORDER_INSERT;
  eventMap["errRtnExecOrderAction"]                   = ON_ERR_RTN_EXEC_ORDER_ACTION;
  eventMap["errRtnForQuoteInsert"]                    = ON_ERR_RTN_FOR_QUOTE_INSERT;
  eventMap["rtnQuote"]                                = ON_RTN_QUOTE;
  eventMap["errRtnQuoteInsert"]                       = ON_ERR_RTN_QUOTE_INSERT;
  eventMap["errRtnQuoteAction"]                       = ON_ERR_RTN_QUOTE_ACTION;
  eventMap["rtnForQuoteRsp"]                          = ON_RTN_FOR_QUOTE_RSP;
  eventMap["rtnCfmmcTradingAccountToken"]             = ON_RTN_CFMMC_TRADING_ACCOUNT_TOKEN;
  eventMap["errRtnBatchOrderAction"]                  = ON_ERR_RTN_BATCH_ORDER_ACTION;
  eventMap["rtnCombAction"]                           = ON_RTN_COMB_ACTION;
  eventMap["errRtnCombActionInsert"]                  = ON_ERR_RTN_COMB_ACTION_INSERT;
  eventMap["rspQryContractBank"]                      = ON_RSP_QRY_CONTRACT_BANK;
  eventMap["rspQryParkedOrder"]                       = ON_RSP_QRY_PARKED_ORDER;
  eventMap["rspQryParkedOrderAction"]                 = ON_RSP_QRY_PARKED_ORDER_ACTION;
  eventMap["rspQryTradingNotice"]                     = ON_RSP_QRY_TRADING_NOTICE;
  eventMap["rspQryBrokerTradingParams"]               = ON_RSP_QRY_BROKER_TRADING_PARAMS;
  eventMap["rspQryBrokerTradingAlgos"]                = ON_RSP_QRY_BROKER_TRADING_ALGOS;
  eventMap["rspQueryCfmmcTradingAccountToken"]        = ON_RSP_QUERY_CFMMC_TRADING_ACCOUNT_TOKEN;
  eventMap["rtnFromBankToFutureByBank"]               = ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK;
  eventMap["rtnFromFutureToBankByBank"]               = ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK;
  eventMap["rtnRepealFromBankToFutureByBank"]         = ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK;
  eventMap["rtnRepealFromFutureToBankByBank"]         = ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK;
  eventMap["rtnFromBankToFutureByFuture"]             = ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE;
  eventMap["rtnFromFutureToBankByFuture"]             = ON_RTN_FROM_FUTURE_TO_BANK_BY_FUTURE;
  eventMap["rtnRepealFromBankToFutureByFutureManual"] = ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL;
  eventMap["rtnRepealFromFutureToBankByFutureManual"] = ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL;
  eventMap["rtnQueryBankBalanceByFuture"]             = ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE;
  eventMap["errRtnBankToFutureByFuture"]              = ON_ERR_RTN_BANK_TO_FUTURE_BY_FUTURE;
  eventMap["errRtnFutureToBankByFuture"]              = ON_ERR_RTN_FUTURE_TO_BANK_BY_FUTURE;
  eventMap["errRtnRepealBankToFutureByFutureManual"]  = ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL;
  eventMap["errRtnRepealFutureToBankByFutureManual"]  = ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL;
  eventMap["errRtnQueryBankBalanceByFuture"]          = ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE;
  eventMap["rtnRepealFromBankToFutureByFuture"]       = ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE;
  eventMap["rtnRepealFromFutureToBankByFuture"]       = ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE;
  eventMap["rspFromBankToFutureByFuture"]             = ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE;
  eventMap["rspFromFutureToBankByFuture"]             = ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE;
  eventMap["rspQueryBankAccountMoneyByFuture"]        = ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE;
  eventMap["rtnOpenAccountByBank"]                    = ON_RTN_OPEN_ACCOUNT_BY_BANK;
  eventMap["rtnCancelAccountByBank"]                  = ON_RTN_CANCEL_ACCOUNT_BY_BANK;
  eventMap["rtnChangeAccountByBank"]                  = ON_RTN_CHANGE_ACCOUNT_BY_BANK;
};
Napi::Object Trader::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  Napi::Function ctor = DefineClass(env, "Trader",
                                    {
                                        InstanceMethod("On", &Trader::On), InstanceMethod("Call", &Trader::Call),
                                    });

  constructor = Napi::Persistent(ctor);
  constructor.SuppressDestruct();
  exports.Set("Trader", ctor);
  return exports;
};

Napi::Value Trader::On(const Napi::CallbackInfo &info) {
  if (Trader::isDebug) {
    std::cout << "[DEBUG in C++]: "
              << "Trader::On called" << std::endl;
  }
  if (!info[0].IsString()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  if (!info[1].IsFunction()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  std::string eventName = info[0].As<Napi::String>();
  std::map<std::string, int>::iterator eIt = Trader::eventMap.find(eventName);
  if (eIt == Trader::eventMap.end()) {
    throw Napi::Error::New(info.Env(), "没有被注册的事件类型");
  }
  int eventId = eIt->second;
  std::map<int, Napi::Reference<Napi::Function> *>::iterator cIt = Trader::cbMap.find(eIt->second);
  if (cIt != Trader::cbMap.end()) {
    throw Napi::Error::New(info.Env(), "此事件已经被绑定过");
  }
  Trader::cbMap[eventId] = new Napi::Reference<Napi::Function>();
  Trader::cbMap[eventId]->Reset(info[1].As<Napi::Function>(), 1);

  return info.Env().Null();
};