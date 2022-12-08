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

	// •`‰æ—Ìˆæ‚ğƒ^ƒCƒ‹‚Ì—Ìˆæ‚É‚·‚é
	SDL_RenderSetViewport(renderer, &area);
	// ƒ^ƒCƒ‹‚Ì”wŒiF
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	// ƒ^ƒCƒ‹‚ğ“h‚è‚Â‚Ô‚·
	SDL_RenderFillRect(renderer, NULL);

	// ‰æ–Ê‚É”½‰f‚³‚¹‚é
	SDL_RenderPresent(renderer);

	SDL_Delay(10);
}

void Tile::setBackgroundColor(MuntiiColor color) {
	baseColor = color;
}

int Tile::handleEvent(SDL_Event *event) { return 0; }