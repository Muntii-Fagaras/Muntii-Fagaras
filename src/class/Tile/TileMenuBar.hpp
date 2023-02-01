#pragma once
#ifdef __GNUC__
	#include "../../stdafx.h"
#endif
#include "../Control/ControlButton.hpp"
#include "../voice.hpp"
#include "Tile.hpp"

class TileMenuBar : public Tile {
   private:
	Font		  *font;
	ControlButton *buttonSave;
	void		   putControls();

   public:
	TileMenuBar(SDL_Window *window, SDL_Event *eventPtr,
				SDL_Renderer *renderer);
	~TileMenuBar();
	void put(SDL_Rect area) override;
	void handleEventMOUSEBUTTONDOWN(list<Task *> *tasks) override;
};