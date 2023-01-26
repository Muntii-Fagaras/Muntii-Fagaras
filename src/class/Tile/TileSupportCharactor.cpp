#include "TileSupportCharactor.hpp"

#include "TileMenuBar.hpp"

TileSupportCharactor::TileSupportCharactor(SDL_Window	*window,
										   SDL_Event	*eventPtr,
										   SDL_Renderer *renderer)
	: Tile(window, eventPtr, renderer)
{
}

TileSupportCharactor::~TileSupportCharactor() {}