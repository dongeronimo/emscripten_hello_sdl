#Hello SDL
The next step is to see something of the SDL library on screen.

## Testing if I am compiling in an emscripten environment
The flag ```__EMSCRIPTEN__``` says if I am under emscripten or not. Example:
```
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
```
