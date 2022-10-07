/**
 * 由于头文件包含可以嵌套，那么C文件就有可能包含多次同一个头文件，就可能出现重复定义的问题的。
   通过条件编译开关来避免重复包含（重复定义）
   #ifndef __headerfileXXX__
    #define __headerfileXXX__
    …
    文件内容
    …
    #endif
 *
 */
#ifndef LOADER_H
#define LOADER_H

#include <fcntl.h>
#include <unistd.h>

#include <vector>

#include "include/common.h"
#include "util.h"
using namespace v8;
using namespace Be::Util;

namespace Be {
namespace Loader {
void Compile(V8_ARGS);
void Init(Isolate* isolate, Local<Object> target);
}  // namespace Loader
}  // namespace Be
#endif
