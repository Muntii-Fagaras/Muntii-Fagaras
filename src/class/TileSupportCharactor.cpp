#include "TileSupportCharactor.hpp"

TileSupportCharactor::TileSupportCharactor(SDL_Window	*window,
										   SDL_Renderer *renderer)
	: Tile(window, renderer)
{
	setBackgroundColor(255, 0, 0, 128);
}

TileSupportCharactor::~TileSupportCharactor() {}

int TileSupportCharactor::run()
{
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

	return 0;
}