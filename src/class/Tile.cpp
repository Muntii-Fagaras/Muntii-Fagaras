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
}

void Tile::setBackgroundColor(MuntiiColor color) {
	baseColor = color;
}

int Tile::handleEvent(SDL_Event *event) { return 0; }