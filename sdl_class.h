#ifndef SDL_CLASS_H
#define SDL_CLASS_H

#include "loader.h"
#include "event_handler.h"

class sdl : public Loader, public EventHandler {
   private:
      SDL_Rect screenrect;
   protected:
      sdl();
      ~sdl();

      SDL_Surface *screen;

      bool init(int width, int height, int bpp, string caption); // put all init here
};

#endif
