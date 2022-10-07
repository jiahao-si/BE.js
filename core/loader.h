#ifndef LOADER_H
#define LOADER_H

#include "include/common.h"
#include "util.h"
#include <vector>
#include <unistd.h>
#include <fcntl.h>
using namespace v8;
using namespace Be::Util;

namespace Be {
    namespace Loader {
        void Compile(V8_ARGS);
        void Init(Isolate* isolate, Local<Object> target);
    }
}
#endif 
