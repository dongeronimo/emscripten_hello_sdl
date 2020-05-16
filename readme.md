#Hello SDL
The next step is to see something of the SDL library on screen.

##Emscritpten Envoronment

### Toolchain file
Instead of using emcmake/emmake I can use the toolchain file I found. Just remember to 
remove the WASM=0 parameters from the cmake configuration. 

### Testing if I am compiling in an emscripten environment
The flag ```__EMSCRIPTEN__``` says if I am under emscripten or not. Example:
```
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
```

### Seeing the emscripten directories
Using the toolchain file or emcmake is not enough. I must add the include directories to the project using
```include_directories("~/emsdk/emscripten/1.38.30/system/include")``` or the symbols won't be there in the world
of c++
