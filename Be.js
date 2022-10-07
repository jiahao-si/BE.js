const { loader, process, console } = Be;
function loaderNativeModule() {
  const modules = [
    {
      module: 'libs/module/index.js',
      name: 'module',
    },
  ];
  Be.libs = {};
  for (let i = 0; i < modules.length; i++) {
    const module = {
      exports: {},
    };
    loader
      .compile(modules[i].module)
      .call(null, loader.compile, module.exports, module);
    Be.libs[modules[i].name] = module.exports;
  }
}

function runMain() {
  Be.libs.module.load(process.argv[1]);
}

loaderNativeModule();
runMain();
