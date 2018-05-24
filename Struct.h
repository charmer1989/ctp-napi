#ifndef _WRAPER_STRUCT_
#define _WRAPER_STRUCT_

#include <math.h>
#include <float.h>
double roundFunc(double x, int n);

///// 外部使用
#define ON_FRONT_CONNECTED 1001
#define ON_FRONT_DISCONNECTED 1002
#define ON_HEART_BEAT_WARNING 1003
#define ON_RSP_AUTHENTICATE 1004
#define ON_RSP_USER_LOGIN 1005
#define ON_RSP_USER_LOGOUT 1006
#define ON_RSP_USER_PASSWORD_UPDATE 1007
#define ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE 1008
#define ON_RSP_ORDER_INSERT 1009
#define ON_RSP_PARKED_ORDER_INSERT 1010
#define ON_RSP_PARKED_ORDER_ACTION 1011
#define ON_RSP_ORDER_ACTION 1012
#define ON_RSP_QUERY_MAX_ORDER_VOLUME 1013
#define ON_RSP_SETTLEMENT_INFO_CONFIRM 1014
#define ON_RSP_REMOVE_PARKED_ORDER 1015
#define ON_RSP_REMOVE_PARKED_ORDER_ACTION 1016
#define ON_RSP_EXEC_ORDER_INSERT 1017
#define ON_RSP_EXEC_ORDER_ACTION 1018
#define ON_RSP_FOR_QUOTE_INSERT 1019
#define ON_RSP_QUOTE_INSERT 1020
#define ON_RSP_QUOTE_ACTION 1021
#define ON_RSP_BATCH_ORDER_ACTION 1022
#define ON_RSP_COMB_ACTION_INSERT 1023
#define ON_RSP_QRY_ORDER 1024
#define ON_RSP_QRY_TRADE 1025
#define ON_RSP_QRY_INVESTOR_POSITION 1026
#define ON_RSP_QRY_TRADING_ACCOUNT 1027
#define ON_RSP_QRY_INVESTOR 1028
#define ON_RSP_QRY_TRADING_CODE 1029
#define ON_RSP_QRY_INSTRUMENT_MARGIN_RATE 1030
#define ON_RSP_QRY_INSTRUMENT_COMMISSION_RATE 1031
#define ON_RSP_QRY_EXCHANGE 1032
#define ON_RSP_QRY_PRODUCT 1033
#define ON_RSP_QRY_INSTRUMENT 1034
#define ON_RSP_QRY_DEPTH_MARKET_DATA 1035
#define ON_RSP_QRY_SETTLEMENT_INFO 1036
#define ON_RSP_QRY_TRANSFER_BANK 1037
#define ON_RSP_QRY_INVESTOR_POSITION_DETAIL 1038
#define ON_RSP_QRY_NOTICE 1039
#define ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM 1040
#define ON_RSP_QRY_INVESTOR_POSITION_COMBINE_DETAIL 1041
#define ON_RSP_QRY_CFMMC_TRADING_ACCOUNT_KEY 1042
#define ON_RSP_QRY_E_WARRANT_OFFSET 1043
#define ON_RSP_QRY_INVESTOR_PRODUCT_GROUP_MARGIN 1044
#define ON_RSP_QRY_EXCHANGE_MARGIN_RATE 1045
#define ON_RSP_QRY_EXCHANGE_MARGIN_RATE_ADJUST 1046
#define ON_RSP_QRY_EXCHANGE_RATE 1047
#define ON_RSP_QRY_SEC_AGENT_ACID_MAP 1048
#define ON_RSP_QRY_PRODUCT_EXCH_RATE 1049
#define ON_RSP_QRY_PRODUCT_GROUP 1050
#define ON_RSP_QRY_MM_INSTRUMENT_COMMISSION_RATE 1051
#define ON_RSP_QRY_MM_OPTION_INSTR_COMM_RATE 1052
#define ON_RSP_QRY_INSTRUMENT_ORDER_COMM_RATE 1053
#define ON_RSP_QRY_OPTION_INSTR_TRADE_COST 1054
#define ON_RSP_QRY_OPTION_INSTR_COMM_RATE 1055
#define ON_RSP_QRY_EXEC_ORDER 1056
#define ON_RSP_QRY_FOR_QUOTE 1057
#define ON_RSP_QRY_QUOTE 1058
#define ON_RSP_QRY_COMB_INSTRUMENT_GUARD 1059
#define ON_RSP_QRY_COMB_ACTION 1060
#define ON_RSP_QRY_TRANSFER_SERIAL 1061
#define ON_RSP_QRY_ACCOUNTREGISTER 1062
#define ON_RSP_ERROR 1063
#define ON_RTN_ORDER 1064
#define ON_RTN_TRADE 1065
#define ON_ERR_RTN_ORDER_INSERT 1066
#define ON_ERR_RTN_ORDER_ACTION 1067
#define ON_RTN_INSTRUMENT_STATUS 1068
#define ON_RTN_BULLETIN 1069
#define ON_RTN_TRADING_NOTICE 1070
#define ON_RTN_ERROR_CONDITIONAL_ORDER 1071
#define ON_RTN_EXEC_ORDER 1072
#define ON_ERR_RTN_EXEC_ORDER_INSERT 1073
#define ON_ERR_RTN_EXEC_ORDER_ACTION 1074
#define ON_ERR_RTN_FOR_QUOTE_INSERT 1075
#define ON_RTN_QUOTE 1076
#define ON_ERR_RTN_QUOTE_INSERT 1077
#define ON_ERR_RTN_QUOTE_ACTION 1078
#define ON_RTN_FOR_QUOTE_RSP 1079
#define ON_RTN_CFMMC_TRADING_ACCOUNT_TOKEN 1080
#define ON_ERR_RTN_BATCH_ORDER_ACTION 1081
#define ON_RTN_COMB_ACTION 1082
#define ON_ERR_RTN_COMB_ACTION_INSERT 1083
#define ON_RSP_QRY_CONTRACT_BANK 1084
#define ON_RSP_QRY_PARKED_ORDER 1085
#define ON_RSP_QRY_PARKED_ORDER_ACTION 1086
#define ON_RSP_QRY_TRADING_NOTICE 1087
#define ON_RSP_QRY_BROKER_TRADING_PARAMS 1088
#define ON_RSP_QRY_BROKER_TRADING_ALGOS 1089
#define ON_RSP_QUERY_CFMMC_TRADING_ACCOUNT_TOKEN 1090
#define ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK 1091
#define ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK 1092
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK 1093
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK 1094
#define ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE 1095
#define ON_RTN_FROM_FUTURE_TO_BANK_BY_FUTURE 1096
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL 1097
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL 1098
#define ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE 1099
#define ON_ERR_RTN_BANK_TO_FUTURE_BY_FUTURE 1100
#define ON_ERR_RTN_FUTURE_TO_BANK_BY_FUTURE 1101
#define ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL 1102
#define ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL 1103
#define ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE 1104
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE 1105
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE 1106
#define ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE 1107
#define ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE 1108
#define ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE 1109
#define ON_RTN_OPEN_ACCOUNT_BY_BANK 1110
#define ON_RTN_CANCEL_ACCOUNT_BY_BANK 1111
#define ON_RTN_CHANGE_ACCOUNT_BY_BANK 1112
#define ON_RSP_SUB_MARKET_DATA 1113
#define ON_RSP_UN_SUB_MARKET_DATA 1114
#define ON_RSP_SUB_FOR_QUOTE_RSP 1115
#define ON_RSP_UN_SUB_FOR_QUOTE_RSP 1116
#define ON_RTN_DEPTH_MARKET_DATA 1117



