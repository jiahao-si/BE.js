# Be.js

a JavaScript runtime

# V8

[Compile V8](https://blog.csdn.net/THEANARKH/article/details/117479273)

[Compile V8 IN M1 Mac](https://joyeecheung.github.io/blog/2021/08/27/binding-v8-on-an-m1-macbook/)


[V8 API Design Doc](include/v8/APIDesign.md)

# how to use

- compile v8(after successfully compiled, copy include/v8 directory from v8 source code)
- replace v8 path in the makefile(-Llib => -L[your path]) or replace libv8_monolith.a
- execute 'make' in the root dir (if success, you can see Be executable file)
- run 'Be ./test/index.js'
