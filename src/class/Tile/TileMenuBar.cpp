#include "TileMenuBar.hpp"

TileMenuBar::TileMenuBar(SDL_Window *window, SDL_Event *eventPtr, SDL_Renderer *renderer)
	: Tile(window, eventPtr, renderer)
{
	setBaseColor(SDL_Color{0, 0, 255, 255});
}

TileMenuBar::~TileMenuBar(){};

void TileMenuBar::putControls() {

}