///// 自定义状态
#define STATUS_SUCCESS 0
#define WRONG_VALUE_TYPE 10001 // 错误的数据类型
#define NONE_TRADER_API_FUNC 10002 // 没有对应的traderApi函数

#define round(x) (x - floor(x) >= 0.5 ? floor(x) + 1 : floor(x)) //四舍五入宏定义

#define TD_EVENT_CALL(FIELD, EVENT_ID, ERR_CODE) \
  do { \
    FIELD->trader    = this; \
    FIELD->errCode   = ERR_CODE; \
    FIELD->eventId   = EVENT_ID; \
    req->data        = FIELD; \
    uv_queue_work(uv_default_loop(), req, AsyncFn, (uv_after_work_cb)AsyncAfterFn); \
  } while (0);

#define MD_EVENT_CALL(FIELD, EVENT_ID, ERR_CODE) \
  do { \
    FIELD->mduser    = this; \
    FIELD->errCode   = ERR_CODE; \
    FIELD->eventId   = EVENT_ID; \
    req->data        = FIELD; \
    uv_queue_work(uv_default_loop(), req, AsyncFn, (uv_after_work_cb)AsyncAfterFn); \
  } while (0);

#define TD_DEBUG_LOG(LOG_STR) \
  if (Trader::isDebug) { \
    std::cout << "[DEBUG in C++]: " << LOG_STR << std::endl; \
  }

#define MD_DEBUG_LOG(LOG_STR) \
  if (Mduser::isDebug) { \
    std::cout << "[DEBUG in C++]: " << LOG_STR << std::endl; \
  }

#define TD_EVENT_FUNC(FUNC_NAME, EVENT_ID, ERR_CODE) \
  do { \
    if (Trader::isDebug) { \
      std::cout << "[DEBUG in C++]: " << FUNC_NAME << " called." << std::endl; \
    } \
    TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField)); \
    uv_work_t *req   = new uv_work_t; \
    field->trader    = this; \
    field->errCode   = ERR_CODE; \
    field->eventId   = EVENT_ID; \
    req->data        = field; \
    uv_queue_work(uv_default_loop(), req, AsyncFn, (uv_after_work_cb)AsyncAfterFn); \
  } while (0);

#define MD_EVENT_FUNC(FUNC_NAME, EVENT_ID, ERR_CODE) \
  do { \
    if (Mduser::isDebug) { \
      std::cout << "[DEBUG in C++]: " << FUNC_NAME << " called." << std::endl; \
    } \
    MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField)); \
    uv_work_t *req   = new uv_work_t; \
    field->mduser    = this; \
    field->errCode   = ERR_CODE; \
    field->eventId   = EVENT_ID; \
    req->data        = field; \
    uv_queue_work(uv_default_loop(), req, AsyncFn, (uv_after_work_cb)AsyncAfterFn); \
  } while (0);

#define SET_PROPERTY_STRING(ENV, OBJ, KEY, STR) \
  OBJ.Set(KEY, Napi::String::New(ENV, (const char *)STR));

#define SET_PROPERTY_CHAR(ENV, OBJ, KEY, STR) \
  do { \
    std::string s(1, STR); \
    OBJ.Set(KEY, Napi::String::New(ENV, s.c_str())); \
  } while (0);

#define SET_PROPERTY_NUMBER(ENV, OBJ, KEY, NUMBER) \
  do { \
    if (NUMBER == DBL_MAX) { \
      OBJ.Set(KEY, Napi::Number::New(ENV, 0)); \
    } else { \
      OBJ.Set(KEY, Napi::Number::New(ENV, NUMBER)); \
    } \
  } while (0);

#define SET_PROPERTY_BUFFER(ENV, OBJ, KEY, STR) \
  OBJ.Set(KEY, Napi::Buffer<char>::New(ENV, STR, strlen(STR)));

#endif