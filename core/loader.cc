#include "loader.h"      

void Be::Loader::Compile(V8_ARGS) {
    V8_ISOLATE
    V8_CONTEXT
    String::Utf8Value filename(isolate, args[0].As<String>());
    int fd = open(*filename, 0 , O_RDONLY);
    std::string content;
    char buffer[4096];
    while (1)
    {
      memset(buffer, 0, 4096);
      int ret = read(fd, buffer, 4096);
      if (ret == -1) {
        return args.GetReturnValue().Set(newStringToLcal(isolate, "read file error"));
      }
      if (ret == 0) {
        break;
      }
      content.append(buffer, ret);
    }
    close(fd);
    ScriptCompiler::Source script_source(newStringToLcal(isolate, content.c_str()));
    Local<String> params[] = {
      newStringToLcal(isolate, "require"),
      newStringToLcal(isolate, "exports"),
      newStringToLcal(isolate, "module"),
    };
    MaybeLocal<Function> fun =
    ScriptCompiler::CompileFunction(context, &script_source, 3, params, 0, nullptr);
    if (fun.IsEmpty()) {
      args.GetReturnValue().Set(Undefined(isolate));
    } else {
      args.GetReturnValue().Set(fun.ToLocalChecked());
    }
}

void Be::Loader::Init(Isolate* isolate, Local<Object> target) {
  // 创建 loader V8对象模板(对象模板中的属性都会添加进通过 loader 对象模板创建的对象实例中)
  Local<ObjectTemplate> loader = ObjectTemplate::New(isolate);
  // 设置 loader 对象的 compile 方法
  setMethod(isolate, loader, "compile", Be::Loader::Compile);
  // 使用 loader 对象模板创建对象实例， 并注入到 target ，也就是 Be
  setObjectValue(isolate, target, "loader", loader->NewInstance(isolate->GetCurrentContext()).ToLocalChecked());
}
