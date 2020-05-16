#include <iostream>
#include <SDL/SDL.h>
//#ifdef __EMSCRIPTEN__
#include <emscripten.h>
//#endif

SDL_Surface *CreateSurface(unsigned int width, unsigned int height){
    SDL_Surface  *screen = SDL_SetVideoMode(width,height, 32, SDL_SWSURFACE);
    return screen;
}

void LockSurfaceIfNeeded(SDL_Surface* surface){
    if (SDL_MUSTLOCK(surface)) {
        SDL_LockSurface(surface);
    }
}
void DrawSomething(SDL_Surface* surface){
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            int alpha = (i+j) % 255;
            *((Uint32*)surface->pixels + i * 256 + j) = SDL_MapRGBA(surface->format, i, j, 255-i, alpha);
        }
    }
}
void UnlockSurfaceIfNeeded(SDL_Surface* surface){
    if (SDL_MUSTLOCK(surface)) {
        SDL_UnlockSurface(surface);
    }
}

int main(int argc, char** argv){
    std::cout<<"Hello world"<<std::endl;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface  *screen = CreateSurface(256, 256);
    LockSurfaceIfNeeded(screen);
    DrawSomething(screen);
    UnlockSurfaceIfNeeded(screen);
    SDL_Flip(screen);
    SDL_Quit();
    return 0;
}