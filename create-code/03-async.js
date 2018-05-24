const _ = require('lodash');
const fs = require('fs');

let str = `	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
virtual void OnFrontConnected(){};

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
virtual void OnFrontDisconnected(int nReason){};
  
///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
virtual void OnHeartBeatWarning(int nTimeLapse){};


///登录请求响应
virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

///登出请求响应
virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

///错误应答
virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

///订阅行情应答
virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

///取消订阅行情应答
virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

///订阅询价应答
virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

///取消订阅询价应答
virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

///深度行情通知
virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) {};

///询价通知
virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) {};`;

let STRUCT = require('./ctp-struct.json');
let DATA_TYPE = require('./ctp-data-type.json');

let rspInfo = (params) => {
  let res = "";
  if (params.some(p => p.match(/CThostFtdcRspInfoField/))) {
    res =
      `\n  if (!!field->rspInfo) {
    CThostFtdcRspInfoField *rspInfo = static_cast<CThostFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }`;
  }
  return res;
};

let info = (params) => {
  let res = "";
  params.forEach(p => {
    if (p.match(/CThostFtdc/) && !p.match(/CThostFtdcRspInfoField/)) {
      let arr = p.match(/\s*([a-zA-Z]*)\s*\*([a-zA-Z]*)/);
      let paramType = arr[1];
      let paramName = arr[2];
      // console.log('[DEBUG]', arr);
      res += `\n    if (!!field->data) {
    ${paramType} *info = static_cast<${paramType} *>(field->data);`;
      if (!STRUCT[paramType]) {
        console.log('[WARN]', 'no STRUCT:', paramType);
      }
      STRUCT[paramType].forEach(field => {
        if (DATA_TYPE[field.fieldType] === "int" || DATA_TYPE[field.fieldType] === "double") {
          res += `\n    SET_PROPERTY_NUMBER(env, obj, "${field.fieldName}", info->${field.fieldName});`;
        } else if (DATA_TYPE[field.fieldType] === "char") {
          if (field.fieldName === "ErrorMsg" || field.fieldName === "StatusMsg" || field.fieldName.indexOf("Name") > -1) {
            res += `\n    SET_PROPERTY_BUFFER(env, obj, "${field.fieldName}", info->${field.fieldName});`;
          } else {
            res += `\n    SET_PROPERTY_STRING(env, obj, "${field.fieldName}", info->${field.fieldName});`;
          }
        } else {
          res += `\n    SET_PROPERTY_CHAR(env, obj, "${field.fieldName}", info->${field.fieldName});`;
        }
      });
      res += `\n  };`
    }
  });
  return res;
};

let errCode = (params) => {
  return "";
};

let requestId = (params) => {
  let res = "";
  params.forEach((p) => {
    if (p.match(/nRequestID/)) {
      res = `\n    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);`
    }
  });
  return res;
};

str.split("\n").forEach((line) => {
  let arr = line.match(/\s*virtual\svoid\s([a-zA-Z]*)\(([^\(\)]*)\)\s*\{\};/);
  // console.log('[DEBUG]', arr);
  if (!arr || !arr.length) return;
  let funcName = arr[1];
  let paramsStr = arr[2];
  let params = paramsStr.split(",").map(s => s.trim());
  // console.log('[DEBUG]', params);
  let res =
    `  else if (eventId == ${_.replace(_.upperCase(_.snakeCase(funcName)), /\s/g, "_")}) {${rspInfo(params)}${info(params)}${errCode(params)}${requestId(params)}
  }`;
  // console.log(res);
  fs.appendFileSync("./tmp-callback.txt", res);
});