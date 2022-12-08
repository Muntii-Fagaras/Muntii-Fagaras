#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "Tile.hpp"

class TileSupportCharactor : public Tile {
   private:
   public:
	TileSupportCharactor(SDL_Window *window, SDL_Renderer *renderer);
	~TileSupportCharactor();
};
