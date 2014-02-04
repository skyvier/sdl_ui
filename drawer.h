#ifndef DRAWER_H
#define DRAWER_H

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>

#include <string>

using namespace std;

typedef SDL_Color color;

class Drawer {
   private:
      SDL_Surface *target_;
   public: 
      Drawer(SDL_Surface* target);
      ~Drawer();

      void testi();

      // surface application functions:
      void apply_surface(int x, int y, SDL_Surface *source);
      void apply_box(SDL_Rect offset, color popup_color);
      // void apply_text(int x, int y, string text, color tcolor); TODO Not yet implemented

      void update();
};

#endif
