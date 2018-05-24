#include "Mduser.h"

void Mduser::OnFrontConnected() { MD_EVENT_FUNC("OnFrontConnected", ON_FRONT_CONNECTED, 0); };
void Mduser::OnFrontDisconnected(int nReason) { MD_EVENT_FUNC("OnFrontDisconnected", ON_FRONT_DISCONNECTED, nReason); };
void Mduser::OnHeartBeatWarning(int nTimeLapse) { MD_EVENT_FUNC("OnHeartBeatWarning", ON_HEART_BEAT_WARNING, nTimeLapse); };

void Mduser::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  MD_DEBUG_LOG("OnRspUserLogin called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspUserLogin) {
    CThostFtdcRspUserLoginField *_info = new CThostFtdcRspUserLoginField();
    memcpy(_info, pRspUserLogin, sizeof(CThostFtdcRspUserLoginField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_USER_LOGIN, 0);
};
void Mduser::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  MD_DEBUG_LOG("OnRspUserLogout called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pUserLogout) {
    CThostFtdcUserLogoutField *_info = new CThostFtdcUserLogoutField();
    memcpy(_info, pUserLogout, sizeof(CThostFtdcUserLogoutField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_USER_LOGOUT, 0);
};
void Mduser::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {

  MD_DEBUG_LOG("OnRspError called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  field->data       = nullptr;
  MD_EVENT_CALL(field, ON_RSP_ERROR, 0);
};
void Mduser::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                bool bIsLast) {

  MD_DEBUG_LOG("OnRspSubMarketData called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSpecificInstrument) {
    CThostFtdcSpecificInstrumentField *_info = new CThostFtdcSpecificInstrumentField();
    memcpy(_info, pSpecificInstrument, sizeof(CThostFtdcSpecificInstrumentField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_SUB_MARKET_DATA, 0);
};
void Mduser::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast) {

  MD_DEBUG_LOG("OnRspUnSubMarketData called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSpecificInstrument) {
    CThostFtdcSpecificInstrumentField *_info = new CThostFtdcSpecificInstrumentField();
    memcpy(_info, pSpecificInstrument, sizeof(CThostFtdcSpecificInstrumentField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_UN_SUB_MARKET_DATA, 0);
};
void Mduser::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                 bool bIsLast) {

  MD_DEBUG_LOG("OnRspSubForQuoteRsp called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSpecificInstrument) {
    CThostFtdcSpecificInstrumentField *_info = new CThostFtdcSpecificInstrumentField();
    memcpy(_info, pSpecificInstrument, sizeof(CThostFtdcSpecificInstrumentField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_SUB_FOR_QUOTE_RSP, 0);
};
void Mduser::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                   bool bIsLast) {

  MD_DEBUG_LOG("OnRspUnSubForQuoteRsp called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSpecificInstrument) {
    CThostFtdcSpecificInstrumentField *_info = new CThostFtdcSpecificInstrumentField();
    memcpy(_info, pSpecificInstrument, sizeof(CThostFtdcSpecificInstrumentField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_UN_SUB_FOR_QUOTE_RSP, 0);
};
void Mduser::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) {

  MD_DEBUG_LOG("OnRtnDepthMarketData called.");
  MdCbField *field  = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pDepthMarketData) {
    CThostFtdcDepthMarketDataField *_info = new CThostFtdcDepthMarketDataField();
    memcpy(_info, pDepthMarketData, sizeof(CThostFtdcDepthMarketDataField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  // MD_EVENT_CALL(field, ON_RTN_DEPTH_MARKET_DATA, 0);
  field->mduser  = this;
  field->errCode = 0;
  field->eventId = ON_RTN_DEPTH_MARKET_DATA;
  req->data      = field;
  queue.push(req);
};
void Mduser::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) {

  MD_DEBUG_LOG("OnRtnForQuoteRsp called.");
  MdCbField *field  = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pForQuoteRsp) {
    CThostFtdcForQuoteRspField *_info = new CThostFtdcForQuoteRspField();
    memcpy(_info, pForQuoteRsp, sizeof(CThostFtdcForQuoteRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RTN_FOR_QUOTE_RSP, 0);
};
