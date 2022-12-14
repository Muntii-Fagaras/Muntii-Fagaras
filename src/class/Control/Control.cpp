#include "Control.hpp"

Control::Control(SDL_Window* window, SDL_Renderer* renderer)
{
	this->window   = window;
	this->renderer = renderer;
}

Control::~Control() {}

// コントロールごとにオーバーライドする
void Control::put(SDL_Rect area)
{
	this->area = area;

	// 描画領域をコントロールの領域にする
	SDL_RenderSetViewport(renderer, &area);
	// コントロールの背景色
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	// コントロールを塗りつぶす
	SDL_RenderFillRect(renderer, NULL);

	// 画面に反映させる
	SDL_RenderPresent(renderer);
}

void Control::setBaseColor(SDL_Color color) { baseColor = color; }

void Control::setEdgeColor(SDL_Color color) { edgeColor = color; }

bool Control::selectedByMouse(SDL_Point mouseCursorPosition)
{
	return SDL_PointInRect(&mouseCursorPosition, &area);
}