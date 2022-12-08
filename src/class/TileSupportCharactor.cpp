#include "TileSupportCharactor.hpp"

TileSupportCharactor::TileSupportCharactor(SDL_Window	*window,
										   SDL_Renderer *renderer)
	: Tile(window, renderer)
{
	setBackgroundColor({0, 50, 50, 128});
}

TileSupportCharactor::~TileSupportCharactor() {}