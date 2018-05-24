#ifndef MDUSER_H__
#define MDUSER_H__

#include "Struct.h"
#include "ThostFtdcMdApi.h"
#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"
#include <napi.h>
#include <iostream>
#include <map>
#include <string.h>
#include <uv.h>
#include "SafeQueue.h"

std::string getString(Napi::Object params, std::string key);
double getNumber(Napi::Object params, std::string key);
char getChar(Napi::Object params, std::string key);

class Mduser : public Napi::ObjectWrap<Mduser>, public CThostFtdcMdSpi {
public:
  Mduser(const Napi::CallbackInfo &info);
  ~Mduser(void);

  uv_async_t async_t;
  static std::map<std::string, int> eventMap;
  static std::map<int, Napi::Reference<Napi::Function> *> cbMap;
  static SafeQueue<uv_work_t *> queue;

  static Napi::Reference<Napi::Function> constructor;
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  Napi::Value On(const Napi::CallbackInfo &info);
  Napi::Value Call(const Napi::CallbackInfo &info);
  static void InitEventMap();

  CThostFtdcMdApi *api;

  static void AsyncFn(uv_work_t *req);
  static void AsyncAfterFn(uv_work_t *req);

  static bool isDebug;

  ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
  virtual void OnFrontConnected();

  ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
  ///@param nReason 错误原因
  ///        0x1001 网络读失败
  ///        0x1002 网络写失败
  ///        0x2001 接收心跳超时
  ///        0x2002 发送心跳失败
  ///        0x2003 收到错误报文
  virtual void OnFrontDisconnected(int nReason);

  ///心跳超时警告。当长时间未收到报文时，该方法被调用。
  ///@param nTimeLapse 距离上次接收报文的时间
  virtual void OnHeartBeatWarning(int nTimeLapse);

  ///登录请求响应
  virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

  ///登出请求响应
  virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

  ///错误应答
  virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

  ///订阅行情应答
  virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast);

  ///取消订阅行情应答
  virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo,
                                    int nRequestID, bool bIsLast);

  ///订阅询价应答
  virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                   bool bIsLast);

  ///取消订阅询价应答
  virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo,
                                     int nRequestID, bool bIsLast);

  ///深度行情通知
  virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

  ///询价通知
  virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);
};

struct MdCbField {
  Mduser *mduser;
  int errCode;
  int eventId;
  void *data;
  void *rspInfo;
  int nRequestID;
};

#endif