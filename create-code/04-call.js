const _ = require('lodash');
const fs = require('fs');

let str = `///订阅行情。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
virtual int SubscribeMarketData(char *ppInstrumentID[], int nCount) = 0;

///退订行情。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
virtual int UnSubscribeMarketData(char *ppInstrumentID[], int nCount) = 0;

///订阅询价。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
virtual int SubscribeForQuoteRsp(char *ppInstrumentID[], int nCount) = 0;

///退订询价。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
virtual int UnSubscribeForQuoteRsp(char *ppInstrumentID[], int nCount) = 0;

///用户登录请求
virtual int ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;


///登出请求
virtual int ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;`;

let STRUCT = require('./ctp-struct.json');
let DATA_TYPE = require('./ctp-data-type.json');

let getParamsStr = (paramType) => {
  return STRUCT[paramType].map((field) => {
    if (DATA_TYPE[field.fieldType] === 'int' || DATA_TYPE[field.fieldType] === 'double') {
      return `  req.${field.fieldName} = getNumber(params, "${field.fieldName}");`;
    } else if (DATA_TYPE[field.fieldType]) {
      return `  strcpy(req.${field.fieldName}, getString(params, "${field.fieldName}").c_str());`;
    } else {
      return `  req.${field.fieldName} = getChar(params, "${field.fieldName}");`;
    }
  }).join("\n");
};

str.split("\n").forEach((line) => {
  let arr = line.match(/\s*virtual\s(int|void)\s([a-zA-Z]*)\(([^\(\)]*)\)\s\=\s0;/);
  if (!arr) {
    return;
  }
  // console.log('[DEBUG]', arr);
  let funcName = arr[2];
  let paramStr = arr[3];
  let params = paramStr.split(",");
  let paramType;
  params.forEach(p => {
    if (p.match(/CThostFtdc/)) { //////////////注意这里
      paramType = p.split(/[\s ]/)[0];
    }
  });
  if (!paramType) {
    let res = `else if (funcName == "${_.camelCase(funcName)}") {
    MD_DEBUG_LOG("call function ${_.camelCase(funcName)}");
    ReqID++;
    int ret = this->api->${funcName}();
    return Napi::Number::New(info.Env(), ret);
  }`;
    // console.log('[DEBUG]', res);
    fs.appendFileSync("./tmp-call.txt", res);
    return;
  }
  let res = `else if (funcName == "${_.camelCase(funcName)}") {
    MD_DEBUG_LOG("call function ${_.camelCase(funcName)}");
    ReqID++;
    ${paramType} req;
    memset(&req, 0, sizeof(${paramType}));
${getParamsStr(paramType)}
    int ret = this->api->${funcName}(&req, ReqID);
    return Napi::Number::New(info.Env(), ret);
  }`;
    fs.appendFileSync("./tmp-call.txt", res);
  // console.log('[DEBUG]', res);
});