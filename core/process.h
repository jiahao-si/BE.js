#ifndef CHILD_PROCESS_H
#define CHILD_PROCESS_H

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>

#include "include/common.h"
#include "util.h"

using namespace v8;
using namespace Be::Util;

namespace Be {
namespace Process {
void Init(Isolate* isolate, Local<Object> target, char** argv, int argc);
}
}  // namespace Be

#endif