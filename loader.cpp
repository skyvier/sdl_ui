#include "loader.h"

SDL_Surface *Loader::load_image(string filename) {

    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;

    loadedImage = IMG_Load(filename.c_str());

    if(loadedImage != NULL) {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
    } else {
        fprintf(stderr, "Couldn't load one of the images.\n");
    }

    return optimizedImage;
}

bool Loader::load_font(string fontname, int fontsize) {
   font = TTF_OpenFont(fontname.c_str(), fontsize);

   if(font == NULL) {
      fprintf(stderr, "TTF_OpenFont() failed!\n");
      return false;
   }

   return true;
}


SDL_Surface *Loader::load_text(string text, color tcolor) {
   SDL_Surface *textImg = NULL;
   SDL_Surface *optImg = NULL;

   SDL_Color text_color = {tcolor.r, tcolor.g, tcolor.b};
   textImg = TTF_RenderText_Solid(font, text.c_str(), text_color);

   if(textImg != NULL) {
      optImg = SDL_DisplayFormat(textImg);
      SDL_FreeSurface(textImg);
   } else {
      fprintf(stderr, "Couldn't load one of the texts.\n");
   }

   return optImg;
}
