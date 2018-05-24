const Ctp = require("./build/Release/ctp-napi.node");
const iconv = require("iconv-lite");

console.log("[DEBUG in js]", "typeof femas:", typeof Ctp);
console.log("[DEBUG in js]", "typeof femas.Trader:", typeof Ctp.Trader);

let trader = new Ctp.Trader({ debug: true });
console.log("[DEBUG in js]", "typeof trader:", typeof trader);

trader.On("frontConnected", function(err, rsp) {
  console.log("[DEBUG in js]", "on frontConnected", { err, rsp: convert(rsp) });
  let ret = trader.Call("reqAuthenticate", {
    UserID: "UserID",
    BrokerID: "BrokerID",
    UserProductInfo: "UserProductInfo",
    AuthCode: "AuthCode"
  });
  // let ret = trader.Call("reqUserLogin", {
  // UserID: "UserID",
  // BrokerID: "BrokerID",
  // Password: "Password",
  // UserProductInfo: "UserProductInfo"
  // });
  console.log("[DEBUG in js]", "call req user login:", ret);
});

trader.On("rspError", function(err, rsp) {
  console.log("[DEBUG in js]", "on rspError", { err, rsp: convert(rsp) });
});
trader.On("rspAuthenticate", function(err, rsp) {
  console.log("[DEBUG in js]", "on rspAuthenticate", { err, rsp: convert(rsp) });
  let ret = trader.Call("reqUserLogin", {
    UserID: "UserID",
    BrokerID: "BrokerID",
    Password: "Password",
    UserProductInfo: "UserProductInfo"
  });
});
trader.On("rspQryExchange", function(err, rsp) {
  console.log("[DEBUG in js]", "on rspQryExchange", { err, rsp: convert(rsp) });
});
trader.On("errRtnOrderInsert", function(err, rsp) {
  console.log("[DEBUG in js]", "on errRtnOrderInsert", { err, rsp: convert(rsp) });
});
trader.On("rtnOrder", function(err, rsp) {
  console.log("[DEBUG in js]", "on rtnOrder", { err, rsp: convert(rsp) });
});
trader.On("rspOrderInsert", function(err, rsp) {
  console.log("[DEBUG in js]", "on rspOrderInsert", { err, rsp: convert(rsp) });
});

trader.On("rspUserLogin", function(err, rsp) {
  console.log("[DEBUG in js]", "on rspUserLogin", { err, rsp: convert(rsp) });
  // trader.Call("reqQryExchange", {
  //   ExchangeID: "DCE"
  // });
  trader.Call("reqSettlementInfoConfirm", {
    BrokerID: "BrokerID",
    InvestorID: "InvestorID"
  });
  setTimeout(() => {
    trader.Call("reqOrderInsert", {
      BrokerID: "BrokerID",
      InvestorID: "InvestorID",
      InstrumentID: "InstrumentID",
      OrderRef: "000000000006",
      UserID: "UserID",
      OrderPriceType: "2",
      Direction: "1", // 0买 1卖
      CombOffsetFlag: "0",
      CombHedgeFlag: "1",
      LimitPrice: 3700,
      VolumeTotalOriginal: 1,
      TimeCondition: "1",
      VolumeCondition: "1",
      MinVolume: 0,
      ContingentCondition: "1",
      StopPrice: 0,
      ForceCloseReason: "0",
      IsAutoSuspend: 0,
      BusinessUnit: "",
      RequestID: 100,
      ExchangeID: "SHFE"
    });
  }, 1000);
});
trader.On("rtnInstrumentStatus", function(err, rsp) {
  console.log("[DEBUG in js]", "on rtnInstrumentStatus", { err, rsp: convert(rsp) });
});

trader.Call("connect", {
  IP: "tcp://122.224.98.87:27225"
});

function convert(obj) {
  if (!obj) return obj;
  for (var k in obj) {
    if (Buffer.isBuffer(obj[k])) {
      obj[k] = iconv.decode(obj[k], "GB2312");
    }
  }
  return obj;
}
