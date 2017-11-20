{
  'targets': [
    {
      'target_name': 'primeNumber',
      'sources': ['primeNumber.cc', '../prime_number/prime_number.cc'],
      'conditions': [
        [
          'OS=="linux"', 
          {
            "defines": [ "_GNU_SOURCE" ],
            "cflags": [ "-g", "-O2", "-std=c++11", ],
          }
        ],
        [
          'OS=="win"', 
          {
            'libraries': [
              'dbghelp.lib',
              'Netapi32.lib'
            ],
            'dll_files': [
              'dbghelp.dll',
              'Netapi32.dll'
            ],
          }
        ],
        [
          'OS=="mac"’,
          {
            'xcode_settings': {
              'CLANG_CXX_LIBRARY': 'libc++',
              'CLANG_CXX_LANGUAGE_STANDARD':'c++11',
            }
          }
        ],
      ]
    }
  ]
}
