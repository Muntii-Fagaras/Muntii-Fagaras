#pragma once
#ifdef __GNUC__
	#include "../../stdafx.h"
#endif
#include "../Control/ControlButton.hpp"
#include "Tile.hpp"

class TileSupportCharactor : public Tile {
   private:
   public:
	TileSupportCharactor(SDL_Window *window, SDL_Event *eventPtr,
						 SDL_Renderer *renderer);
	~TileSupportCharactor();
};
