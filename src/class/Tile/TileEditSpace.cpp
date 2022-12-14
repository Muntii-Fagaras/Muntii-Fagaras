#include "TileEditSpace.hpp"

TileEditSpace::TileEditSpace(SDL_Window *window, SDL_Renderer *renderer)
	: Tile(window, renderer)
{
	setBaseColor(SDL_Color{50, 50, 50, 128});
}

TileEditSpace::~TileEditSpace() {}