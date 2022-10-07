run: 
	g++ -g -Iinclude/v8 Be.cc core/*.cc -o Be -lv8_monolith -ldl -L/Users/jiahao.si/project/Node/v8/v8/out.gn/x64.release.sample/obj -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX