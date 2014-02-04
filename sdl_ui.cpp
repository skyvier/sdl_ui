#include "sdl_ui.h"

#include <iostream>

// sdl_ui function definitions
sdl_ui::sdl_ui(int width, int height, int bpp) {
   if(!init(width, height, bpp, "Testtesttest")) {
      fprintf(stderr, "Couldn't initialize SDL!\n");
   } else {
      pDrawer = new Drawer(screen);
      cout << "sdl_ui created" << endl;
   }
}

void sdl_ui::createButton(int x, int y) {
   entity *tmp;
   tmp = button::generateButton(x, y);
   entities.push_back(tmp);
   cout << "button created" << endl;
}

void sdl_ui::createPopup(int x, int y) {
   entity *tmp;
   tmp = popup::generatePopup(x, y, popup_color);
   entities.push_back(tmp);
   cout << "Popup created" << endl;
}

void sdl_ui::update() {
   cout << "updating" << endl;
   for(int i = 0; i < entities.size(); i++) {
      entities.at(i)->draw(pDrawer);
   }

   SDL_Flip(screen);

   cout << "flipping" << endl;
}

sdl_ui::~sdl_ui() {
   delete pDrawer;
   for(int i = 0; i < entities.size(); i++) {
      delete entities.at(i);
   }
   SDL_Quit();
}

// entity function definitions
entity::entity(int x, int y) {
	offset.x = x;
	offset.y = y;
}


bool entity::inRect(int x, int y) const {
	if(x < offset.x || x > offset.x+offset.w) // Two if's just to keep it clearer 
		return false;
	if(y < offset.y || y > offset.y+offset.h)
		return false;

	return true;
}

// picture function definitions
/*picture::picture(int x, int y, string filename) : entity(x, y) {
	pic = load_image(filename);

	offset.w = pic->w;
	offset.h = pic->h;

	cout << "A picture has been created!" << endl;
}

void picture::draw(Drawer *pDrawer) {
	pDrawer->apply_surface(offset.x, offset.y, pic);
}

entity* picture::generatePicture(int x, int y, string filename) {
	entity *pPic = new picture(x, y, filename);
	return pPic;
}

picture::~picture() {
   SDL_FreeSurface(pic);
}*/

// popup function definitions
popup::popup(int x, int y, color popup_color) : entity(x, y)  {
   name = "popup";
	colors = popup_color;

	offset.w = 10;
	offset.h = 10;

	cout << "A popup window has been created!" << endl;
}

bool popup::addEntity(entity *tmp) {
   if(tmp->name != "popup" && inRect(tmp->offset.x, tmp->offset.y)) {
      entities.push_back(tmp);
   }
}

void popup::draw(Drawer *pDrawer) {
	pDrawer->apply_box(offset, colors);
   for(int i = 0; i < entities.size(); i++) {

   }
}	

entity* popup::generatePopup(int x, int y, color popup_color) {
	entity *pPup = new popup(x, y, popup_color);
	return pPup;
}

popup::~popup() {
	
}

// button function definitions
button::button(int x, int y) : entity(x, y) {
   name = "button";

	offset.w = 10;
	offset.h = 10;

	cout << "A button has been created!" << endl;
}

void button::draw(Drawer *pDrawer) {
   cout << "in the draw function" << endl;
	int x, y;
	SDL_GetMouseState(&x, &y);

	if(inRect(x, y)) {
		pDrawer->apply_box(offset, pressed_button_color);
	} else {
		pDrawer->apply_box(offset, button_color);
	}	
   cout << "drawed" << endl;
}

entity* button::generateButton(int x, int y) {
	entity *pButton = new button(x, y);
	return pButton;
}

button::~button() {

}


