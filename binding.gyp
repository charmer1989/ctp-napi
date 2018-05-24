{
  'targets': [
    {
      'target_name': 'ctp-napi',
      'sources': [
        'ctp.cc',
        'Mduser.h',
        'Mduser.cpp',
        'MduserEvent.cpp',
        'MduserCall.cpp',
        'MduserAsync.cpp',
        'Trader.h',
        'Trader.cpp',
        'TraderEvent.cpp',
        'TraderCall.cpp',
        'TraderAsync.cpp',
        'Struct.h',
        'SafeQueue.h'
      ],
      "libraries": [
        "../thosttraderapi.so", "../thostmduserapi.so"
      ],
      'include_dirs': ["./tradeapi/", "<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'defines': [ 'NAPI_CPP_EXCEPTIONS' ],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      },
      'xcode_settings': {
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7',
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
      },
    }
  ]
}