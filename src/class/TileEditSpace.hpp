#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "Tile.hpp"

class TileEditSpace : public Tile {
   private:
   public:
	TileEditSpace(SDL_Window *window, SDL_Renderer *renderer);
	~TileEditSpace();
};
