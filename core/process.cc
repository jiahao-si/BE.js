#include "process.h"

void Be::Process::Init(Isolate* isolate, Local<Object> target, char ** argv, int argc) {
  // V8 当前执行 js 的上下文
  Local<Context> context = isolate->GetCurrentContext();
  Local<ObjectTemplate> process = ObjectTemplate::New(isolate);
  // 当前对象模板的对象实例
  Local<Object> obj = process->NewInstance(isolate->GetCurrentContext()).ToLocalChecked();

  Local<Array> arr = Array::New(isolate, argc);
  for (int i = 0; i < argc; i++) {
      arr->Set(context, Number::New(isolate, i), newStringToLcal(isolate, argv[i]));
  }
  // 设置 process.argv
  setObjectValue(isolate, obj, "argv", arr);
  // 设置 Be 的全局对象属性 process
  setObjectValue(isolate, target, "process", obj);
}