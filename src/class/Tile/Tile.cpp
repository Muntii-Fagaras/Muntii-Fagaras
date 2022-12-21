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

	// 描画領域をタイルの領域にする
	SDL_RenderSetViewport(renderer, &area);
	// タイルの背景色
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	// タイルを塗りつぶす
	SDL_RenderFillRect(renderer, NULL);

	// 画面に反映させる
	SDL_RenderPresent(renderer);
}

void Tile::setBaseColor(SDL_Color color) { baseColor = color; }

int Tile::handleEvent() { return 0; }