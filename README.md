# Be.js

a JavaScript runtime

# compile V8

[Reference](https://blog.csdn.net/THEANARKH/article/details/117479273)

# how to use

- compile v8(after successfully compiled, copy include/v8 directory from v8 source code)
- replace v8 path in the makefile(-Llib => -L[your path]) or replace libv8_monolith.a
- execute 'make' in the root dir (if success, you can see Be executable file)
- run 'Be ./test/index.js'
