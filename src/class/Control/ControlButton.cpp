#include "ControlButton.hpp"

ControlButton::ControlButton(SDL_Window *window, SDL_Renderer *renderer,
							 std::string text, Font *font)
	: Control(window, renderer)
{
	setBaseColor(SDL_Color{255, 255, 255, 255});
	setEdgeColor(SDL_Color{0, 255, 255, 255});
	
	setText(text);
	
	label = new ControlLabel(window, renderer, text, font);
}

ControlButton::~ControlButton(){delete label;};

void ControlButton::setText(std::string text) { this->text = text; }
void ControlButton::setSlctColor(SDL_Color color) { slctColor = color; }

void ControlButton::put(SDL_Rect area)
{
	this->area = area;

	// 描画領域をボタンの領域にする
	SDL_RenderSetViewport(renderer, &area);

	// ボタンの背景
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	SDL_RenderFillRect(renderer, NULL);

	// ボタンのふち
	SDL_SetRenderDrawColor(renderer, edgeColor.r, edgeColor.g, edgeColor.b,
						   edgeColor.a);
	SDL_RenderDrawRect(renderer, NULL);

	SDL_Rect areaText = {
		area.x + area.w / 5,
		area.y + area.h / 5,
		area.w * 3 / 5,
		area.h * 3 / 5
	};

	// テキストを表示
	label->put(areaText);

	// 画面に反映
	SDL_RenderPresent(renderer);
}