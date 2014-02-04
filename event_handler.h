#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL/SDL.h>

// kind of simple for now

class EventHandler {
   private:
      SDL_Event event;
   public:
      bool read_events();
};

#endif
