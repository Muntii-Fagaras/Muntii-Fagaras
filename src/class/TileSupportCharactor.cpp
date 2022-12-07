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
	// 描画領域をタイルの領域にする
	SDL_RenderSetViewport(renderer, &area);
	// タイルの背景色
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	// タイルを塗りつぶす
	SDL_RenderFillRect(renderer, NULL);

	// 画面に反映させる
	SDL_RenderPresent(renderer);

	SDL_Delay(10);

	return 0;
}