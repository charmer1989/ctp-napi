const fs = require('fs');
const path = require('path');
const _ = require('lodash');

let str = `	///订阅行情。
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

// // 制作 ctp-struct.json
// let dataStruct = fs.readFileSync(path.join(__dirname, '../tradeapi/ThostFtdcUserApiStruct.h')).toString();
// let structReg = /struct\s([a-zA-Z]*)\s*\n\{([^\}]*)\};/g;
// let arr = dataStruct.match(structReg);

// let structObj = {};
// arr.forEach((s) => {
//   let a = s.match(/struct\s([a-zA-Z]*)\s*\n\{([^\}]*)\};/);
//   if (!a) return;
//   let structName = a[1];
//   let structFields = [];
//   a[2].split("\n").forEach((one) => {
//     let oneArr = one.match(/([a-zA-Z]*)\s*([a-zA-Z1-5]*);/);
//     if (oneArr && oneArr.length) {
//       structFields.push({ fieldType: oneArr[1], fieldName: oneArr[2] });
//     }
//   });
//   structObj[structName] = structFields;
// });
// console.log('[DEBUG]', structObj);
// fs.writeFileSync("./ctp-struct.json", JSON.stringify(structObj));



//制作 ctp-data-type.json
// let dataTypeStr = fs.readFileSync(path.join(__dirname, "../tradeapi/ThostFtdcUserApiDataType.h")).toString("utf8");

// let dataType = {};
// dataTypeStr.split('\n').forEach((line) => {
//   if (line.match(/typedef\schar\s([a-zA-Z]*)\[\d*\];/)) {
//     console.log('[DEBUG]', line);
//     let arr = line.match(/typedef\schar\s([a-zA-Z]*)\[\d*\];/);
//     dataType[arr[1]] = "char";
//   } else if (line.match(/typedef\s(int|double|short|float)\s([a-zA-Z]*);/)) {
//     let arr = line.match(/typedef\s(int|double|short|float)\s([a-zA-Z]*);/);
//     dataType[arr[2]] = arr[1];
//   }
// });

// console.log('[DEBUG]', dataType);
// fs.writeFileSync("./ctp-data-type.json", JSON.stringify(dataType));