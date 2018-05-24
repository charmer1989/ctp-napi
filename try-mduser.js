const Ctp = require('./build/Release/ctp-napi.node');
const iconv = require('iconv-lite');

console.log('[DEBUG in js]', 'typeof femas:', typeof Ctp);
console.log('[DEBUG in js]', 'typeof femas.Mduser:', typeof Ctp.Mduser);

let mduser = new Ctp.Mduser({ debug: true });
console.log('[DEBUG in js]', 'typeof mduser:', typeof mduser);

mduser.On("frontConnected", function (err, rsp) {
  console.log('[DEBUG in js]', 'on frontConnected', { err, rsp: convert(rsp) });
  let ret = mduser.Call("reqUserLogin", {
    UserID: "UserID",
    BrokerID: "BrokerID",
    Password: "Password",
    UserProductInfo: "UserProductInfo",
    TradingDay: "20181212"
  });
  console.log('[DEBUG in js]', 'call req user login:', ret);
});
mduser.On("rspError", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rspError', { err, rsp: convert(rsp) });
});

mduser.On("rspUserLogin", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rspUserLogin', { err, rsp: convert(rsp) });
  mduser.Call("subscribeMarketData", {
    InstrumentID: "rb1805"
  });
  // mduser.Call("subMarketData", {
  //   InstrumentID: "IC1708"
  // });
  // mduser.Call("reqSubMarketData", {
  //   InstrumentID: "IC1708"
  // });
});
mduser.On("rspSubMarketData", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rspSubMarketData', { err, rsp: convert(rsp) });
});
mduser.On("rtnDepthMarketData", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rtnDepthMarketData', { err, rsp: convert(rsp) });
});


mduser.Call("connect", {
  IP: "tcp://180.168.146.187:10010",
  RESUME_TYPE: "QUICK"
});

function convert(obj) {
  if (!obj) return obj;
  for (var k in obj) {
    if (Buffer.isBuffer(obj[k])) {
      obj[k] = iconv.decode(obj[k], "GB2312")
    }
  }
  return obj;
}

setInterval(() => {
  mduser.Call("checkLoop", {});
}, 0);