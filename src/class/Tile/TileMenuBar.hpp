#pragma onse
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "../Control/ControlButton.hpp"
#include "Tile.hpp"

class TileMenuBar : public Tile {
   private:
	ControlButton *buttonSave;
	void		   putControls();

   public:
	TileMenuBar(SDL_Window *window, SDL_Event *eventPtr, SDL_Renderer *renderer);
	~TileMenuBar();
};