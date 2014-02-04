#include "sdl_ui.h"

int main(int argc, char **argv) {
   sdl_ui ui(640, 480, 32);
   ui.createPopup(100, 100);
   ui.createButton(10, 10);
   ui.createButton(30, 30);
   while(ui.read_events()) {
      ui.update();
   }

   return 0;
}
