#ifndef LOADER_H
#define LOADER_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_gfxPrimitives.h>

#include <string>

using namespace std;

typedef SDL_Color color;

class Loader {
   private:
      TTF_Font *font;
   public:
      SDL_Surface *load_image(string filename); // this might not be needed tbh
      SDL_Surface *load_text(string text, color tcolor); 
      bool load_font(string fontname, int fontsize);
};

#endif
