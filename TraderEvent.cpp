#include "Trader.h"

void Trader::OnFrontConnected() {
  TD_DEBUG_LOG("OnFrontConnected called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  field->data       = nullptr;
  TD_EVENT_CALL(field, ON_FRONT_CONNECTED, 0);
};
void Trader::OnFrontDisconnected(int nReason) {
  TD_DEBUG_LOG("OnFrontDisconnected called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  field->data       = nullptr;
  TD_EVENT_CALL(field, ON_FRONT_DISCONNECTED, 0);
};
void Trader::OnHeartBeatWarning(int nTimeLapse) {
  TD_DEBUG_LOG("OnHeartBeatWarning called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  field->data       = nullptr;
  TD_EVENT_CALL(field, ON_HEART_BEAT_WARNING, 0);
};
void Trader::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                               bool bIsLast) {
  TD_DEBUG_LOG("OnRspAuthenticate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspAuthenticateField) {
    CThostFtdcRspAuthenticateField *_info = new CThostFtdcRspAuthenticateField();
    memcpy(_info, pRspAuthenticateField, sizeof(CThostFtdcRspAuthenticateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_AUTHENTICATE, 0);
};
void Trader::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspUserLogin called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
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
  TD_EVENT_CALL(field, ON_RSP_USER_LOGIN, 0);
};
void Trader::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspUserLogout called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
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
  TD_EVENT_CALL(field, ON_RSP_USER_LOGOUT, 0);
};
void Trader::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo,
                                     int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspUserPasswordUpdate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pUserPasswordUpdate) {
    CThostFtdcUserPasswordUpdateField *_info = new CThostFtdcUserPasswordUpdateField();
    memcpy(_info, pUserPasswordUpdate, sizeof(CThostFtdcUserPasswordUpdateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_USER_PASSWORD_UPDATE, 0);
};
void Trader::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate,
                                               CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspTradingAccountPasswordUpdate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTradingAccountPasswordUpdate) {
    CThostFtdcTradingAccountPasswordUpdateField *_info = new CThostFtdcTradingAccountPasswordUpdateField();
    memcpy(_info, pTradingAccountPasswordUpdate, sizeof(CThostFtdcTradingAccountPasswordUpdateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE, 0);
};
void Trader::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  
  TD_DEBUG_LOG("OnRspOrderInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputOrder) {
    CThostFtdcInputOrderField *_info = new CThostFtdcInputOrderField();
    memcpy(_info, pInputOrder, sizeof(CThostFtdcInputOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_ORDER_INSERT, 0);
  
};
void Trader::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspParkedOrderInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pParkedOrder) {
    CThostFtdcParkedOrderField *_info = new CThostFtdcParkedOrderField();
    memcpy(_info, pParkedOrder, sizeof(CThostFtdcParkedOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_PARKED_ORDER_INSERT, 0);
};
void Trader::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspParkedOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pParkedOrderAction) {
    CThostFtdcParkedOrderActionField *_info = new CThostFtdcParkedOrderActionField();
    memcpy(_info, pParkedOrderAction, sizeof(CThostFtdcParkedOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_PARKED_ORDER_ACTION, 0);
};
void Trader::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                              bool bIsLast) {
  
  TD_DEBUG_LOG("OnRspOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputOrderAction) {
    CThostFtdcInputOrderActionField *_info = new CThostFtdcInputOrderActionField();
    memcpy(_info, pInputOrderAction, sizeof(CThostFtdcInputOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_ORDER_ACTION, 0);
  
};
void Trader::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo,
                                      int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQueryMaxOrderVolume called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pQueryMaxOrderVolume) {
    CThostFtdcQueryMaxOrderVolumeField *_info = new CThostFtdcQueryMaxOrderVolumeField();
    memcpy(_info, pQueryMaxOrderVolume, sizeof(CThostFtdcQueryMaxOrderVolumeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QUERY_MAX_ORDER_VOLUME, 0);
};
void Trader::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo,
                                        int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspSettlementInfoConfirm called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSettlementInfoConfirm) {
    CThostFtdcSettlementInfoConfirmField *_info = new CThostFtdcSettlementInfoConfirmField();
    memcpy(_info, pSettlementInfoConfirm, sizeof(CThostFtdcSettlementInfoConfirmField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_SETTLEMENT_INFO_CONFIRM, 0);
};
void Trader::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspRemoveParkedOrder called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRemoveParkedOrder) {
    CThostFtdcRemoveParkedOrderField *_info = new CThostFtdcRemoveParkedOrderField();
    memcpy(_info, pRemoveParkedOrder, sizeof(CThostFtdcRemoveParkedOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_REMOVE_PARKED_ORDER, 0);
};
void Trader::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction,
                                          CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspRemoveParkedOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRemoveParkedOrderAction) {
    CThostFtdcRemoveParkedOrderActionField *_info = new CThostFtdcRemoveParkedOrderActionField();
    memcpy(_info, pRemoveParkedOrderAction, sizeof(CThostFtdcRemoveParkedOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_REMOVE_PARKED_ORDER_ACTION, 0);
};
void Trader::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast) {
  TD_DEBUG_LOG("OnRspExecOrderInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputExecOrder) {
    CThostFtdcInputExecOrderField *_info = new CThostFtdcInputExecOrderField();
    memcpy(_info, pInputExecOrder, sizeof(CThostFtdcInputExecOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_EXEC_ORDER_INSERT, 0);
};
void Trader::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo,
                                  int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspExecOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputExecOrderAction) {
    CThostFtdcInputExecOrderActionField *_info = new CThostFtdcInputExecOrderActionField();
    memcpy(_info, pInputExecOrderAction, sizeof(CThostFtdcInputExecOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_EXEC_ORDER_ACTION, 0);
};
void Trader::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                 bool bIsLast) {
  TD_DEBUG_LOG("OnRspForQuoteInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputForQuote) {
    CThostFtdcInputForQuoteField *_info = new CThostFtdcInputForQuoteField();
    memcpy(_info, pInputForQuote, sizeof(CThostFtdcInputForQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_FOR_QUOTE_INSERT, 0);
};
void Trader::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQuoteInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputQuote) {
    CThostFtdcInputQuoteField *_info = new CThostFtdcInputQuoteField();
    memcpy(_info, pInputQuote, sizeof(CThostFtdcInputQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QUOTE_INSERT, 0);
};
void Trader::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                              bool bIsLast) {
  TD_DEBUG_LOG("OnRspQuoteAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputQuoteAction) {
    CThostFtdcInputQuoteActionField *_info = new CThostFtdcInputQuoteActionField();
    memcpy(_info, pInputQuoteAction, sizeof(CThostFtdcInputQuoteActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QUOTE_ACTION, 0);
};
void Trader::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo,
                                   int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspBatchOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputBatchOrderAction) {
    CThostFtdcInputBatchOrderActionField *_info = new CThostFtdcInputBatchOrderActionField();
    memcpy(_info, pInputBatchOrderAction, sizeof(CThostFtdcInputBatchOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_BATCH_ORDER_ACTION, 0);
};
void Trader::OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                   bool bIsLast) {
  TD_DEBUG_LOG("OnRspCombActionInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputCombAction) {
    CThostFtdcInputCombActionField *_info = new CThostFtdcInputCombActionField();
    memcpy(_info, pInputCombAction, sizeof(CThostFtdcInputCombActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_COMB_ACTION_INSERT, 0);
};
void Trader::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryOrder called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pOrder) {
    CThostFtdcOrderField *_info = new CThostFtdcOrderField();
    memcpy(_info, pOrder, sizeof(CThostFtdcOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_ORDER, 0);
};
void Trader::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTrade called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTrade) {
    CThostFtdcTradeField *_info = new CThostFtdcTradeField();
    memcpy(_info, pTrade, sizeof(CThostFtdcTradeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_TRADE, 0);
};
void Trader::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                      bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestorPosition called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInvestorPosition) {
    CThostFtdcInvestorPositionField *_info = new CThostFtdcInvestorPositionField();
    memcpy(_info, pInvestorPosition, sizeof(CThostFtdcInvestorPositionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR_POSITION, 0);
};
void Trader::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTradingAccount called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTradingAccount) {
    CThostFtdcTradingAccountField *_info = new CThostFtdcTradingAccountField();
    memcpy(_info, pTradingAccount, sizeof(CThostFtdcTradingAccountField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_TRADING_ACCOUNT, 0);
};
void Trader::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestor called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInvestor) {
    CThostFtdcInvestorField *_info = new CThostFtdcInvestorField();
    memcpy(_info, pInvestor, sizeof(CThostFtdcInvestorField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR, 0);
};
void Trader::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTradingCode called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTradingCode) {
    CThostFtdcTradingCodeField *_info = new CThostFtdcTradingCodeField();
    memcpy(_info, pTradingCode, sizeof(CThostFtdcTradingCodeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_TRADING_CODE, 0);
};
void Trader::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo,
                                          int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInstrumentMarginRate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInstrumentMarginRate) {
    CThostFtdcInstrumentMarginRateField *_info = new CThostFtdcInstrumentMarginRateField();
    memcpy(_info, pInstrumentMarginRate, sizeof(CThostFtdcInstrumentMarginRateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INSTRUMENT_MARGIN_RATE, 0);
};
void Trader::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate,
                                              CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInstrumentCommissionRate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInstrumentCommissionRate) {
    CThostFtdcInstrumentCommissionRateField *_info = new CThostFtdcInstrumentCommissionRateField();
    memcpy(_info, pInstrumentCommissionRate, sizeof(CThostFtdcInstrumentCommissionRateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INSTRUMENT_COMMISSION_RATE, 0);
};
void Trader::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryExchange called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pExchange) {
    CThostFtdcExchangeField *_info = new CThostFtdcExchangeField();
    memcpy(_info, pExchange, sizeof(CThostFtdcExchangeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_EXCHANGE, 0);
};
void Trader::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryProduct called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pProduct) {
    CThostFtdcProductField *_info = new CThostFtdcProductField();
    memcpy(_info, pProduct, sizeof(CThostFtdcProductField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_PRODUCT, 0);
};
void Trader::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInstrument called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInstrument) {
    CThostFtdcInstrumentField *_info = new CThostFtdcInstrumentField();
    memcpy(_info, pInstrument, sizeof(CThostFtdcInstrumentField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INSTRUMENT, 0);
};
void Trader::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                     bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryDepthMarketData called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pDepthMarketData) {
    CThostFtdcDepthMarketDataField *_info = new CThostFtdcDepthMarketDataField();
    memcpy(_info, pDepthMarketData, sizeof(CThostFtdcDepthMarketDataField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_DEPTH_MARKET_DATA, 0);
};
void Trader::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspQrySettlementInfo called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSettlementInfo) {
    CThostFtdcSettlementInfoField *_info = new CThostFtdcSettlementInfoField();
    memcpy(_info, pSettlementInfo, sizeof(CThostFtdcSettlementInfoField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_SETTLEMENT_INFO, 0);
};
void Trader::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTransferBank called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTransferBank) {
    CThostFtdcTransferBankField *_info = new CThostFtdcTransferBankField();
    memcpy(_info, pTransferBank, sizeof(CThostFtdcTransferBankField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_TRANSFER_BANK, 0);
};
void Trader::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail,
                                            CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestorPositionDetail called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInvestorPositionDetail) {
    CThostFtdcInvestorPositionDetailField *_info = new CThostFtdcInvestorPositionDetailField();
    memcpy(_info, pInvestorPositionDetail, sizeof(CThostFtdcInvestorPositionDetailField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR_POSITION_DETAIL, 0);
};
void Trader::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryNotice called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pNotice) {
    CThostFtdcNoticeField *_info = new CThostFtdcNoticeField();
    memcpy(_info, pNotice, sizeof(CThostFtdcNoticeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_NOTICE, 0);
};
void Trader::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo,
                                           int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQrySettlementInfoConfirm called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSettlementInfoConfirm) {
    CThostFtdcSettlementInfoConfirmField *_info = new CThostFtdcSettlementInfoConfirmField();
    memcpy(_info, pSettlementInfoConfirm, sizeof(CThostFtdcSettlementInfoConfirmField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM, 0);
};
void Trader::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail,
                                                   CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestorPositionCombineDetail called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInvestorPositionCombineDetail) {
    CThostFtdcInvestorPositionCombineDetailField *_info = new CThostFtdcInvestorPositionCombineDetailField();
    memcpy(_info, pInvestorPositionCombineDetail, sizeof(CThostFtdcInvestorPositionCombineDetailField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR_POSITION_COMBINE_DETAIL, 0);
};
void Trader::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey,
                                            CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryCFMMCTradingAccountKey called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pCFMMCTradingAccountKey) {
    CThostFtdcCFMMCTradingAccountKeyField *_info = new CThostFtdcCFMMCTradingAccountKeyField();
    memcpy(_info, pCFMMCTradingAccountKey, sizeof(CThostFtdcCFMMCTradingAccountKeyField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_CFMMC_TRADING_ACCOUNT_KEY, 0);
};
void Trader::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryEWarrantOffset called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pEWarrantOffset) {
    CThostFtdcEWarrantOffsetField *_info = new CThostFtdcEWarrantOffsetField();
    memcpy(_info, pEWarrantOffset, sizeof(CThostFtdcEWarrantOffsetField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_E_WARRANT_OFFSET, 0);
};
void Trader::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin,
                                                CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestorProductGroupMargin called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInvestorProductGroupMargin) {
    CThostFtdcInvestorProductGroupMarginField *_info = new CThostFtdcInvestorProductGroupMarginField();
    memcpy(_info, pInvestorProductGroupMargin, sizeof(CThostFtdcInvestorProductGroupMarginField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR_PRODUCT_GROUP_MARGIN, 0);
};
void Trader::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo,
                                        int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryExchangeMarginRate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pExchangeMarginRate) {
    CThostFtdcExchangeMarginRateField *_info = new CThostFtdcExchangeMarginRateField();
    memcpy(_info, pExchangeMarginRate, sizeof(CThostFtdcExchangeMarginRateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_EXCHANGE_MARGIN_RATE, 0);
};
void Trader::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust,
                                              CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryExchangeMarginRateAdjust called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pExchangeMarginRateAdjust) {
    CThostFtdcExchangeMarginRateAdjustField *_info = new CThostFtdcExchangeMarginRateAdjustField();
    memcpy(_info, pExchangeMarginRateAdjust, sizeof(CThostFtdcExchangeMarginRateAdjustField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_EXCHANGE_MARGIN_RATE_ADJUST, 0);
};
void Trader::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryExchangeRate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pExchangeRate) {
    CThostFtdcExchangeRateField *_info = new CThostFtdcExchangeRateField();
    memcpy(_info, pExchangeRate, sizeof(CThostFtdcExchangeRateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_EXCHANGE_RATE, 0);
};
void Trader::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                     bool bIsLast) {
  TD_DEBUG_LOG("OnRspQrySecAgentACIDMap called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSecAgentACIDMap) {
    CThostFtdcSecAgentACIDMapField *_info = new CThostFtdcSecAgentACIDMapField();
    memcpy(_info, pSecAgentACIDMap, sizeof(CThostFtdcSecAgentACIDMapField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_SEC_AGENT_ACID_MAP, 0);
};
void Trader::OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                     bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryProductExchRate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pProductExchRate) {
    CThostFtdcProductExchRateField *_info = new CThostFtdcProductExchRateField();
    memcpy(_info, pProductExchRate, sizeof(CThostFtdcProductExchRateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_PRODUCT_EXCH_RATE, 0);
};
void Trader::OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryProductGroup called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pProductGroup) {
    CThostFtdcProductGroupField *_info = new CThostFtdcProductGroupField();
    memcpy(_info, pProductGroup, sizeof(CThostFtdcProductGroupField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_PRODUCT_GROUP, 0);
};
void Trader::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate,
                                                CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryMMInstrumentCommissionRate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pMMInstrumentCommissionRate) {
    CThostFtdcMMInstrumentCommissionRateField *_info = new CThostFtdcMMInstrumentCommissionRateField();
    memcpy(_info, pMMInstrumentCommissionRate, sizeof(CThostFtdcMMInstrumentCommissionRateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_MM_INSTRUMENT_COMMISSION_RATE, 0);
};
void Trader::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo,
                                           int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryMMOptionInstrCommRate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pMMOptionInstrCommRate) {
    CThostFtdcMMOptionInstrCommRateField *_info = new CThostFtdcMMOptionInstrCommRateField();
    memcpy(_info, pMMOptionInstrCommRate, sizeof(CThostFtdcMMOptionInstrCommRateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_MM_OPTION_INSTR_COMM_RATE, 0);
};
void Trader::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate,
                                             CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInstrumentOrderCommRate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInstrumentOrderCommRate) {
    CThostFtdcInstrumentOrderCommRateField *_info = new CThostFtdcInstrumentOrderCommRateField();
    memcpy(_info, pInstrumentOrderCommRate, sizeof(CThostFtdcInstrumentOrderCommRateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INSTRUMENT_ORDER_COMM_RATE, 0);
};
void Trader::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo,
                                          int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryOptionInstrTradeCost called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pOptionInstrTradeCost) {
    CThostFtdcOptionInstrTradeCostField *_info = new CThostFtdcOptionInstrTradeCostField();
    memcpy(_info, pOptionInstrTradeCost, sizeof(CThostFtdcOptionInstrTradeCostField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_OPTION_INSTR_TRADE_COST, 0);
};
void Trader::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo,
                                         int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryOptionInstrCommRate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pOptionInstrCommRate) {
    CThostFtdcOptionInstrCommRateField *_info = new CThostFtdcOptionInstrCommRateField();
    memcpy(_info, pOptionInstrCommRate, sizeof(CThostFtdcOptionInstrCommRateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_OPTION_INSTR_COMM_RATE, 0);
};
void Trader::OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryExecOrder called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pExecOrder) {
    CThostFtdcExecOrderField *_info = new CThostFtdcExecOrderField();
    memcpy(_info, pExecOrder, sizeof(CThostFtdcExecOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_EXEC_ORDER, 0);
};
void Trader::OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryForQuote called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pForQuote) {
    CThostFtdcForQuoteField *_info = new CThostFtdcForQuoteField();
    memcpy(_info, pForQuote, sizeof(CThostFtdcForQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_FOR_QUOTE, 0);
};
void Trader::OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryQuote called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pQuote) {
    CThostFtdcQuoteField *_info = new CThostFtdcQuoteField();
    memcpy(_info, pQuote, sizeof(CThostFtdcQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_QUOTE, 0);
};
void Trader::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo,
                                         int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryCombInstrumentGuard called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pCombInstrumentGuard) {
    CThostFtdcCombInstrumentGuardField *_info = new CThostFtdcCombInstrumentGuardField();
    memcpy(_info, pCombInstrumentGuard, sizeof(CThostFtdcCombInstrumentGuardField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_COMB_INSTRUMENT_GUARD, 0);
};
void Trader::OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryCombAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pCombAction) {
    CThostFtdcCombActionField *_info = new CThostFtdcCombActionField();
    memcpy(_info, pCombAction, sizeof(CThostFtdcCombActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_COMB_ACTION, 0);
};
void Trader::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTransferSerial called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTransferSerial) {
    CThostFtdcTransferSerialField *_info = new CThostFtdcTransferSerialField();
    memcpy(_info, pTransferSerial, sizeof(CThostFtdcTransferSerialField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_TRANSFER_SERIAL, 0);
};
void Trader::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                     bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryAccountregister called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pAccountregister) {
    CThostFtdcAccountregisterField *_info = new CThostFtdcAccountregisterField();
    memcpy(_info, pAccountregister, sizeof(CThostFtdcAccountregisterField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_ACCOUNTREGISTER, 0);
};
void Trader::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  
  TD_DEBUG_LOG("OnRspError called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
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
  TD_EVENT_CALL(field, ON_RSP_ERROR, 0);
  
};
void Trader::OnRtnOrder(CThostFtdcOrderField *pOrder) {
  
  TD_DEBUG_LOG("OnRtnOrder called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pOrder) {
    CThostFtdcOrderField *_info = new CThostFtdcOrderField();
    memcpy(_info, pOrder, sizeof(CThostFtdcOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_ORDER, 0);
  
};
void Trader::OnRtnTrade(CThostFtdcTradeField *pTrade) {
  
  TD_DEBUG_LOG("OnRtnTrade called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pTrade) {
    CThostFtdcTradeField *_info = new CThostFtdcTradeField();
    memcpy(_info, pTrade, sizeof(CThostFtdcTradeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_TRADE, 0);
  
};
void Trader::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) {
  
  TD_DEBUG_LOG("OnErrRtnOrderInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pInputOrder) {
    CThostFtdcInputOrderField *_info = new CThostFtdcInputOrderField();
    memcpy(_info, pInputOrder, sizeof(CThostFtdcInputOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_ORDER_INSERT, 0);
  
};
void Trader::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) {
  
  TD_DEBUG_LOG("OnErrRtnOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pOrderAction) {
    CThostFtdcOrderActionField *_info = new CThostFtdcOrderActionField();
    memcpy(_info, pOrderAction, sizeof(CThostFtdcOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_ORDER_ACTION, 0);
  
};
void Trader::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus){
    // TD_DEBUG_LOG("OnRtnInstrumentStatus called.");
    // TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
    // uv_work_t *req    = new uv_work_t;
    // field->rspInfo    = nullptr;
    // field->nRequestID = -1;
    // if (pInstrumentStatus) {
    //   CThostFtdcInstrumentStatusField *_info = new CThostFtdcInstrumentStatusField();
    //   memcpy(_info, pInstrumentStatus, sizeof(CThostFtdcInstrumentStatusField));
    //   field->data = _info;
    // } else {
    //   field->data = nullptr;
    // }
    // TD_EVENT_CALL(field, ON_RTN_INSTRUMENT_STATUS, 0);
};
void Trader::OnRtnBulletin(CThostFtdcBulletinField *pBulletin) {
  TD_DEBUG_LOG("OnRtnBulletin called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pBulletin) {
    CThostFtdcBulletinField *_info = new CThostFtdcBulletinField();
    memcpy(_info, pBulletin, sizeof(CThostFtdcBulletinField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_BULLETIN, 0);
};
void Trader::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) {
  TD_DEBUG_LOG("OnRtnTradingNotice called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pTradingNoticeInfo) {
    CThostFtdcTradingNoticeInfoField *_info = new CThostFtdcTradingNoticeInfoField();
    memcpy(_info, pTradingNoticeInfo, sizeof(CThostFtdcTradingNoticeInfoField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_TRADING_NOTICE, 0);
};
void Trader::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) {
  TD_DEBUG_LOG("OnRtnErrorConditionalOrder called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pErrorConditionalOrder) {
    CThostFtdcErrorConditionalOrderField *_info = new CThostFtdcErrorConditionalOrderField();
    memcpy(_info, pErrorConditionalOrder, sizeof(CThostFtdcErrorConditionalOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_ERROR_CONDITIONAL_ORDER, 0);
};
void Trader::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder) {
  TD_DEBUG_LOG("OnRtnExecOrder called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pExecOrder) {
    CThostFtdcExecOrderField *_info = new CThostFtdcExecOrderField();
    memcpy(_info, pExecOrder, sizeof(CThostFtdcExecOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_EXEC_ORDER, 0);
};
void Trader::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnExecOrderInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pInputExecOrder) {
    CThostFtdcInputExecOrderField *_info = new CThostFtdcInputExecOrderField();
    memcpy(_info, pInputExecOrder, sizeof(CThostFtdcInputExecOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_EXEC_ORDER_INSERT, 0);
};
void Trader::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnExecOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pExecOrderAction) {
    CThostFtdcExecOrderActionField *_info = new CThostFtdcExecOrderActionField();
    memcpy(_info, pExecOrderAction, sizeof(CThostFtdcExecOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_EXEC_ORDER_ACTION, 0);
};
void Trader::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnForQuoteInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pInputForQuote) {
    CThostFtdcInputForQuoteField *_info = new CThostFtdcInputForQuoteField();
    memcpy(_info, pInputForQuote, sizeof(CThostFtdcInputForQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_FOR_QUOTE_INSERT, 0);
};
void Trader::OnRtnQuote(CThostFtdcQuoteField *pQuote) {
  TD_DEBUG_LOG("OnRtnQuote called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pQuote) {
    CThostFtdcQuoteField *_info = new CThostFtdcQuoteField();
    memcpy(_info, pQuote, sizeof(CThostFtdcQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_QUOTE, 0);
};
void Trader::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnQuoteInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pInputQuote) {
    CThostFtdcInputQuoteField *_info = new CThostFtdcInputQuoteField();
    memcpy(_info, pInputQuote, sizeof(CThostFtdcInputQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_QUOTE_INSERT, 0);
};
void Trader::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnQuoteAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pQuoteAction) {
    CThostFtdcQuoteActionField *_info = new CThostFtdcQuoteActionField();
    memcpy(_info, pQuoteAction, sizeof(CThostFtdcQuoteActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_QUOTE_ACTION, 0);
};
void Trader::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) {
  TD_DEBUG_LOG("OnRtnForQuoteRsp called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
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
  TD_EVENT_CALL(field, ON_RTN_FOR_QUOTE_RSP, 0);
};
void Trader::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken) {
  TD_DEBUG_LOG("OnRtnCFMMCTradingAccountToken called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pCFMMCTradingAccountToken) {
    CThostFtdcCFMMCTradingAccountTokenField *_info = new CThostFtdcCFMMCTradingAccountTokenField();
    memcpy(_info, pCFMMCTradingAccountToken, sizeof(CThostFtdcCFMMCTradingAccountTokenField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_CFMMC_TRADING_ACCOUNT_TOKEN, 0);
};
void Trader::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnBatchOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pBatchOrderAction) {
    CThostFtdcBatchOrderActionField *_info = new CThostFtdcBatchOrderActionField();
    memcpy(_info, pBatchOrderAction, sizeof(CThostFtdcBatchOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_BATCH_ORDER_ACTION, 0);
};
void Trader::OnRtnCombAction(CThostFtdcCombActionField *pCombAction) {
  TD_DEBUG_LOG("OnRtnCombAction called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pCombAction) {
    CThostFtdcCombActionField *_info = new CThostFtdcCombActionField();
    memcpy(_info, pCombAction, sizeof(CThostFtdcCombActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_COMB_ACTION, 0);
};
void Trader::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnCombActionInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pInputCombAction) {
    CThostFtdcInputCombActionField *_info = new CThostFtdcInputCombActionField();
    memcpy(_info, pInputCombAction, sizeof(CThostFtdcInputCombActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_COMB_ACTION_INSERT, 0);
};
void Trader::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryContractBank called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pContractBank) {
    CThostFtdcContractBankField *_info = new CThostFtdcContractBankField();
    memcpy(_info, pContractBank, sizeof(CThostFtdcContractBankField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_CONTRACT_BANK, 0);
};
void Trader::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryParkedOrder called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pParkedOrder) {
    CThostFtdcParkedOrderField *_info = new CThostFtdcParkedOrderField();
    memcpy(_info, pParkedOrder, sizeof(CThostFtdcParkedOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_PARKED_ORDER, 0);
};
void Trader::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo,
                                       int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryParkedOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pParkedOrderAction) {
    CThostFtdcParkedOrderActionField *_info = new CThostFtdcParkedOrderActionField();
    memcpy(_info, pParkedOrderAction, sizeof(CThostFtdcParkedOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_PARKED_ORDER_ACTION, 0);
};
void Trader::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                   bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTradingNotice called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTradingNotice) {
    CThostFtdcTradingNoticeField *_info = new CThostFtdcTradingNoticeField();
    memcpy(_info, pTradingNotice, sizeof(CThostFtdcTradingNoticeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_TRADING_NOTICE, 0);
};
void Trader::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo,
                                         int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryBrokerTradingParams called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pBrokerTradingParams) {
    CThostFtdcBrokerTradingParamsField *_info = new CThostFtdcBrokerTradingParamsField();
    memcpy(_info, pBrokerTradingParams, sizeof(CThostFtdcBrokerTradingParamsField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_BROKER_TRADING_PARAMS, 0);
};
void Trader::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo,
                                        int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryBrokerTradingAlgos called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pBrokerTradingAlgos) {
    CThostFtdcBrokerTradingAlgosField *_info = new CThostFtdcBrokerTradingAlgosField();
    memcpy(_info, pBrokerTradingAlgos, sizeof(CThostFtdcBrokerTradingAlgosField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_BROKER_TRADING_ALGOS, 0);
};
void Trader::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken,
                                                CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQueryCFMMCTradingAccountToken called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pQueryCFMMCTradingAccountToken) {
    CThostFtdcQueryCFMMCTradingAccountTokenField *_info = new CThostFtdcQueryCFMMCTradingAccountTokenField();
    memcpy(_info, pQueryCFMMCTradingAccountToken, sizeof(CThostFtdcQueryCFMMCTradingAccountTokenField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QUERY_CFMMC_TRADING_ACCOUNT_TOKEN, 0);
};
void Trader::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) {
  TD_DEBUG_LOG("OnRtnFromBankToFutureByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRspTransfer) {
    CThostFtdcRspTransferField *_info = new CThostFtdcRspTransferField();
    memcpy(_info, pRspTransfer, sizeof(CThostFtdcRspTransferField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK, 0);
};
void Trader::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) {
  TD_DEBUG_LOG("OnRtnFromFutureToBankByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRspTransfer) {
    CThostFtdcRspTransferField *_info = new CThostFtdcRspTransferField();
    memcpy(_info, pRspTransfer, sizeof(CThostFtdcRspTransferField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK, 0);
};
void Trader::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) {
  TD_DEBUG_LOG("OnRtnRepealFromBankToFutureByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRspRepeal) {
    CThostFtdcRspRepealField *_info = new CThostFtdcRspRepealField();
    memcpy(_info, pRspRepeal, sizeof(CThostFtdcRspRepealField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK, 0);
};
void Trader::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) {
  TD_DEBUG_LOG("OnRtnRepealFromFutureToBankByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRspRepeal) {
    CThostFtdcRspRepealField *_info = new CThostFtdcRspRepealField();
    memcpy(_info, pRspRepeal, sizeof(CThostFtdcRspRepealField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK, 0);
};
void Trader::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) {
  TD_DEBUG_LOG("OnRtnFromBankToFutureByFuture called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRspTransfer) {
    CThostFtdcRspTransferField *_info = new CThostFtdcRspTransferField();
    memcpy(_info, pRspTransfer, sizeof(CThostFtdcRspTransferField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE, 0);
};
void Trader::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) {
  TD_DEBUG_LOG("OnRtnFromFutureToBankByFuture called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRspTransfer) {
    CThostFtdcRspTransferField *_info = new CThostFtdcRspTransferField();
    memcpy(_info, pRspTransfer, sizeof(CThostFtdcRspTransferField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_FROM_FUTURE_TO_BANK_BY_FUTURE, 0);
};
void Trader::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
  TD_DEBUG_LOG("OnRtnRepealFromBankToFutureByFutureManual called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRspRepeal) {
    CThostFtdcRspRepealField *_info = new CThostFtdcRspRepealField();
    memcpy(_info, pRspRepeal, sizeof(CThostFtdcRspRepealField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL, 0);
};
void Trader::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
  TD_DEBUG_LOG("OnRtnRepealFromFutureToBankByFutureManual called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRspRepeal) {
    CThostFtdcRspRepealField *_info = new CThostFtdcRspRepealField();
    memcpy(_info, pRspRepeal, sizeof(CThostFtdcRspRepealField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL, 0);
};
void Trader::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) {
  TD_DEBUG_LOG("OnRtnQueryBankBalanceByFuture called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pNotifyQueryAccount) {
    CThostFtdcNotifyQueryAccountField *_info = new CThostFtdcNotifyQueryAccountField();
    memcpy(_info, pNotifyQueryAccount, sizeof(CThostFtdcNotifyQueryAccountField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE, 0);
};
void Trader::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnBankToFutureByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pReqTransfer) {
    CThostFtdcReqTransferField *_info = new CThostFtdcReqTransferField();
    memcpy(_info, pReqTransfer, sizeof(CThostFtdcReqTransferField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_BANK_TO_FUTURE_BY_FUTURE, 0);
};
void Trader::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnFutureToBankByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pReqTransfer) {
    CThostFtdcReqTransferField *_info = new CThostFtdcReqTransferField();
    memcpy(_info, pReqTransfer, sizeof(CThostFtdcReqTransferField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_FUTURE_TO_BANK_BY_FUTURE, 0);
};
void Trader::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnRepealBankToFutureByFutureManual called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pReqRepeal) {
    CThostFtdcReqRepealField *_info = new CThostFtdcReqRepealField();
    memcpy(_info, pReqRepeal, sizeof(CThostFtdcReqRepealField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL, 0);
};
void Trader::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnRepealFutureToBankByFutureManual called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pReqRepeal) {
    CThostFtdcReqRepealField *_info = new CThostFtdcReqRepealField();
    memcpy(_info, pReqRepeal, sizeof(CThostFtdcReqRepealField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL, 0);
};
void Trader::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnQueryBankBalanceByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pReqQueryAccount) {
    CThostFtdcReqQueryAccountField *_info = new CThostFtdcReqQueryAccountField();
    memcpy(_info, pReqQueryAccount, sizeof(CThostFtdcReqQueryAccountField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE, 0);
};
void Trader::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) {
  TD_DEBUG_LOG("OnRtnRepealFromBankToFutureByFuture called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRspRepeal) {
    CThostFtdcRspRepealField *_info = new CThostFtdcRspRepealField();
    memcpy(_info, pRspRepeal, sizeof(CThostFtdcRspRepealField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE, 0);
};
void Trader::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) {
  TD_DEBUG_LOG("OnRtnRepealFromFutureToBankByFuture called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRspRepeal) {
    CThostFtdcRspRepealField *_info = new CThostFtdcRspRepealField();
    memcpy(_info, pRspRepeal, sizeof(CThostFtdcRspRepealField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE, 0);
};
void Trader::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                           bool bIsLast) {
  TD_DEBUG_LOG("OnRspFromBankToFutureByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pReqTransfer) {
    CThostFtdcReqTransferField *_info = new CThostFtdcReqTransferField();
    memcpy(_info, pReqTransfer, sizeof(CThostFtdcReqTransferField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE, 0);
};
void Trader::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                           bool bIsLast) {
  TD_DEBUG_LOG("OnRspFromFutureToBankByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pReqTransfer) {
    CThostFtdcReqTransferField *_info = new CThostFtdcReqTransferField();
    memcpy(_info, pReqTransfer, sizeof(CThostFtdcReqTransferField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE, 0);
};
void Trader::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo,
                                                int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQueryBankAccountMoneyByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pReqQueryAccount) {
    CThostFtdcReqQueryAccountField *_info = new CThostFtdcReqQueryAccountField();
    memcpy(_info, pReqQueryAccount, sizeof(CThostFtdcReqQueryAccountField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE, 0);
};
void Trader::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) {
  TD_DEBUG_LOG("OnRtnOpenAccountByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pOpenAccount) {
    CThostFtdcOpenAccountField *_info = new CThostFtdcOpenAccountField();
    memcpy(_info, pOpenAccount, sizeof(CThostFtdcOpenAccountField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_OPEN_ACCOUNT_BY_BANK, 0);
};
void Trader::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount) {
  TD_DEBUG_LOG("OnRtnCancelAccountByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pCancelAccount) {
    CThostFtdcCancelAccountField *_info = new CThostFtdcCancelAccountField();
    memcpy(_info, pCancelAccount, sizeof(CThostFtdcCancelAccountField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_CANCEL_ACCOUNT_BY_BANK, 0);
};
void Trader::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount) {
  TD_DEBUG_LOG("OnRtnChangeAccountByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pChangeAccount) {
    CThostFtdcChangeAccountField *_info = new CThostFtdcChangeAccountField();
    memcpy(_info, pChangeAccount, sizeof(CThostFtdcChangeAccountField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_CHANGE_ACCOUNT_BY_BANK, 0);
};
