#include "sdl_class.h"

#include <iostream>

sdl::sdl() {
   cout << "sdl created" << endl;
}

bool sdl::init(int width, int height, int bpp, string caption) {

   if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
     fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
     return false;
   }

   screenrect.w = width;
   screenrect.h = height;
   
   screen = SDL_SetVideoMode(screenrect.w, screenrect.h, bpp, SDL_SWSURFACE);

   if(screen == NULL) {
      fprintf(stderr, "Screen could not be initialized.\n");
      return false;
   }

   SDL_WM_SetCaption(caption.c_str(), NULL);

   if(TTF_Init() != 0) {
      fprintf(stderr, "TTF_Init() failed!\n");
      return false;
   }

   return true;
}

sdl::~sdl() {
   TTF_Quit();
   SDL_Quit();
}
