#include "Tile.hpp"

Tile::Tile(SDL_Window *window, SDL_Event *eventPtr, SDL_Renderer *renderer)
{
	this->window   = window;
	this->eventPtr = eventPtr;
	this->renderer = renderer;
}

Tile::~Tile() {}

void Tile::put(SDL_Rect area)
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
}

void Tile::setBaseColor(SDL_Color color) { baseColor = color; }

int Tile::handleEvent() { return 0; }