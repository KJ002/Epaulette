project('source', 'cpp',
  version : '1.0',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

executable('main',
           ['./src/main.cpp',
           './src/displaymanager.cpp'],
           install : true,
           link_args : ['-lraylib', '-lGL', '-lm', '-pthread', '-ldl'])
