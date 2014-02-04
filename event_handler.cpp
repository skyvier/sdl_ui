#include "event_handler.h"

bool EventHandler::read_events() { 
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            return false;
        } else if(event.type == SDL_KEYDOWN) {
         if(event.key.keysym.sym == SDLK_ESCAPE) {
            return false;
         }
      }
    }

    return true;
}
