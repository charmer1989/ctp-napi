#include "Trader.h"

void Trader::AsyncFn(uv_work_t *req){};

void Trader::AsyncAfterFn(uv_work_t *req) {
  
  if (Trader::isDebug) {
    std::cout << "[DEBUG in C++]: "
              << "AsyncAfterFn called." << std::endl;
  }
  TdCbField *field = (TdCbField *)req->data;
  int eventId      = field->eventId;
  Napi::Env env    = field->trader->Env();
  Napi::HandleScope scope(env);
  Napi::Object obj = Napi::Object::New(env);

  if (eventId == ON_FRONT_CONNECTED)
  {
    SET_PROPERTY_NUMBER(env, obj, "ErrorCode", 0);
  }
  else if (eventId == ON_FRONT_DISCONNECTED)
  {
    SET_PROPERTY_NUMBER(env, obj, "ErrorCode", field->errCode);
  }
  else if (eventId == ON_HEART_BEAT_WARNING)
  {
    SET_PROPERTY_NUMBER(env, obj, "ErrorCode", field->errCode);
  }
  else if (eventId == ON_RSP_AUTHENTICATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcRspAuthenticateField *info = static_cast<CThostFtdcRspAuthenticateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "UserProductInfo", info->UserProductInfo);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_USER_LOGIN) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcRspUserLoginField *info = static_cast<CThostFtdcRspUserLoginField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_STRING(env, obj, "LoginTime", info->LoginTime);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_BUFFER(env, obj, "SystemName", info->SystemName);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "MaxOrderRef", info->MaxOrderRef);
    SET_PROPERTY_STRING(env, obj, "SHFETime", info->SHFETime);
    SET_PROPERTY_STRING(env, obj, "DCETime", info->DCETime);
    SET_PROPERTY_STRING(env, obj, "CZCETime", info->CZCETime);
    SET_PROPERTY_STRING(env, obj, "FFEXTime", info->FFEXTime);
    SET_PROPERTY_STRING(env, obj, "INETime", info->INETime);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_USER_LOGOUT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcUserLogoutField *info = static_cast<CThostFtdcUserLogoutField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_USER_PASSWORD_UPDATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcUserPasswordUpdateField *info = static_cast<CThostFtdcUserPasswordUpdateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "OldPassword", info->OldPassword);
    SET_PROPERTY_STRING(env, obj, "NewPassword", info->NewPassword);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcTradingAccountPasswordUpdateField *info = static_cast<CThostFtdcTradingAccountPasswordUpdateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "OldPassword", info->OldPassword);
    SET_PROPERTY_STRING(env, obj, "NewPassword", info->NewPassword);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_ORDER_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputOrderField *info = static_cast<CThostFtdcInputOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "OrderPriceType", info->OrderPriceType);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_STRING(env, obj, "CombOffsetFlag", info->CombOffsetFlag);
    SET_PROPERTY_STRING(env, obj, "CombHedgeFlag", info->CombHedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTotalOriginal", info->VolumeTotalOriginal);
    SET_PROPERTY_CHAR(env, obj, "TimeCondition", info->TimeCondition);
    SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
    SET_PROPERTY_CHAR(env, obj, "VolumeCondition", info->VolumeCondition);
    SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
    SET_PROPERTY_CHAR(env, obj, "ContingentCondition", info->ContingentCondition);
    SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
    SET_PROPERTY_CHAR(env, obj, "ForceCloseReason", info->ForceCloseReason);
    SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "UserForceClose", info->UserForceClose);
    SET_PROPERTY_NUMBER(env, obj, "IsSwapOrder", info->IsSwapOrder);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_PARKED_ORDER_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcParkedOrderField *info = static_cast<CThostFtdcParkedOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "OrderPriceType", info->OrderPriceType);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_STRING(env, obj, "CombOffsetFlag", info->CombOffsetFlag);
    SET_PROPERTY_STRING(env, obj, "CombHedgeFlag", info->CombHedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTotalOriginal", info->VolumeTotalOriginal);
    SET_PROPERTY_CHAR(env, obj, "TimeCondition", info->TimeCondition);
    SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
    SET_PROPERTY_CHAR(env, obj, "VolumeCondition", info->VolumeCondition);
    SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
    SET_PROPERTY_CHAR(env, obj, "ContingentCondition", info->ContingentCondition);
    SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
    SET_PROPERTY_CHAR(env, obj, "ForceCloseReason", info->ForceCloseReason);
    SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "UserForceClose", info->UserForceClose);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParkedOrderID", info->ParkedOrderID);
    SET_PROPERTY_CHAR(env, obj, "UserType", info->UserType);
    SET_PROPERTY_CHAR(env, obj, "Status", info->Status);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "IsSwapOrder", info->IsSwapOrder);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_PARKED_ORDER_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcParkedOrderActionField *info = static_cast<CThostFtdcParkedOrderActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "OrderActionRef", info->OrderActionRef);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
    SET_PROPERTY_CHAR(env, obj, "ActionFlag", info->ActionFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeChange", info->VolumeChange);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ParkedOrderActionID", info->ParkedOrderActionID);
    SET_PROPERTY_CHAR(env, obj, "UserType", info->UserType);
    SET_PROPERTY_CHAR(env, obj, "Status", info->Status);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_ORDER_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputOrderActionField *info = static_cast<CThostFtdcInputOrderActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "OrderActionRef", info->OrderActionRef);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
    SET_PROPERTY_CHAR(env, obj, "ActionFlag", info->ActionFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeChange", info->VolumeChange);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QUERY_MAX_ORDER_VOLUME) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcQueryMaxOrderVolumeField *info = static_cast<CThostFtdcQueryMaxOrderVolumeField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_CHAR(env, obj, "OffsetFlag", info->OffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "MaxVolume", info->MaxVolume);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_SETTLEMENT_INFO_CONFIRM) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcSettlementInfoConfirmField *info = static_cast<CThostFtdcSettlementInfoConfirmField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "ConfirmDate", info->ConfirmDate);
    SET_PROPERTY_STRING(env, obj, "ConfirmTime", info->ConfirmTime);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_REMOVE_PARKED_ORDER) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcRemoveParkedOrderField *info = static_cast<CThostFtdcRemoveParkedOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "ParkedOrderID", info->ParkedOrderID);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_REMOVE_PARKED_ORDER_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcRemoveParkedOrderActionField *info = static_cast<CThostFtdcRemoveParkedOrderActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "ParkedOrderActionID", info->ParkedOrderActionID);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_EXEC_ORDER_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputExecOrderField *info = static_cast<CThostFtdcInputExecOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ExecOrderRef", info->ExecOrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "OffsetFlag", info->OffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "ActionType", info->ActionType);
    SET_PROPERTY_CHAR(env, obj, "PosiDirection", info->PosiDirection);
    SET_PROPERTY_CHAR(env, obj, "ReservePositionFlag", info->ReservePositionFlag);
    SET_PROPERTY_CHAR(env, obj, "CloseFlag", info->CloseFlag);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_EXEC_ORDER_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputExecOrderActionField *info = static_cast<CThostFtdcInputExecOrderActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "ExecOrderActionRef", info->ExecOrderActionRef);
    SET_PROPERTY_STRING(env, obj, "ExecOrderRef", info->ExecOrderRef);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ExecOrderSysID", info->ExecOrderSysID);
    SET_PROPERTY_CHAR(env, obj, "ActionFlag", info->ActionFlag);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_FOR_QUOTE_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputForQuoteField *info = static_cast<CThostFtdcInputForQuoteField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ForQuoteRef", info->ForQuoteRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QUOTE_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputQuoteField *info = static_cast<CThostFtdcInputQuoteField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "QuoteRef", info->QuoteRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_NUMBER(env, obj, "AskPrice", info->AskPrice);
    SET_PROPERTY_NUMBER(env, obj, "BidPrice", info->BidPrice);
    SET_PROPERTY_NUMBER(env, obj, "AskVolume", info->AskVolume);
    SET_PROPERTY_NUMBER(env, obj, "BidVolume", info->BidVolume);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "AskOffsetFlag", info->AskOffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "BidOffsetFlag", info->BidOffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "AskHedgeFlag", info->AskHedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "BidHedgeFlag", info->BidHedgeFlag);
    SET_PROPERTY_STRING(env, obj, "AskOrderRef", info->AskOrderRef);
    SET_PROPERTY_STRING(env, obj, "BidOrderRef", info->BidOrderRef);
    SET_PROPERTY_STRING(env, obj, "ForQuoteSysID", info->ForQuoteSysID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QUOTE_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputQuoteActionField *info = static_cast<CThostFtdcInputQuoteActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "QuoteActionRef", info->QuoteActionRef);
    SET_PROPERTY_STRING(env, obj, "QuoteRef", info->QuoteRef);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "QuoteSysID", info->QuoteSysID);
    SET_PROPERTY_CHAR(env, obj, "ActionFlag", info->ActionFlag);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_BATCH_ORDER_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputBatchOrderActionField *info = static_cast<CThostFtdcInputBatchOrderActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "OrderActionRef", info->OrderActionRef);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_COMB_ACTION_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputCombActionField *info = static_cast<CThostFtdcInputCombActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "CombActionRef", info->CombActionRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_CHAR(env, obj, "CombDirection", info->CombDirection);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_ORDER) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcOrderField *info = static_cast<CThostFtdcOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "OrderPriceType", info->OrderPriceType);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_STRING(env, obj, "CombOffsetFlag", info->CombOffsetFlag);
    SET_PROPERTY_STRING(env, obj, "CombHedgeFlag", info->CombHedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTotalOriginal", info->VolumeTotalOriginal);
    SET_PROPERTY_CHAR(env, obj, "TimeCondition", info->TimeCondition);
    SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
    SET_PROPERTY_CHAR(env, obj, "VolumeCondition", info->VolumeCondition);
    SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
    SET_PROPERTY_CHAR(env, obj, "ContingentCondition", info->ContingentCondition);
    SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
    SET_PROPERTY_CHAR(env, obj, "ForceCloseReason", info->ForceCloseReason);
    SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "OrderLocalID", info->OrderLocalID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_CHAR(env, obj, "OrderSubmitStatus", info->OrderSubmitStatus);
    SET_PROPERTY_NUMBER(env, obj, "NotifySequence", info->NotifySequence);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
    SET_PROPERTY_CHAR(env, obj, "OrderSource", info->OrderSource);
    SET_PROPERTY_CHAR(env, obj, "OrderStatus", info->OrderStatus);
    SET_PROPERTY_CHAR(env, obj, "OrderType", info->OrderType);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTraded", info->VolumeTraded);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTotal", info->VolumeTotal);
    SET_PROPERTY_STRING(env, obj, "InsertDate", info->InsertDate);
    SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
    SET_PROPERTY_STRING(env, obj, "ActiveTime", info->ActiveTime);
    SET_PROPERTY_STRING(env, obj, "SuspendTime", info->SuspendTime);
    SET_PROPERTY_STRING(env, obj, "UpdateTime", info->UpdateTime);
    SET_PROPERTY_STRING(env, obj, "CancelTime", info->CancelTime);
    SET_PROPERTY_STRING(env, obj, "ActiveTraderID", info->ActiveTraderID);
    SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "UserProductInfo", info->UserProductInfo);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_NUMBER(env, obj, "UserForceClose", info->UserForceClose);
    SET_PROPERTY_STRING(env, obj, "ActiveUserID", info->ActiveUserID);
    SET_PROPERTY_NUMBER(env, obj, "BrokerOrderSeq", info->BrokerOrderSeq);
    SET_PROPERTY_STRING(env, obj, "RelativeOrderSysID", info->RelativeOrderSysID);
    SET_PROPERTY_NUMBER(env, obj, "ZCETotalTradedVolume", info->ZCETotalTradedVolume);
    SET_PROPERTY_NUMBER(env, obj, "IsSwapOrder", info->IsSwapOrder);
    SET_PROPERTY_STRING(env, obj, "BranchID", info->BranchID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_TRADE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcTradeField *info = static_cast<CThostFtdcTradeField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "TradeID", info->TradeID);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_CHAR(env, obj, "TradingRole", info->TradingRole);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_CHAR(env, obj, "OffsetFlag", info->OffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "Price", info->Price);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_CHAR(env, obj, "TradeType", info->TradeType);
    SET_PROPERTY_CHAR(env, obj, "PriceSource", info->PriceSource);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_STRING(env, obj, "OrderLocalID", info->OrderLocalID);
    SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_NUMBER(env, obj, "BrokerOrderSeq", info->BrokerOrderSeq);
    SET_PROPERTY_CHAR(env, obj, "TradeSource", info->TradeSource);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_INVESTOR_POSITION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInvestorPositionField *info = static_cast<CThostFtdcInvestorPositionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_CHAR(env, obj, "PosiDirection", info->PosiDirection);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "PositionDate", info->PositionDate);
    SET_PROPERTY_NUMBER(env, obj, "YdPosition", info->YdPosition);
    SET_PROPERTY_NUMBER(env, obj, "Position", info->Position);
    SET_PROPERTY_NUMBER(env, obj, "LongFrozen", info->LongFrozen);
    SET_PROPERTY_NUMBER(env, obj, "ShortFrozen", info->ShortFrozen);
    SET_PROPERTY_NUMBER(env, obj, "LongFrozenAmount", info->LongFrozenAmount);
    SET_PROPERTY_NUMBER(env, obj, "ShortFrozenAmount", info->ShortFrozenAmount);
    SET_PROPERTY_NUMBER(env, obj, "OpenVolume", info->OpenVolume);
    SET_PROPERTY_NUMBER(env, obj, "CloseVolume", info->CloseVolume);
    SET_PROPERTY_NUMBER(env, obj, "OpenAmount", info->OpenAmount);
    SET_PROPERTY_NUMBER(env, obj, "CloseAmount", info->CloseAmount);
    SET_PROPERTY_NUMBER(env, obj, "PositionCost", info->PositionCost);
    SET_PROPERTY_NUMBER(env, obj, "PreMargin", info->PreMargin);
    SET_PROPERTY_NUMBER(env, obj, "UseMargin", info->UseMargin);
    SET_PROPERTY_NUMBER(env, obj, "FrozenMargin", info->FrozenMargin);
    SET_PROPERTY_NUMBER(env, obj, "FrozenCash", info->FrozenCash);
    SET_PROPERTY_NUMBER(env, obj, "FrozenCommission", info->FrozenCommission);
    SET_PROPERTY_NUMBER(env, obj, "CashIn", info->CashIn);
    SET_PROPERTY_NUMBER(env, obj, "Commission", info->Commission);
    SET_PROPERTY_NUMBER(env, obj, "CloseProfit", info->CloseProfit);
    SET_PROPERTY_NUMBER(env, obj, "PositionProfit", info->PositionProfit);
    SET_PROPERTY_NUMBER(env, obj, "PreSettlementPrice", info->PreSettlementPrice);
    SET_PROPERTY_NUMBER(env, obj, "SettlementPrice", info->SettlementPrice);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_NUMBER(env, obj, "OpenCost", info->OpenCost);
    SET_PROPERTY_NUMBER(env, obj, "ExchangeMargin", info->ExchangeMargin);
    SET_PROPERTY_NUMBER(env, obj, "CombPosition", info->CombPosition);
    SET_PROPERTY_NUMBER(env, obj, "CombLongFrozen", info->CombLongFrozen);
    SET_PROPERTY_NUMBER(env, obj, "CombShortFrozen", info->CombShortFrozen);
    SET_PROPERTY_NUMBER(env, obj, "CloseProfitByDate", info->CloseProfitByDate);
    SET_PROPERTY_NUMBER(env, obj, "CloseProfitByTrade", info->CloseProfitByTrade);
    SET_PROPERTY_NUMBER(env, obj, "TodayPosition", info->TodayPosition);
    SET_PROPERTY_NUMBER(env, obj, "MarginRateByMoney", info->MarginRateByMoney);
    SET_PROPERTY_NUMBER(env, obj, "MarginRateByVolume", info->MarginRateByVolume);
    SET_PROPERTY_NUMBER(env, obj, "StrikeFrozen", info->StrikeFrozen);
    SET_PROPERTY_NUMBER(env, obj, "StrikeFrozenAmount", info->StrikeFrozenAmount);
    SET_PROPERTY_NUMBER(env, obj, "AbandonFrozen", info->AbandonFrozen);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_TRADING_ACCOUNT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcTradingAccountField *info = static_cast<CThostFtdcTradingAccountField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_NUMBER(env, obj, "PreMortgage", info->PreMortgage);
    SET_PROPERTY_NUMBER(env, obj, "PreCredit", info->PreCredit);
    SET_PROPERTY_NUMBER(env, obj, "PreDeposit", info->PreDeposit);
    SET_PROPERTY_NUMBER(env, obj, "PreBalance", info->PreBalance);
    SET_PROPERTY_NUMBER(env, obj, "PreMargin", info->PreMargin);
    SET_PROPERTY_NUMBER(env, obj, "InterestBase", info->InterestBase);
    SET_PROPERTY_NUMBER(env, obj, "Interest", info->Interest);
    SET_PROPERTY_NUMBER(env, obj, "Deposit", info->Deposit);
    SET_PROPERTY_NUMBER(env, obj, "Withdraw", info->Withdraw);
    SET_PROPERTY_NUMBER(env, obj, "FrozenMargin", info->FrozenMargin);
    SET_PROPERTY_NUMBER(env, obj, "FrozenCash", info->FrozenCash);
    SET_PROPERTY_NUMBER(env, obj, "FrozenCommission", info->FrozenCommission);
    SET_PROPERTY_NUMBER(env, obj, "CurrMargin", info->CurrMargin);
    SET_PROPERTY_NUMBER(env, obj, "CashIn", info->CashIn);
    SET_PROPERTY_NUMBER(env, obj, "Commission", info->Commission);
    SET_PROPERTY_NUMBER(env, obj, "CloseProfit", info->CloseProfit);
    SET_PROPERTY_NUMBER(env, obj, "PositionProfit", info->PositionProfit);
    SET_PROPERTY_NUMBER(env, obj, "Balance", info->Balance);
    SET_PROPERTY_NUMBER(env, obj, "Available", info->Available);
    SET_PROPERTY_NUMBER(env, obj, "WithdrawQuota", info->WithdrawQuota);
    SET_PROPERTY_NUMBER(env, obj, "Reserve", info->Reserve);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_NUMBER(env, obj, "Credit", info->Credit);
    SET_PROPERTY_NUMBER(env, obj, "Mortgage", info->Mortgage);
    SET_PROPERTY_NUMBER(env, obj, "ExchangeMargin", info->ExchangeMargin);
    SET_PROPERTY_NUMBER(env, obj, "DeliveryMargin", info->DeliveryMargin);
    SET_PROPERTY_NUMBER(env, obj, "ExchangeDeliveryMargin", info->ExchangeDeliveryMargin);
    SET_PROPERTY_NUMBER(env, obj, "ReserveBalance", info->ReserveBalance);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "PreFundMortgageIn", info->PreFundMortgageIn);
    SET_PROPERTY_NUMBER(env, obj, "PreFundMortgageOut", info->PreFundMortgageOut);
    SET_PROPERTY_NUMBER(env, obj, "FundMortgageIn", info->FundMortgageIn);
    SET_PROPERTY_NUMBER(env, obj, "FundMortgageOut", info->FundMortgageOut);
    SET_PROPERTY_NUMBER(env, obj, "FundMortgageAvailable", info->FundMortgageAvailable);
    SET_PROPERTY_NUMBER(env, obj, "MortgageableFund", info->MortgageableFund);
    SET_PROPERTY_NUMBER(env, obj, "SpecProductMargin", info->SpecProductMargin);
    SET_PROPERTY_NUMBER(env, obj, "SpecProductFrozenMargin", info->SpecProductFrozenMargin);
    SET_PROPERTY_NUMBER(env, obj, "SpecProductCommission", info->SpecProductCommission);
    SET_PROPERTY_NUMBER(env, obj, "SpecProductFrozenCommission", info->SpecProductFrozenCommission);
    SET_PROPERTY_NUMBER(env, obj, "SpecProductPositionProfit", info->SpecProductPositionProfit);
    SET_PROPERTY_NUMBER(env, obj, "SpecProductCloseProfit", info->SpecProductCloseProfit);
    SET_PROPERTY_NUMBER(env, obj, "SpecProductPositionProfitByAlg", info->SpecProductPositionProfitByAlg);
    SET_PROPERTY_NUMBER(env, obj, "SpecProductExchangeMargin", info->SpecProductExchangeMargin);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_INVESTOR) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInvestorField *info = static_cast<CThostFtdcInvestorField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorGroupID", info->InvestorGroupID);
    SET_PROPERTY_BUFFER(env, obj, "InvestorName", info->InvestorName);
    SET_PROPERTY_CHAR(env, obj, "IdentifiedCardType", info->IdentifiedCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_NUMBER(env, obj, "IsActive", info->IsActive);
    SET_PROPERTY_STRING(env, obj, "Telephone", info->Telephone);
    SET_PROPERTY_STRING(env, obj, "Address", info->Address);
    SET_PROPERTY_STRING(env, obj, "OpenDate", info->OpenDate);
    SET_PROPERTY_STRING(env, obj, "Mobile", info->Mobile);
    SET_PROPERTY_STRING(env, obj, "CommModelID", info->CommModelID);
    SET_PROPERTY_STRING(env, obj, "MarginModelID", info->MarginModelID);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_TRADING_CODE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcTradingCodeField *info = static_cast<CThostFtdcTradingCodeField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_NUMBER(env, obj, "IsActive", info->IsActive);
    SET_PROPERTY_CHAR(env, obj, "ClientIDType", info->ClientIDType);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_INSTRUMENT_MARGIN_RATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInstrumentMarginRateField *info = static_cast<CThostFtdcInstrumentMarginRateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "InvestorRange", info->InvestorRange);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "LongMarginRatioByMoney", info->LongMarginRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "LongMarginRatioByVolume", info->LongMarginRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "ShortMarginRatioByMoney", info->ShortMarginRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "ShortMarginRatioByVolume", info->ShortMarginRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "IsRelative", info->IsRelative);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_INSTRUMENT_COMMISSION_RATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInstrumentCommissionRateField *info = static_cast<CThostFtdcInstrumentCommissionRateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "InvestorRange", info->InvestorRange);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "OpenRatioByMoney", info->OpenRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "OpenRatioByVolume", info->OpenRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "CloseRatioByMoney", info->CloseRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "CloseRatioByVolume", info->CloseRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "CloseTodayRatioByMoney", info->CloseTodayRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "CloseTodayRatioByVolume", info->CloseTodayRatioByVolume);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_EXCHANGE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcExchangeField *info = static_cast<CThostFtdcExchangeField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_BUFFER(env, obj, "ExchangeName", info->ExchangeName);
    SET_PROPERTY_CHAR(env, obj, "ExchangeProperty", info->ExchangeProperty);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_PRODUCT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcProductField *info = static_cast<CThostFtdcProductField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "ProductID", info->ProductID);
    SET_PROPERTY_BUFFER(env, obj, "ProductName", info->ProductName);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_CHAR(env, obj, "ProductClass", info->ProductClass);
    SET_PROPERTY_NUMBER(env, obj, "VolumeMultiple", info->VolumeMultiple);
    SET_PROPERTY_NUMBER(env, obj, "PriceTick", info->PriceTick);
    SET_PROPERTY_NUMBER(env, obj, "MaxMarketOrderVolume", info->MaxMarketOrderVolume);
    SET_PROPERTY_NUMBER(env, obj, "MinMarketOrderVolume", info->MinMarketOrderVolume);
    SET_PROPERTY_NUMBER(env, obj, "MaxLimitOrderVolume", info->MaxLimitOrderVolume);
    SET_PROPERTY_NUMBER(env, obj, "MinLimitOrderVolume", info->MinLimitOrderVolume);
    SET_PROPERTY_CHAR(env, obj, "PositionType", info->PositionType);
    SET_PROPERTY_CHAR(env, obj, "PositionDateType", info->PositionDateType);
    SET_PROPERTY_CHAR(env, obj, "CloseDealType", info->CloseDealType);
    SET_PROPERTY_STRING(env, obj, "TradeCurrencyID", info->TradeCurrencyID);
    SET_PROPERTY_CHAR(env, obj, "MortgageFundUseRange", info->MortgageFundUseRange);
    SET_PROPERTY_STRING(env, obj, "ExchangeProductID", info->ExchangeProductID);
    SET_PROPERTY_NUMBER(env, obj, "UnderlyingMultiple", info->UnderlyingMultiple);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_INSTRUMENT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInstrumentField *info = static_cast<CThostFtdcInstrumentField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_BUFFER(env, obj, "InstrumentName", info->InstrumentName);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "ProductID", info->ProductID);
    SET_PROPERTY_CHAR(env, obj, "ProductClass", info->ProductClass);
    SET_PROPERTY_NUMBER(env, obj, "DeliveryYear", info->DeliveryYear);
    SET_PROPERTY_NUMBER(env, obj, "DeliveryMonth", info->DeliveryMonth);
    SET_PROPERTY_NUMBER(env, obj, "MaxMarketOrderVolume", info->MaxMarketOrderVolume);
    SET_PROPERTY_NUMBER(env, obj, "MinMarketOrderVolume", info->MinMarketOrderVolume);
    SET_PROPERTY_NUMBER(env, obj, "MaxLimitOrderVolume", info->MaxLimitOrderVolume);
    SET_PROPERTY_NUMBER(env, obj, "MinLimitOrderVolume", info->MinLimitOrderVolume);
    SET_PROPERTY_NUMBER(env, obj, "VolumeMultiple", info->VolumeMultiple);
    SET_PROPERTY_NUMBER(env, obj, "PriceTick", info->PriceTick);
    SET_PROPERTY_STRING(env, obj, "CreateDate", info->CreateDate);
    SET_PROPERTY_STRING(env, obj, "OpenDate", info->OpenDate);
    SET_PROPERTY_STRING(env, obj, "ExpireDate", info->ExpireDate);
    SET_PROPERTY_STRING(env, obj, "StartDelivDate", info->StartDelivDate);
    SET_PROPERTY_STRING(env, obj, "EndDelivDate", info->EndDelivDate);
    SET_PROPERTY_CHAR(env, obj, "InstLifePhase", info->InstLifePhase);
    SET_PROPERTY_NUMBER(env, obj, "IsTrading", info->IsTrading);
    SET_PROPERTY_CHAR(env, obj, "PositionType", info->PositionType);
    SET_PROPERTY_CHAR(env, obj, "PositionDateType", info->PositionDateType);
    SET_PROPERTY_NUMBER(env, obj, "LongMarginRatio", info->LongMarginRatio);
    SET_PROPERTY_NUMBER(env, obj, "ShortMarginRatio", info->ShortMarginRatio);
    SET_PROPERTY_CHAR(env, obj, "MaxMarginSideAlgorithm", info->MaxMarginSideAlgorithm);
    SET_PROPERTY_STRING(env, obj, "UnderlyingInstrID", info->UnderlyingInstrID);
    SET_PROPERTY_NUMBER(env, obj, "StrikePrice", info->StrikePrice);
    SET_PROPERTY_CHAR(env, obj, "OptionsType", info->OptionsType);
    SET_PROPERTY_NUMBER(env, obj, "UnderlyingMultiple", info->UnderlyingMultiple);
    SET_PROPERTY_CHAR(env, obj, "CombinationType", info->CombinationType);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_DEPTH_MARKET_DATA) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcDepthMarketDataField *info = static_cast<CThostFtdcDepthMarketDataField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_NUMBER(env, obj, "LastPrice", info->LastPrice);
    SET_PROPERTY_NUMBER(env, obj, "PreSettlementPrice", info->PreSettlementPrice);
    SET_PROPERTY_NUMBER(env, obj, "PreClosePrice", info->PreClosePrice);
    SET_PROPERTY_NUMBER(env, obj, "PreOpenInterest", info->PreOpenInterest);
    SET_PROPERTY_NUMBER(env, obj, "OpenPrice", info->OpenPrice);
    SET_PROPERTY_NUMBER(env, obj, "HighestPrice", info->HighestPrice);
    SET_PROPERTY_NUMBER(env, obj, "LowestPrice", info->LowestPrice);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_NUMBER(env, obj, "Turnover", info->Turnover);
    SET_PROPERTY_NUMBER(env, obj, "OpenInterest", info->OpenInterest);
    SET_PROPERTY_NUMBER(env, obj, "ClosePrice", info->ClosePrice);
    SET_PROPERTY_NUMBER(env, obj, "SettlementPrice", info->SettlementPrice);
    SET_PROPERTY_NUMBER(env, obj, "UpperLimitPrice", info->UpperLimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "LowerLimitPrice", info->LowerLimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "PreDelta", info->PreDelta);
    SET_PROPERTY_NUMBER(env, obj, "CurrDelta", info->CurrDelta);
    SET_PROPERTY_STRING(env, obj, "UpdateTime", info->UpdateTime);
    SET_PROPERTY_NUMBER(env, obj, "UpdateMillisec", info->UpdateMillisec);
    SET_PROPERTY_NUMBER(env, obj, "BidPrice1", info->BidPrice1);
    SET_PROPERTY_NUMBER(env, obj, "BidVolume1", info->BidVolume1);
    SET_PROPERTY_NUMBER(env, obj, "AskPrice1", info->AskPrice1);
    SET_PROPERTY_NUMBER(env, obj, "AskVolume1", info->AskVolume1);
    SET_PROPERTY_NUMBER(env, obj, "BidPrice2", info->BidPrice2);
    SET_PROPERTY_NUMBER(env, obj, "BidVolume2", info->BidVolume2);
    SET_PROPERTY_NUMBER(env, obj, "AskPrice2", info->AskPrice2);
    SET_PROPERTY_NUMBER(env, obj, "AskVolume2", info->AskVolume2);
    SET_PROPERTY_NUMBER(env, obj, "BidPrice3", info->BidPrice3);
    SET_PROPERTY_NUMBER(env, obj, "BidVolume3", info->BidVolume3);
    SET_PROPERTY_NUMBER(env, obj, "AskPrice3", info->AskPrice3);
    SET_PROPERTY_NUMBER(env, obj, "AskVolume3", info->AskVolume3);
    SET_PROPERTY_NUMBER(env, obj, "BidPrice4", info->BidPrice4);
    SET_PROPERTY_NUMBER(env, obj, "BidVolume4", info->BidVolume4);
    SET_PROPERTY_NUMBER(env, obj, "AskPrice4", info->AskPrice4);
    SET_PROPERTY_NUMBER(env, obj, "AskVolume4", info->AskVolume4);
    SET_PROPERTY_NUMBER(env, obj, "BidPrice5", info->BidPrice5);
    SET_PROPERTY_NUMBER(env, obj, "BidVolume5", info->BidVolume5);
    SET_PROPERTY_NUMBER(env, obj, "AskPrice5", info->AskPrice5);
    SET_PROPERTY_NUMBER(env, obj, "AskVolume5", info->AskVolume5);
    SET_PROPERTY_NUMBER(env, obj, "AveragePrice", info->AveragePrice);
    SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_SETTLEMENT_INFO) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcSettlementInfoField *info = static_cast<CThostFtdcSettlementInfoField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_STRING(env, obj, "Content", info->Content);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_TRANSFER_BANK) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcTransferBankField *info = static_cast<CThostFtdcTransferBankField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
    SET_PROPERTY_BUFFER(env, obj, "BankName", info->BankName);
    SET_PROPERTY_NUMBER(env, obj, "IsActive", info->IsActive);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_INVESTOR_POSITION_DETAIL) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInvestorPositionDetailField *info = static_cast<CThostFtdcInvestorPositionDetailField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_STRING(env, obj, "OpenDate", info->OpenDate);
    SET_PROPERTY_STRING(env, obj, "TradeID", info->TradeID);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_NUMBER(env, obj, "OpenPrice", info->OpenPrice);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_CHAR(env, obj, "TradeType", info->TradeType);
    SET_PROPERTY_STRING(env, obj, "CombInstrumentID", info->CombInstrumentID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_NUMBER(env, obj, "CloseProfitByDate", info->CloseProfitByDate);
    SET_PROPERTY_NUMBER(env, obj, "CloseProfitByTrade", info->CloseProfitByTrade);
    SET_PROPERTY_NUMBER(env, obj, "PositionProfitByDate", info->PositionProfitByDate);
    SET_PROPERTY_NUMBER(env, obj, "PositionProfitByTrade", info->PositionProfitByTrade);
    SET_PROPERTY_NUMBER(env, obj, "Margin", info->Margin);
    SET_PROPERTY_NUMBER(env, obj, "ExchMargin", info->ExchMargin);
    SET_PROPERTY_NUMBER(env, obj, "MarginRateByMoney", info->MarginRateByMoney);
    SET_PROPERTY_NUMBER(env, obj, "MarginRateByVolume", info->MarginRateByVolume);
    SET_PROPERTY_NUMBER(env, obj, "LastSettlementPrice", info->LastSettlementPrice);
    SET_PROPERTY_NUMBER(env, obj, "SettlementPrice", info->SettlementPrice);
    SET_PROPERTY_NUMBER(env, obj, "CloseVolume", info->CloseVolume);
    SET_PROPERTY_NUMBER(env, obj, "CloseAmount", info->CloseAmount);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_NOTICE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcNoticeField *info = static_cast<CThostFtdcNoticeField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "Content", info->Content);
    SET_PROPERTY_STRING(env, obj, "SequenceLabel", info->SequenceLabel);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcSettlementInfoConfirmField *info = static_cast<CThostFtdcSettlementInfoConfirmField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "ConfirmDate", info->ConfirmDate);
    SET_PROPERTY_STRING(env, obj, "ConfirmTime", info->ConfirmTime);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_INVESTOR_POSITION_COMBINE_DETAIL) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInvestorPositionCombineDetailField *info = static_cast<CThostFtdcInvestorPositionCombineDetailField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_STRING(env, obj, "OpenDate", info->OpenDate);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "ComTradeID", info->ComTradeID);
    SET_PROPERTY_STRING(env, obj, "TradeID", info->TradeID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_NUMBER(env, obj, "TotalAmt", info->TotalAmt);
    SET_PROPERTY_NUMBER(env, obj, "Margin", info->Margin);
    SET_PROPERTY_NUMBER(env, obj, "ExchMargin", info->ExchMargin);
    SET_PROPERTY_NUMBER(env, obj, "MarginRateByMoney", info->MarginRateByMoney);
    SET_PROPERTY_NUMBER(env, obj, "MarginRateByVolume", info->MarginRateByVolume);
    SET_PROPERTY_NUMBER(env, obj, "LegID", info->LegID);
    SET_PROPERTY_NUMBER(env, obj, "LegMultiple", info->LegMultiple);
    SET_PROPERTY_STRING(env, obj, "CombInstrumentID", info->CombInstrumentID);
    SET_PROPERTY_NUMBER(env, obj, "TradeGroupID", info->TradeGroupID);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_CFMMC_TRADING_ACCOUNT_KEY) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcCFMMCTradingAccountKeyField *info = static_cast<CThostFtdcCFMMCTradingAccountKeyField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_NUMBER(env, obj, "KeyID", info->KeyID);
    SET_PROPERTY_STRING(env, obj, "CurrentKey", info->CurrentKey);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_E_WARRANT_OFFSET) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcEWarrantOffsetField *info = static_cast<CThostFtdcEWarrantOffsetField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_INVESTOR_PRODUCT_GROUP_MARGIN) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInvestorProductGroupMarginField *info = static_cast<CThostFtdcInvestorProductGroupMarginField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "ProductGroupID", info->ProductGroupID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_NUMBER(env, obj, "FrozenMargin", info->FrozenMargin);
    SET_PROPERTY_NUMBER(env, obj, "LongFrozenMargin", info->LongFrozenMargin);
    SET_PROPERTY_NUMBER(env, obj, "ShortFrozenMargin", info->ShortFrozenMargin);
    SET_PROPERTY_NUMBER(env, obj, "UseMargin", info->UseMargin);
    SET_PROPERTY_NUMBER(env, obj, "LongUseMargin", info->LongUseMargin);
    SET_PROPERTY_NUMBER(env, obj, "ShortUseMargin", info->ShortUseMargin);
    SET_PROPERTY_NUMBER(env, obj, "ExchMargin", info->ExchMargin);
    SET_PROPERTY_NUMBER(env, obj, "LongExchMargin", info->LongExchMargin);
    SET_PROPERTY_NUMBER(env, obj, "ShortExchMargin", info->ShortExchMargin);
    SET_PROPERTY_NUMBER(env, obj, "CloseProfit", info->CloseProfit);
    SET_PROPERTY_NUMBER(env, obj, "FrozenCommission", info->FrozenCommission);
    SET_PROPERTY_NUMBER(env, obj, "Commission", info->Commission);
    SET_PROPERTY_NUMBER(env, obj, "FrozenCash", info->FrozenCash);
    SET_PROPERTY_NUMBER(env, obj, "CashIn", info->CashIn);
    SET_PROPERTY_NUMBER(env, obj, "PositionProfit", info->PositionProfit);
    SET_PROPERTY_NUMBER(env, obj, "OffsetAmount", info->OffsetAmount);
    SET_PROPERTY_NUMBER(env, obj, "LongOffsetAmount", info->LongOffsetAmount);
    SET_PROPERTY_NUMBER(env, obj, "ShortOffsetAmount", info->ShortOffsetAmount);
    SET_PROPERTY_NUMBER(env, obj, "ExchOffsetAmount", info->ExchOffsetAmount);
    SET_PROPERTY_NUMBER(env, obj, "LongExchOffsetAmount", info->LongExchOffsetAmount);
    SET_PROPERTY_NUMBER(env, obj, "ShortExchOffsetAmount", info->ShortExchOffsetAmount);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_EXCHANGE_MARGIN_RATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcExchangeMarginRateField *info = static_cast<CThostFtdcExchangeMarginRateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "LongMarginRatioByMoney", info->LongMarginRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "LongMarginRatioByVolume", info->LongMarginRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "ShortMarginRatioByMoney", info->ShortMarginRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "ShortMarginRatioByVolume", info->ShortMarginRatioByVolume);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_EXCHANGE_MARGIN_RATE_ADJUST) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcExchangeMarginRateAdjustField *info = static_cast<CThostFtdcExchangeMarginRateAdjustField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "LongMarginRatioByMoney", info->LongMarginRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "LongMarginRatioByVolume", info->LongMarginRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "ShortMarginRatioByMoney", info->ShortMarginRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "ShortMarginRatioByVolume", info->ShortMarginRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "ExchLongMarginRatioByMoney", info->ExchLongMarginRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "ExchLongMarginRatioByVolume", info->ExchLongMarginRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "ExchShortMarginRatioByMoney", info->ExchShortMarginRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "ExchShortMarginRatioByVolume", info->ExchShortMarginRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "NoLongMarginRatioByMoney", info->NoLongMarginRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "NoLongMarginRatioByVolume", info->NoLongMarginRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "NoShortMarginRatioByMoney", info->NoShortMarginRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "NoShortMarginRatioByVolume", info->NoShortMarginRatioByVolume);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_EXCHANGE_RATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcExchangeRateField *info = static_cast<CThostFtdcExchangeRateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "FromCurrencyID", info->FromCurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "FromCurrencyUnit", info->FromCurrencyUnit);
    SET_PROPERTY_STRING(env, obj, "ToCurrencyID", info->ToCurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "ExchangeRate", info->ExchangeRate);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_SEC_AGENT_ACID_MAP) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcSecAgentACIDMapField *info = static_cast<CThostFtdcSecAgentACIDMapField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "BrokerSecAgentID", info->BrokerSecAgentID);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_PRODUCT_EXCH_RATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcProductExchRateField *info = static_cast<CThostFtdcProductExchRateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "ProductID", info->ProductID);
    SET_PROPERTY_STRING(env, obj, "QuoteCurrencyID", info->QuoteCurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "ExchangeRate", info->ExchangeRate);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_PRODUCT_GROUP) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcProductGroupField *info = static_cast<CThostFtdcProductGroupField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "ProductID", info->ProductID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ProductGroupID", info->ProductGroupID);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_MM_INSTRUMENT_COMMISSION_RATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcMMInstrumentCommissionRateField *info = static_cast<CThostFtdcMMInstrumentCommissionRateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "InvestorRange", info->InvestorRange);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "OpenRatioByMoney", info->OpenRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "OpenRatioByVolume", info->OpenRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "CloseRatioByMoney", info->CloseRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "CloseRatioByVolume", info->CloseRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "CloseTodayRatioByMoney", info->CloseTodayRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "CloseTodayRatioByVolume", info->CloseTodayRatioByVolume);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_MM_OPTION_INSTR_COMM_RATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcMMOptionInstrCommRateField *info = static_cast<CThostFtdcMMOptionInstrCommRateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "InvestorRange", info->InvestorRange);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "OpenRatioByMoney", info->OpenRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "OpenRatioByVolume", info->OpenRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "CloseRatioByMoney", info->CloseRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "CloseRatioByVolume", info->CloseRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "CloseTodayRatioByMoney", info->CloseTodayRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "CloseTodayRatioByVolume", info->CloseTodayRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "StrikeRatioByMoney", info->StrikeRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "StrikeRatioByVolume", info->StrikeRatioByVolume);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_INSTRUMENT_ORDER_COMM_RATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInstrumentOrderCommRateField *info = static_cast<CThostFtdcInstrumentOrderCommRateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "InvestorRange", info->InvestorRange);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "OrderCommByVolume", info->OrderCommByVolume);
    SET_PROPERTY_NUMBER(env, obj, "OrderActionCommByVolume", info->OrderActionCommByVolume);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_OPTION_INSTR_TRADE_COST) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcOptionInstrTradeCostField *info = static_cast<CThostFtdcOptionInstrTradeCostField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "FixedMargin", info->FixedMargin);
    SET_PROPERTY_NUMBER(env, obj, "MiniMargin", info->MiniMargin);
    SET_PROPERTY_NUMBER(env, obj, "Royalty", info->Royalty);
    SET_PROPERTY_NUMBER(env, obj, "ExchFixedMargin", info->ExchFixedMargin);
    SET_PROPERTY_NUMBER(env, obj, "ExchMiniMargin", info->ExchMiniMargin);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_OPTION_INSTR_COMM_RATE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcOptionInstrCommRateField *info = static_cast<CThostFtdcOptionInstrCommRateField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "InvestorRange", info->InvestorRange);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "OpenRatioByMoney", info->OpenRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "OpenRatioByVolume", info->OpenRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "CloseRatioByMoney", info->CloseRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "CloseRatioByVolume", info->CloseRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "CloseTodayRatioByMoney", info->CloseTodayRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "CloseTodayRatioByVolume", info->CloseTodayRatioByVolume);
    SET_PROPERTY_NUMBER(env, obj, "StrikeRatioByMoney", info->StrikeRatioByMoney);
    SET_PROPERTY_NUMBER(env, obj, "StrikeRatioByVolume", info->StrikeRatioByVolume);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_EXEC_ORDER) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcExecOrderField *info = static_cast<CThostFtdcExecOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ExecOrderRef", info->ExecOrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "OffsetFlag", info->OffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "ActionType", info->ActionType);
    SET_PROPERTY_CHAR(env, obj, "PosiDirection", info->PosiDirection);
    SET_PROPERTY_CHAR(env, obj, "ReservePositionFlag", info->ReservePositionFlag);
    SET_PROPERTY_CHAR(env, obj, "CloseFlag", info->CloseFlag);
    SET_PROPERTY_STRING(env, obj, "ExecOrderLocalID", info->ExecOrderLocalID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_CHAR(env, obj, "OrderSubmitStatus", info->OrderSubmitStatus);
    SET_PROPERTY_NUMBER(env, obj, "NotifySequence", info->NotifySequence);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_STRING(env, obj, "ExecOrderSysID", info->ExecOrderSysID);
    SET_PROPERTY_STRING(env, obj, "InsertDate", info->InsertDate);
    SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
    SET_PROPERTY_STRING(env, obj, "CancelTime", info->CancelTime);
    SET_PROPERTY_CHAR(env, obj, "ExecResult", info->ExecResult);
    SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "UserProductInfo", info->UserProductInfo);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "ActiveUserID", info->ActiveUserID);
    SET_PROPERTY_NUMBER(env, obj, "BrokerExecOrderSeq", info->BrokerExecOrderSeq);
    SET_PROPERTY_STRING(env, obj, "BranchID", info->BranchID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_FOR_QUOTE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcForQuoteField *info = static_cast<CThostFtdcForQuoteField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ForQuoteRef", info->ForQuoteRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "ForQuoteLocalID", info->ForQuoteLocalID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_STRING(env, obj, "InsertDate", info->InsertDate);
    SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
    SET_PROPERTY_CHAR(env, obj, "ForQuoteStatus", info->ForQuoteStatus);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "ActiveUserID", info->ActiveUserID);
    SET_PROPERTY_NUMBER(env, obj, "BrokerForQutoSeq", info->BrokerForQutoSeq);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_QUOTE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcQuoteField *info = static_cast<CThostFtdcQuoteField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "QuoteRef", info->QuoteRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_NUMBER(env, obj, "AskPrice", info->AskPrice);
    SET_PROPERTY_NUMBER(env, obj, "BidPrice", info->BidPrice);
    SET_PROPERTY_NUMBER(env, obj, "AskVolume", info->AskVolume);
    SET_PROPERTY_NUMBER(env, obj, "BidVolume", info->BidVolume);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "AskOffsetFlag", info->AskOffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "BidOffsetFlag", info->BidOffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "AskHedgeFlag", info->AskHedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "BidHedgeFlag", info->BidHedgeFlag);
    SET_PROPERTY_STRING(env, obj, "QuoteLocalID", info->QuoteLocalID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "NotifySequence", info->NotifySequence);
    SET_PROPERTY_CHAR(env, obj, "OrderSubmitStatus", info->OrderSubmitStatus);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_STRING(env, obj, "QuoteSysID", info->QuoteSysID);
    SET_PROPERTY_STRING(env, obj, "InsertDate", info->InsertDate);
    SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
    SET_PROPERTY_STRING(env, obj, "CancelTime", info->CancelTime);
    SET_PROPERTY_CHAR(env, obj, "QuoteStatus", info->QuoteStatus);
    SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_STRING(env, obj, "AskOrderSysID", info->AskOrderSysID);
    SET_PROPERTY_STRING(env, obj, "BidOrderSysID", info->BidOrderSysID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "UserProductInfo", info->UserProductInfo);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "ActiveUserID", info->ActiveUserID);
    SET_PROPERTY_NUMBER(env, obj, "BrokerQuoteSeq", info->BrokerQuoteSeq);
    SET_PROPERTY_STRING(env, obj, "AskOrderRef", info->AskOrderRef);
    SET_PROPERTY_STRING(env, obj, "BidOrderRef", info->BidOrderRef);
    SET_PROPERTY_STRING(env, obj, "ForQuoteSysID", info->ForQuoteSysID);
    SET_PROPERTY_STRING(env, obj, "BranchID", info->BranchID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_COMB_INSTRUMENT_GUARD) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcCombInstrumentGuardField *info = static_cast<CThostFtdcCombInstrumentGuardField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_NUMBER(env, obj, "GuarantRatio", info->GuarantRatio);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_COMB_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcCombActionField *info = static_cast<CThostFtdcCombActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "CombActionRef", info->CombActionRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_CHAR(env, obj, "CombDirection", info->CombDirection);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_STRING(env, obj, "ActionLocalID", info->ActionLocalID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_CHAR(env, obj, "ActionStatus", info->ActionStatus);
    SET_PROPERTY_NUMBER(env, obj, "NotifySequence", info->NotifySequence);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "UserProductInfo", info->UserProductInfo);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_TRANSFER_SERIAL) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcTransferSerialField *info = static_cast<CThostFtdcTransferSerialField *>(field->data);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_CHAR(env, obj, "FutureAccType", info->FutureAccType);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_CHAR(env, obj, "AvailabilityFlag", info->AvailabilityFlag);
    SET_PROPERTY_STRING(env, obj, "OperatorCode", info->OperatorCode);
    SET_PROPERTY_STRING(env, obj, "BankNewAccount", info->BankNewAccount);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_ACCOUNTREGISTER) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcAccountregisterField *info = static_cast<CThostFtdcAccountregisterField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeDay", info->TradeDay);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_CHAR(env, obj, "OpenOrDestroy", info->OpenOrDestroy);
    SET_PROPERTY_STRING(env, obj, "RegDate", info->RegDate);
    SET_PROPERTY_STRING(env, obj, "OutDate", info->OutDate);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_ERROR) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RTN_ORDER) {
    if (!!field->data) {
    CThostFtdcOrderField *info = static_cast<CThostFtdcOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "OrderPriceType", info->OrderPriceType);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_STRING(env, obj, "CombOffsetFlag", info->CombOffsetFlag);
    SET_PROPERTY_STRING(env, obj, "CombHedgeFlag", info->CombHedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTotalOriginal", info->VolumeTotalOriginal);
    SET_PROPERTY_CHAR(env, obj, "TimeCondition", info->TimeCondition);
    SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
    SET_PROPERTY_CHAR(env, obj, "VolumeCondition", info->VolumeCondition);
    SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
    SET_PROPERTY_CHAR(env, obj, "ContingentCondition", info->ContingentCondition);
    SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
    SET_PROPERTY_CHAR(env, obj, "ForceCloseReason", info->ForceCloseReason);
    SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "OrderLocalID", info->OrderLocalID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_CHAR(env, obj, "OrderSubmitStatus", info->OrderSubmitStatus);
    SET_PROPERTY_NUMBER(env, obj, "NotifySequence", info->NotifySequence);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
    SET_PROPERTY_CHAR(env, obj, "OrderSource", info->OrderSource);
    SET_PROPERTY_CHAR(env, obj, "OrderStatus", info->OrderStatus);
    SET_PROPERTY_CHAR(env, obj, "OrderType", info->OrderType);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTraded", info->VolumeTraded);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTotal", info->VolumeTotal);
    SET_PROPERTY_STRING(env, obj, "InsertDate", info->InsertDate);
    SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
    SET_PROPERTY_STRING(env, obj, "ActiveTime", info->ActiveTime);
    SET_PROPERTY_STRING(env, obj, "SuspendTime", info->SuspendTime);
    SET_PROPERTY_STRING(env, obj, "UpdateTime", info->UpdateTime);
    SET_PROPERTY_STRING(env, obj, "CancelTime", info->CancelTime);
    SET_PROPERTY_STRING(env, obj, "ActiveTraderID", info->ActiveTraderID);
    SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "UserProductInfo", info->UserProductInfo);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_NUMBER(env, obj, "UserForceClose", info->UserForceClose);
    SET_PROPERTY_STRING(env, obj, "ActiveUserID", info->ActiveUserID);
    SET_PROPERTY_NUMBER(env, obj, "BrokerOrderSeq", info->BrokerOrderSeq);
    SET_PROPERTY_STRING(env, obj, "RelativeOrderSysID", info->RelativeOrderSysID);
    SET_PROPERTY_NUMBER(env, obj, "ZCETotalTradedVolume", info->ZCETotalTradedVolume);
    SET_PROPERTY_NUMBER(env, obj, "IsSwapOrder", info->IsSwapOrder);
    SET_PROPERTY_STRING(env, obj, "BranchID", info->BranchID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_RTN_TRADE) {
    if (!!field->data) {
    CThostFtdcTradeField *info = static_cast<CThostFtdcTradeField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "TradeID", info->TradeID);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_CHAR(env, obj, "TradingRole", info->TradingRole);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_CHAR(env, obj, "OffsetFlag", info->OffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "Price", info->Price);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_CHAR(env, obj, "TradeType", info->TradeType);
    SET_PROPERTY_CHAR(env, obj, "PriceSource", info->PriceSource);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_STRING(env, obj, "OrderLocalID", info->OrderLocalID);
    SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_NUMBER(env, obj, "BrokerOrderSeq", info->BrokerOrderSeq);
    SET_PROPERTY_CHAR(env, obj, "TradeSource", info->TradeSource);
  };
  }  else if (eventId == ON_ERR_RTN_ORDER_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputOrderField *info = static_cast<CThostFtdcInputOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "OrderPriceType", info->OrderPriceType);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_STRING(env, obj, "CombOffsetFlag", info->CombOffsetFlag);
    SET_PROPERTY_STRING(env, obj, "CombHedgeFlag", info->CombHedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTotalOriginal", info->VolumeTotalOriginal);
    SET_PROPERTY_CHAR(env, obj, "TimeCondition", info->TimeCondition);
    SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
    SET_PROPERTY_CHAR(env, obj, "VolumeCondition", info->VolumeCondition);
    SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
    SET_PROPERTY_CHAR(env, obj, "ContingentCondition", info->ContingentCondition);
    SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
    SET_PROPERTY_CHAR(env, obj, "ForceCloseReason", info->ForceCloseReason);
    SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "UserForceClose", info->UserForceClose);
    SET_PROPERTY_NUMBER(env, obj, "IsSwapOrder", info->IsSwapOrder);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_ERR_RTN_ORDER_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcOrderActionField *info = static_cast<CThostFtdcOrderActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "OrderActionRef", info->OrderActionRef);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
    SET_PROPERTY_CHAR(env, obj, "ActionFlag", info->ActionFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeChange", info->VolumeChange);
    SET_PROPERTY_STRING(env, obj, "ActionDate", info->ActionDate);
    SET_PROPERTY_STRING(env, obj, "ActionTime", info->ActionTime);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_STRING(env, obj, "OrderLocalID", info->OrderLocalID);
    SET_PROPERTY_STRING(env, obj, "ActionLocalID", info->ActionLocalID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "OrderActionStatus", info->OrderActionStatus);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "BranchID", info->BranchID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_RTN_INSTRUMENT_STATUS) {
    if (!!field->data) {
    CThostFtdcInstrumentStatusField *info = static_cast<CThostFtdcInstrumentStatusField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "SettlementGroupID", info->SettlementGroupID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "InstrumentStatus", info->InstrumentStatus);
    SET_PROPERTY_NUMBER(env, obj, "TradingSegmentSN", info->TradingSegmentSN);
    SET_PROPERTY_STRING(env, obj, "EnterTime", info->EnterTime);
    SET_PROPERTY_CHAR(env, obj, "EnterReason", info->EnterReason);
  };
  }  else if (eventId == ON_RTN_BULLETIN) {
    if (!!field->data) {
    CThostFtdcBulletinField *info = static_cast<CThostFtdcBulletinField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "BulletinID", info->BulletinID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_STRING(env, obj, "NewsType", info->NewsType);
    SET_PROPERTY_CHAR(env, obj, "NewsUrgency", info->NewsUrgency);
    SET_PROPERTY_STRING(env, obj, "SendTime", info->SendTime);
    SET_PROPERTY_STRING(env, obj, "Abstract", info->Abstract);
    SET_PROPERTY_STRING(env, obj, "ComeFrom", info->ComeFrom);
    SET_PROPERTY_STRING(env, obj, "Content", info->Content);
    SET_PROPERTY_STRING(env, obj, "URLLink", info->URLLink);
    SET_PROPERTY_STRING(env, obj, "MarketID", info->MarketID);
  };
  }  else if (eventId == ON_RTN_TRADING_NOTICE) {
    if (!!field->data) {
    CThostFtdcTradingNoticeInfoField *info = static_cast<CThostFtdcTradingNoticeInfoField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "SendTime", info->SendTime);
    SET_PROPERTY_STRING(env, obj, "FieldContent", info->FieldContent);
    SET_PROPERTY_CHAR(env, obj, "SequenceSeries", info->SequenceSeries);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
  };
  }  else if (eventId == ON_RTN_ERROR_CONDITIONAL_ORDER) {
    if (!!field->data) {
    CThostFtdcErrorConditionalOrderField *info = static_cast<CThostFtdcErrorConditionalOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "OrderPriceType", info->OrderPriceType);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_STRING(env, obj, "CombOffsetFlag", info->CombOffsetFlag);
    SET_PROPERTY_STRING(env, obj, "CombHedgeFlag", info->CombHedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTotalOriginal", info->VolumeTotalOriginal);
    SET_PROPERTY_CHAR(env, obj, "TimeCondition", info->TimeCondition);
    SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
    SET_PROPERTY_CHAR(env, obj, "VolumeCondition", info->VolumeCondition);
    SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
    SET_PROPERTY_CHAR(env, obj, "ContingentCondition", info->ContingentCondition);
    SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
    SET_PROPERTY_CHAR(env, obj, "ForceCloseReason", info->ForceCloseReason);
    SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "OrderLocalID", info->OrderLocalID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_CHAR(env, obj, "OrderSubmitStatus", info->OrderSubmitStatus);
    SET_PROPERTY_NUMBER(env, obj, "NotifySequence", info->NotifySequence);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
    SET_PROPERTY_CHAR(env, obj, "OrderSource", info->OrderSource);
    SET_PROPERTY_CHAR(env, obj, "OrderStatus", info->OrderStatus);
    SET_PROPERTY_CHAR(env, obj, "OrderType", info->OrderType);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTraded", info->VolumeTraded);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTotal", info->VolumeTotal);
    SET_PROPERTY_STRING(env, obj, "InsertDate", info->InsertDate);
    SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
    SET_PROPERTY_STRING(env, obj, "ActiveTime", info->ActiveTime);
    SET_PROPERTY_STRING(env, obj, "SuspendTime", info->SuspendTime);
    SET_PROPERTY_STRING(env, obj, "UpdateTime", info->UpdateTime);
    SET_PROPERTY_STRING(env, obj, "CancelTime", info->CancelTime);
    SET_PROPERTY_STRING(env, obj, "ActiveTraderID", info->ActiveTraderID);
    SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "UserProductInfo", info->UserProductInfo);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_NUMBER(env, obj, "UserForceClose", info->UserForceClose);
    SET_PROPERTY_STRING(env, obj, "ActiveUserID", info->ActiveUserID);
    SET_PROPERTY_NUMBER(env, obj, "BrokerOrderSeq", info->BrokerOrderSeq);
    SET_PROPERTY_STRING(env, obj, "RelativeOrderSysID", info->RelativeOrderSysID);
    SET_PROPERTY_NUMBER(env, obj, "ZCETotalTradedVolume", info->ZCETotalTradedVolume);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "IsSwapOrder", info->IsSwapOrder);
    SET_PROPERTY_STRING(env, obj, "BranchID", info->BranchID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_RTN_EXEC_ORDER) {
    if (!!field->data) {
    CThostFtdcExecOrderField *info = static_cast<CThostFtdcExecOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ExecOrderRef", info->ExecOrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "OffsetFlag", info->OffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "ActionType", info->ActionType);
    SET_PROPERTY_CHAR(env, obj, "PosiDirection", info->PosiDirection);
    SET_PROPERTY_CHAR(env, obj, "ReservePositionFlag", info->ReservePositionFlag);
    SET_PROPERTY_CHAR(env, obj, "CloseFlag", info->CloseFlag);
    SET_PROPERTY_STRING(env, obj, "ExecOrderLocalID", info->ExecOrderLocalID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_CHAR(env, obj, "OrderSubmitStatus", info->OrderSubmitStatus);
    SET_PROPERTY_NUMBER(env, obj, "NotifySequence", info->NotifySequence);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_STRING(env, obj, "ExecOrderSysID", info->ExecOrderSysID);
    SET_PROPERTY_STRING(env, obj, "InsertDate", info->InsertDate);
    SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
    SET_PROPERTY_STRING(env, obj, "CancelTime", info->CancelTime);
    SET_PROPERTY_CHAR(env, obj, "ExecResult", info->ExecResult);
    SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "UserProductInfo", info->UserProductInfo);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "ActiveUserID", info->ActiveUserID);
    SET_PROPERTY_NUMBER(env, obj, "BrokerExecOrderSeq", info->BrokerExecOrderSeq);
    SET_PROPERTY_STRING(env, obj, "BranchID", info->BranchID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_ERR_RTN_EXEC_ORDER_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputExecOrderField *info = static_cast<CThostFtdcInputExecOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ExecOrderRef", info->ExecOrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "OffsetFlag", info->OffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "ActionType", info->ActionType);
    SET_PROPERTY_CHAR(env, obj, "PosiDirection", info->PosiDirection);
    SET_PROPERTY_CHAR(env, obj, "ReservePositionFlag", info->ReservePositionFlag);
    SET_PROPERTY_CHAR(env, obj, "CloseFlag", info->CloseFlag);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_ERR_RTN_EXEC_ORDER_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcExecOrderActionField *info = static_cast<CThostFtdcExecOrderActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "ExecOrderActionRef", info->ExecOrderActionRef);
    SET_PROPERTY_STRING(env, obj, "ExecOrderRef", info->ExecOrderRef);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ExecOrderSysID", info->ExecOrderSysID);
    SET_PROPERTY_CHAR(env, obj, "ActionFlag", info->ActionFlag);
    SET_PROPERTY_STRING(env, obj, "ActionDate", info->ActionDate);
    SET_PROPERTY_STRING(env, obj, "ActionTime", info->ActionTime);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_STRING(env, obj, "ExecOrderLocalID", info->ExecOrderLocalID);
    SET_PROPERTY_STRING(env, obj, "ActionLocalID", info->ActionLocalID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "OrderActionStatus", info->OrderActionStatus);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "ActionType", info->ActionType);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "BranchID", info->BranchID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_ERR_RTN_FOR_QUOTE_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputForQuoteField *info = static_cast<CThostFtdcInputForQuoteField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ForQuoteRef", info->ForQuoteRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_RTN_QUOTE) {
    if (!!field->data) {
    CThostFtdcQuoteField *info = static_cast<CThostFtdcQuoteField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "QuoteRef", info->QuoteRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_NUMBER(env, obj, "AskPrice", info->AskPrice);
    SET_PROPERTY_NUMBER(env, obj, "BidPrice", info->BidPrice);
    SET_PROPERTY_NUMBER(env, obj, "AskVolume", info->AskVolume);
    SET_PROPERTY_NUMBER(env, obj, "BidVolume", info->BidVolume);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "AskOffsetFlag", info->AskOffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "BidOffsetFlag", info->BidOffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "AskHedgeFlag", info->AskHedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "BidHedgeFlag", info->BidHedgeFlag);
    SET_PROPERTY_STRING(env, obj, "QuoteLocalID", info->QuoteLocalID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "NotifySequence", info->NotifySequence);
    SET_PROPERTY_CHAR(env, obj, "OrderSubmitStatus", info->OrderSubmitStatus);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_STRING(env, obj, "QuoteSysID", info->QuoteSysID);
    SET_PROPERTY_STRING(env, obj, "InsertDate", info->InsertDate);
    SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
    SET_PROPERTY_STRING(env, obj, "CancelTime", info->CancelTime);
    SET_PROPERTY_CHAR(env, obj, "QuoteStatus", info->QuoteStatus);
    SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_STRING(env, obj, "AskOrderSysID", info->AskOrderSysID);
    SET_PROPERTY_STRING(env, obj, "BidOrderSysID", info->BidOrderSysID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "UserProductInfo", info->UserProductInfo);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "ActiveUserID", info->ActiveUserID);
    SET_PROPERTY_NUMBER(env, obj, "BrokerQuoteSeq", info->BrokerQuoteSeq);
    SET_PROPERTY_STRING(env, obj, "AskOrderRef", info->AskOrderRef);
    SET_PROPERTY_STRING(env, obj, "BidOrderRef", info->BidOrderRef);
    SET_PROPERTY_STRING(env, obj, "ForQuoteSysID", info->ForQuoteSysID);
    SET_PROPERTY_STRING(env, obj, "BranchID", info->BranchID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_ERR_RTN_QUOTE_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputQuoteField *info = static_cast<CThostFtdcInputQuoteField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "QuoteRef", info->QuoteRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_NUMBER(env, obj, "AskPrice", info->AskPrice);
    SET_PROPERTY_NUMBER(env, obj, "BidPrice", info->BidPrice);
    SET_PROPERTY_NUMBER(env, obj, "AskVolume", info->AskVolume);
    SET_PROPERTY_NUMBER(env, obj, "BidVolume", info->BidVolume);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "AskOffsetFlag", info->AskOffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "BidOffsetFlag", info->BidOffsetFlag);
    SET_PROPERTY_CHAR(env, obj, "AskHedgeFlag", info->AskHedgeFlag);
    SET_PROPERTY_CHAR(env, obj, "BidHedgeFlag", info->BidHedgeFlag);
    SET_PROPERTY_STRING(env, obj, "AskOrderRef", info->AskOrderRef);
    SET_PROPERTY_STRING(env, obj, "BidOrderRef", info->BidOrderRef);
    SET_PROPERTY_STRING(env, obj, "ForQuoteSysID", info->ForQuoteSysID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_ERR_RTN_QUOTE_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcQuoteActionField *info = static_cast<CThostFtdcQuoteActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "QuoteActionRef", info->QuoteActionRef);
    SET_PROPERTY_STRING(env, obj, "QuoteRef", info->QuoteRef);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "QuoteSysID", info->QuoteSysID);
    SET_PROPERTY_CHAR(env, obj, "ActionFlag", info->ActionFlag);
    SET_PROPERTY_STRING(env, obj, "ActionDate", info->ActionDate);
    SET_PROPERTY_STRING(env, obj, "ActionTime", info->ActionTime);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_STRING(env, obj, "QuoteLocalID", info->QuoteLocalID);
    SET_PROPERTY_STRING(env, obj, "ActionLocalID", info->ActionLocalID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "OrderActionStatus", info->OrderActionStatus);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "BranchID", info->BranchID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_RTN_FOR_QUOTE_RSP) {
    if (!!field->data) {
    CThostFtdcForQuoteRspField *info = static_cast<CThostFtdcForQuoteRspField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ForQuoteSysID", info->ForQuoteSysID);
    SET_PROPERTY_STRING(env, obj, "ForQuoteTime", info->ForQuoteTime);
    SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
  };
  }  else if (eventId == ON_RTN_CFMMC_TRADING_ACCOUNT_TOKEN) {
    if (!!field->data) {
    CThostFtdcCFMMCTradingAccountTokenField *info = static_cast<CThostFtdcCFMMCTradingAccountTokenField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_NUMBER(env, obj, "KeyID", info->KeyID);
    SET_PROPERTY_STRING(env, obj, "Token", info->Token);
  };
  }  else if (eventId == ON_ERR_RTN_BATCH_ORDER_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcBatchOrderActionField *info = static_cast<CThostFtdcBatchOrderActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "OrderActionRef", info->OrderActionRef);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ActionDate", info->ActionDate);
    SET_PROPERTY_STRING(env, obj, "ActionTime", info->ActionTime);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_STRING(env, obj, "ActionLocalID", info->ActionLocalID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_CHAR(env, obj, "OrderActionStatus", info->OrderActionStatus);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_RTN_COMB_ACTION) {
    if (!!field->data) {
    CThostFtdcCombActionField *info = static_cast<CThostFtdcCombActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "CombActionRef", info->CombActionRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_CHAR(env, obj, "CombDirection", info->CombDirection);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_STRING(env, obj, "ActionLocalID", info->ActionLocalID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "ExchangeInstID", info->ExchangeInstID);
    SET_PROPERTY_STRING(env, obj, "TraderID", info->TraderID);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_CHAR(env, obj, "ActionStatus", info->ActionStatus);
    SET_PROPERTY_NUMBER(env, obj, "NotifySequence", info->NotifySequence);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "UserProductInfo", info->UserProductInfo);
    SET_PROPERTY_BUFFER(env, obj, "StatusMsg", info->StatusMsg);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_ERR_RTN_COMB_ACTION_INSERT) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcInputCombActionField *info = static_cast<CThostFtdcInputCombActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "CombActionRef", info->CombActionRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    SET_PROPERTY_CHAR(env, obj, "CombDirection", info->CombDirection);
    SET_PROPERTY_CHAR(env, obj, "HedgeFlag", info->HedgeFlag);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
  }  else if (eventId == ON_RSP_QRY_CONTRACT_BANK) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcContractBankField *info = static_cast<CThostFtdcContractBankField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
    SET_PROPERTY_BUFFER(env, obj, "BankName", info->BankName);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_PARKED_ORDER) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcParkedOrderField *info = static_cast<CThostFtdcParkedOrderField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "OrderPriceType", info->OrderPriceType);
    SET_PROPERTY_CHAR(env, obj, "Direction", info->Direction);
    SET_PROPERTY_STRING(env, obj, "CombOffsetFlag", info->CombOffsetFlag);
    SET_PROPERTY_STRING(env, obj, "CombHedgeFlag", info->CombHedgeFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeTotalOriginal", info->VolumeTotalOriginal);
    SET_PROPERTY_CHAR(env, obj, "TimeCondition", info->TimeCondition);
    SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
    SET_PROPERTY_CHAR(env, obj, "VolumeCondition", info->VolumeCondition);
    SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
    SET_PROPERTY_CHAR(env, obj, "ContingentCondition", info->ContingentCondition);
    SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
    SET_PROPERTY_CHAR(env, obj, "ForceCloseReason", info->ForceCloseReason);
    SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
    SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "UserForceClose", info->UserForceClose);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "ParkedOrderID", info->ParkedOrderID);
    SET_PROPERTY_CHAR(env, obj, "UserType", info->UserType);
    SET_PROPERTY_CHAR(env, obj, "Status", info->Status);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "IsSwapOrder", info->IsSwapOrder);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_PARKED_ORDER_ACTION) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcParkedOrderActionField *info = static_cast<CThostFtdcParkedOrderActionField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_NUMBER(env, obj, "OrderActionRef", info->OrderActionRef);
    SET_PROPERTY_STRING(env, obj, "OrderRef", info->OrderRef);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "FrontID", info->FrontID);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
    SET_PROPERTY_CHAR(env, obj, "ActionFlag", info->ActionFlag);
    SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
    SET_PROPERTY_NUMBER(env, obj, "VolumeChange", info->VolumeChange);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_STRING(env, obj, "ParkedOrderActionID", info->ParkedOrderActionID);
    SET_PROPERTY_CHAR(env, obj, "UserType", info->UserType);
    SET_PROPERTY_CHAR(env, obj, "Status", info->Status);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_STRING(env, obj, "InvestUnitID", info->InvestUnitID);
    SET_PROPERTY_STRING(env, obj, "IPAddress", info->IPAddress);
    SET_PROPERTY_STRING(env, obj, "MacAddress", info->MacAddress);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_TRADING_NOTICE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcTradingNoticeField *info = static_cast<CThostFtdcTradingNoticeField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_CHAR(env, obj, "InvestorRange", info->InvestorRange);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_CHAR(env, obj, "SequenceSeries", info->SequenceSeries);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_STRING(env, obj, "SendTime", info->SendTime);
    SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    SET_PROPERTY_STRING(env, obj, "FieldContent", info->FieldContent);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_BROKER_TRADING_PARAMS) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcBrokerTradingParamsField *info = static_cast<CThostFtdcBrokerTradingParamsField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    SET_PROPERTY_CHAR(env, obj, "MarginPriceType", info->MarginPriceType);
    SET_PROPERTY_CHAR(env, obj, "Algorithm", info->Algorithm);
    SET_PROPERTY_CHAR(env, obj, "AvailIncludeCloseProfit", info->AvailIncludeCloseProfit);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_CHAR(env, obj, "OptionRoyaltyPriceType", info->OptionRoyaltyPriceType);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QRY_BROKER_TRADING_ALGOS) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcBrokerTradingAlgosField *info = static_cast<CThostFtdcBrokerTradingAlgosField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
    SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    SET_PROPERTY_CHAR(env, obj, "HandlePositionAlgoID", info->HandlePositionAlgoID);
    SET_PROPERTY_CHAR(env, obj, "FindMarginRateAlgoID", info->FindMarginRateAlgoID);
    SET_PROPERTY_CHAR(env, obj, "HandleTradingAccountAlgoID", info->HandleTradingAccountAlgoID);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QUERY_CFMMC_TRADING_ACCOUNT_TOKEN) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcQueryCFMMCTradingAccountTokenField *info = static_cast<CThostFtdcQueryCFMMCTradingAccountTokenField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK) {
    if (!!field->data) {
    CThostFtdcRspTransferField *info = static_cast<CThostFtdcRspTransferField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK) {
    if (!!field->data) {
    CThostFtdcRspTransferField *info = static_cast<CThostFtdcRspTransferField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK) {
    if (!!field->data) {
    CThostFtdcRspRepealField *info = static_cast<CThostFtdcRspRepealField *>(field->data);
    SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
    SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
    SET_PROPERTY_CHAR(env, obj, "BankRepealFlag", info->BankRepealFlag);
    SET_PROPERTY_CHAR(env, obj, "BrokerRepealFlag", info->BrokerRepealFlag);
    SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
    SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
    SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK) {
    if (!!field->data) {
    CThostFtdcRspRepealField *info = static_cast<CThostFtdcRspRepealField *>(field->data);
    SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
    SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
    SET_PROPERTY_CHAR(env, obj, "BankRepealFlag", info->BankRepealFlag);
    SET_PROPERTY_CHAR(env, obj, "BrokerRepealFlag", info->BrokerRepealFlag);
    SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
    SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
    SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE) {
    if (!!field->data) {
    CThostFtdcRspTransferField *info = static_cast<CThostFtdcRspTransferField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_FROM_FUTURE_TO_BANK_BY_FUTURE) {
    if (!!field->data) {
    CThostFtdcRspTransferField *info = static_cast<CThostFtdcRspTransferField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL) {
    if (!!field->data) {
    CThostFtdcRspRepealField *info = static_cast<CThostFtdcRspRepealField *>(field->data);
    SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
    SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
    SET_PROPERTY_CHAR(env, obj, "BankRepealFlag", info->BankRepealFlag);
    SET_PROPERTY_CHAR(env, obj, "BrokerRepealFlag", info->BrokerRepealFlag);
    SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
    SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
    SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL) {
    if (!!field->data) {
    CThostFtdcRspRepealField *info = static_cast<CThostFtdcRspRepealField *>(field->data);
    SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
    SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
    SET_PROPERTY_CHAR(env, obj, "BankRepealFlag", info->BankRepealFlag);
    SET_PROPERTY_CHAR(env, obj, "BrokerRepealFlag", info->BrokerRepealFlag);
    SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
    SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
    SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE) {
    if (!!field->data) {
    CThostFtdcNotifyQueryAccountField *info = static_cast<CThostFtdcNotifyQueryAccountField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_NUMBER(env, obj, "BankUseAmount", info->BankUseAmount);
    SET_PROPERTY_NUMBER(env, obj, "BankFetchAmount", info->BankFetchAmount);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_ERR_RTN_BANK_TO_FUTURE_BY_FUTURE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcReqTransferField *info = static_cast<CThostFtdcReqTransferField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_ERR_RTN_FUTURE_TO_BANK_BY_FUTURE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcReqTransferField *info = static_cast<CThostFtdcReqTransferField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcReqRepealField *info = static_cast<CThostFtdcReqRepealField *>(field->data);
    SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
    SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
    SET_PROPERTY_CHAR(env, obj, "BankRepealFlag", info->BankRepealFlag);
    SET_PROPERTY_CHAR(env, obj, "BrokerRepealFlag", info->BrokerRepealFlag);
    SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
    SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
    SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcReqRepealField *info = static_cast<CThostFtdcReqRepealField *>(field->data);
    SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
    SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
    SET_PROPERTY_CHAR(env, obj, "BankRepealFlag", info->BankRepealFlag);
    SET_PROPERTY_CHAR(env, obj, "BrokerRepealFlag", info->BrokerRepealFlag);
    SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
    SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
    SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcReqQueryAccountField *info = static_cast<CThostFtdcReqQueryAccountField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE) {
    if (!!field->data) {
    CThostFtdcRspRepealField *info = static_cast<CThostFtdcRspRepealField *>(field->data);
    SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
    SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
    SET_PROPERTY_CHAR(env, obj, "BankRepealFlag", info->BankRepealFlag);
    SET_PROPERTY_CHAR(env, obj, "BrokerRepealFlag", info->BrokerRepealFlag);
    SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
    SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
    SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE) {
    if (!!field->data) {
    CThostFtdcRspRepealField *info = static_cast<CThostFtdcRspRepealField *>(field->data);
    SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
    SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
    SET_PROPERTY_CHAR(env, obj, "BankRepealFlag", info->BankRepealFlag);
    SET_PROPERTY_CHAR(env, obj, "BrokerRepealFlag", info->BrokerRepealFlag);
    SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
    SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
    SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcReqTransferField *info = static_cast<CThostFtdcReqTransferField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcReqTransferField *info = static_cast<CThostFtdcReqTransferField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
    SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
    SET_PROPERTY_CHAR(env, obj, "FeePayFlag", info->FeePayFlag);
    SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
    SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
    SET_PROPERTY_STRING(env, obj, "Message", info->Message);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_CHAR(env, obj, "TransferStatus", info->TransferStatus);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE) {
  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }
    if (!!field->data) {
    CThostFtdcReqQueryAccountField *info = static_cast<CThostFtdcReqQueryAccountField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }  else if (eventId == ON_RTN_OPEN_ACCOUNT_BY_BANK) {
    if (!!field->data) {
    CThostFtdcOpenAccountField *info = static_cast<CThostFtdcOpenAccountField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "Gender", info->Gender);
    SET_PROPERTY_STRING(env, obj, "CountryCode", info->CountryCode);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "Address", info->Address);
    SET_PROPERTY_STRING(env, obj, "ZipCode", info->ZipCode);
    SET_PROPERTY_STRING(env, obj, "Telephone", info->Telephone);
    SET_PROPERTY_STRING(env, obj, "MobilePhone", info->MobilePhone);
    SET_PROPERTY_STRING(env, obj, "Fax", info->Fax);
    SET_PROPERTY_STRING(env, obj, "EMail", info->EMail);
    SET_PROPERTY_CHAR(env, obj, "MoneyAccountStatus", info->MoneyAccountStatus);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_CHAR(env, obj, "CashExchangeCode", info->CashExchangeCode);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_CANCEL_ACCOUNT_BY_BANK) {
    if (!!field->data) {
    CThostFtdcCancelAccountField *info = static_cast<CThostFtdcCancelAccountField *>(field->data);
    SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
    SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
    SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
    SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
    SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
    SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
    SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
    SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
    SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
    SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
    SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
    SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
    SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
    SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
    SET_PROPERTY_CHAR(env, obj, "Gender", info->Gender);
    SET_PROPERTY_STRING(env, obj, "CountryCode", info->CountryCode);
    SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
    SET_PROPERTY_STRING(env, obj, "Address", info->Address);
    SET_PROPERTY_STRING(env, obj, "ZipCode", info->ZipCode);
    SET_PROPERTY_STRING(env, obj, "Telephone", info->Telephone);
    SET_PROPERTY_STRING(env, obj, "MobilePhone", info->MobilePhone);
    SET_PROPERTY_STRING(env, obj, "Fax", info->Fax);
    SET_PROPERTY_STRING(env, obj, "EMail", info->EMail);
    SET_PROPERTY_CHAR(env, obj, "MoneyAccountStatus", info->MoneyAccountStatus);
    SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
    SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
    SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
    SET_PROPERTY_STRING(env, obj, "Password", info->Password);
    SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
    SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
    SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    SET_PROPERTY_CHAR(env, obj, "CashExchangeCode", info->CashExchangeCode);
    SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
    SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
    SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
    SET_PROPERTY_CHAR(env, obj, "BankSecuAccType", info->BankSecuAccType);
    SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
    SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
    SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
    SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
    SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
    SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
    SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
  };
  }  else if (eventId == ON_RTN_CHANGE_ACCOUNT_BY_BANK) {
    if (!!field->data) {
      CThostFtdcChangeAccountField *info = static_cast<CThostFtdcChangeAccountField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBranchID", info->BankBranchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_CHAR(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_CHAR(env, obj, "IdCardType", info->IdCardType);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_CHAR(env, obj, "Gender", info->Gender);
      SET_PROPERTY_STRING(env, obj, "CountryCode", info->CountryCode);
      SET_PROPERTY_CHAR(env, obj, "CustType", info->CustType);
      SET_PROPERTY_STRING(env, obj, "Address", info->Address);
      SET_PROPERTY_STRING(env, obj, "ZipCode", info->ZipCode);
      SET_PROPERTY_STRING(env, obj, "Telephone", info->Telephone);
      SET_PROPERTY_STRING(env, obj, "MobilePhone", info->MobilePhone);
      SET_PROPERTY_STRING(env, obj, "Fax", info->Fax);
      SET_PROPERTY_STRING(env, obj, "EMail", info->EMail);
      SET_PROPERTY_CHAR(env, obj, "MoneyAccountStatus", info->MoneyAccountStatus);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "NewBankAccount", info->NewBankAccount);
      SET_PROPERTY_STRING(env, obj, "NewBankPassWord", info->NewBankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_CHAR(env, obj, "BankAccType", info->BankAccType);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_CHAR(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_CHAR(env, obj, "BankPwdFlag", info->BankPwdFlag);
      SET_PROPERTY_CHAR(env, obj, "SecuPwdFlag", info->SecuPwdFlag);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", info->ErrorMsg);
      SET_PROPERTY_BUFFER(env, obj, "LongCustomerName", info->LongCustomerName);
    };
  }

  if (cbMap.find(eventId) != cbMap.end()) {
    cbMap.find(eventId)->second->Value().Call({env.Null(), obj});
  }

  delete req->data;
  delete req;
  
};