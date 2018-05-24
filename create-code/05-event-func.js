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

let rspInfo = (params) => {
  if (params.some(s => s.match(/CThostFtdcRspInfoField/))) {
    return `\n  if (pRspInfo) {
    CThostFtdcRspInfoField *_pRspInfo = new CThostFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
    field->rspInfo    = _pRspInfo;
    } else {
      field->rspInfo = nullptr;
    }`;
  }
  return "\n  field->rspInfo = nullptr;";
};
let nRequestID = (params) => {
  if (params.some(s => s.match(/int\snRequestID/))) {
    return `\n  field->nRequestID = nRequestID;`;
  }
  return "\n  field->nRequestID = -1;";
};
let CThostFtdcParams = (params) => {
  if (params.some(s => s.match(/CThostFtdc/) && !s.match(/CThostFtdcRspInfoField/))) {
    let res = '';
    params.forEach(s => {
      if (s.match(/CThostFtdc/) && !s.match(/CThostFtdcRspInfoField/)) {
        let arr = s.match(/(CThostFtdc[^\s]*)\s*\*([a-zA-Z]*)/);
        let paramType = arr[1];
        let paramName = arr[2];
        res = `\n  if (${paramName}) {
      ${paramType} *_info = new ${paramType}();
      memcpy(_info, ${paramName}, sizeof(${paramType}));
      field->data = _info;
    } else {
      field->data = nullptr;
    }`;
      }
    });
    return res;
  }
  return "\n  field->data = nullptr;";
};

str.split("\n").forEach((line) => {
  let arr = line.match(/\s*virtual\svoid\s([a-zA-Z]*)\(([^\(\)]*)\)\s*\{\};/);
  // console.log('[DEBUG]', arr);
  if (!arr || !arr.length) return;
  let funcName = arr[1];
  let paramsStr = arr[2];
  let params = paramsStr.split(",").map(s => s.trim());
  let res = `void Trader::${funcName}(${params.join(",")}) {
  MD_DEBUG_LOG("${funcName} called.");
  TdCbField *field                 = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req                   = new uv_work_t;${rspInfo(params)}${nRequestID(params)}${CThostFtdcParams(params)}
  MD_EVENT_CALL(field, ${_.replace(_.upperCase(_.snakeCase(funcName)), /\s/g, "_")}, 0);
};\n`;
  console.log('[DEBUG]', res);

  fs.appendFileSync("./tmp-func.txt", res);
});