#include "Tile.hpp"

Tile::Tile(SDL_Window *window, SDL_Renderer *renderer)
{
	this->window   = window;
	this->renderer = renderer;
}

Tile::~Tile() {}

void Tile::setArea(SDL_Rect area)
{
	this->area = area;
}

void Tile::setBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	baseColor = {r, g, b, a};
}

int Tile::run()
{
	return 0;
}

int Tile::handleEvent(SDL_Event *event) { return 0; }