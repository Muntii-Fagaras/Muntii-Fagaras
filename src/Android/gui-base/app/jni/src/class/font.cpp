#pragma once
#include "font.hpp"

font_load::font_load(std::string font_path, int font_size)
{
	// フォントファイルの存在確認
	if (chk(font_path) == false) {
		std::cout << SDL_GetError();
		SDL_Quit();
		exit(1);
	}
	// フォントをメモリに読み込む
	if ((font_load::font = TTF_OpenFont(font_path.c_str(), font_size)) == nullptr) {
		std::cout << SDL_GetError();
		SDL_Quit();
		exit(1);
	}
}

font_load::~font_load()
{
	// フォントをメモリから解放する
	TTF_CloseFont(font);
}
