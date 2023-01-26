#include "Tile.hpp"

#include "../image.hpp"

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
void Tile::put_withimg(SDL_Rect area)
{
	// 画像を読み込む
	std::string tsukuyomi_path = "assets/image/tsukuyomi.png";
	image		s;
	s.load(tsukuyomi_path, renderer, area.x, area.y);
	// 描画位置を決める
	SDL_RenderSetViewport(renderer, &area);

	// 描画する
	SDL_RenderCopy(renderer, s.texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}
void Tile::setBaseColor(SDL_Color color) { baseColor = color; }

bool Tile::selectedByMouse()
{
	SDL_Point mouseCosorPosition =
		SDL_Point{eventPtr->motion.x, eventPtr->motion.y};
	return selectedByMouse(mouseCosorPosition);
}

bool Tile::selectedByMouse(SDL_Point mouseCursorPosition)
{
	return SDL_PointInRect(&mouseCursorPosition, &area);
}

void Tile::handleEventMOUSEMOTION(list<Task *> *tasks) {}
void Tile::handleEventMOUSEBUTTONDOWN(list<Task *> *tasks) {}
void Tile::handleEventMOUSEBUTTONUP(list<Task *> *tasks) {}
void Tile::handleEventMOUSEWHEEL(list<Task *> *tasks) {}