#include "drawer.h"

#include <iostream>

Drawer::Drawer(SDL_Surface* target) {
   target_ = target;
   if(target_ == NULL) {
      cout << "GOT NOTHING HERE" << endl;
   }
}

void Drawer::testi() {
   cout << "TOIMIIKO" << endl;
   cout << (target_)->w << endl;
}

void Drawer::apply_box(SDL_Rect offset, color popup_color) {
   cout << "applying a box" << endl;
   cout << (target_)->w << endl;
   boxRGBA(target_, offset.x, offset.y, offset.x+offset.w, offset.y+offset.h,
         popup_color.r, popup_color.g, popup_color.b, popup_color.unused);
}

void Drawer::apply_surface(int x, int y, SDL_Surface *source) {
   SDL_Rect offset;
   offset.x = x;
   offset.y = y;
   SDL_BlitSurface(source, NULL, target_, &offset);
}

void Drawer::update() {
   SDL_Flip(target_);
}

Drawer::~Drawer() {
   SDL_FreeSurface(target_);
}
