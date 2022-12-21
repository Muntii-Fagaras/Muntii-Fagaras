#include "TileSupportCharactor.hpp"

TileSupportCharactor::TileSupportCharactor(SDL_Window	*window,
										   SDL_Event	*eventPtr,
										   SDL_Renderer *renderer)
	: Tile(window, eventPtr, renderer)
{
	setBaseColor(SDL_Color{0, 50, 50, 128});
}

TileSupportCharactor::~TileSupportCharactor() {}