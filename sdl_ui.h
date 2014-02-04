#ifndef SDL_UI
#define SDL_UI

#include "sdl_class.h"
#include "drawer.h"

#include <vector>

const color pressed_button_color = {255, 255, 255, 255};
const color button_color = {255, 0, 0, 255};

const color popup_color = {255, 255, 100, 255};

// A base class for all entities (popups, buttons etc)
class entity {
	public:
      string name;

	 	entity(int x, int y);
		virtual void draw(Drawer *pDrawer) = 0;
	protected:
		SDL_Rect offset;
		bool inRect(int x, int y) const;
};

class sdl_ui : public sdl { // THIS LIBRARY NEEDS A STATE MANAGER
                            // www.sdltutorials.com/sdl-app-states
   private:
      Drawer *pDrawer;
      vector<entity*> entities; // all the entities that should be drawn
   public:
      sdl_ui(int width, int height, int bpp);
      ~sdl_ui();

      void createButton(int x, int y); 
      void createPopup(int x, int y);
      void update();
};

// A picture class for all kinds of bitmaps
/*class picture : public entity {

	private:
		SDL_Surface *pic;
	public:
		picture(int x, int y, string filename);
		~picture();

		void draw(Drawer *pDrawer);

		static entity* generatePicture(int x, int y, string filename);
};*/

// A popup window where you can place buttons, text, pictures etc.
class popup : public entity {
	
	private: // private variables
		color colors;
      vector<entity*> entities; // all the popup-window's entities that should be drawn
	public: // public functions
		popup(int x, int y, color popup_color);
		~popup();

		void draw(Drawer *pDrawer);

      // Name: addEntity
      // Parameters: entity pointer
      // Returns: success/failure
      bool addEntity(entity *tmp);

		// Name: generatePopup
		// Parameters: (x, y) coordinates and color
		// Returns: an entity pointer to a popup
		static entity* generatePopup(int x, int y, color popup_color);

};

// A button with a text
class button : public entity {
	
	private:

	public:
		button(int x, int y);
		~button();

		void draw(Drawer *pDrawer);

		// Name: generateButton
		// Parameters: (x, y) coordinates
		// Returns: an entity pointer to a button
		static entity* generateButton(int x, int y);

};

#endif
