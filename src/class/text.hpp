#pragma once
#ifdef __ANDROID__
	#include "stdafx.h"
#endif
#include "font.hpp"

class text : public load_file {
   public:
	// テキストの描画位置
	SDL_Rect rect{rect.x = 520, rect.y = 260, rect.w = 0, rect.h = 0};
	// テキストテクスチャ
	SDL_Texture* texture = nullptr;
	text(SDL_Renderer* renderer, TTF_Font* font, std::string text_show, int x,
		 int y);
	~text();

   private:
	// テキストサーフェス
	SDL_Surface* text_surface = nullptr;
};