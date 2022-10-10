#pragma once
#include "font.hpp"

font_load::font_load(std::string font_path, int font_size)
{
	// �t�H���g�t�@�C���̑��݊m�F
	if (chk(font_path) == false) {
		std::cout << SDL_GetError();
		SDL_Quit();
		exit(1);
	}
	// �t�H���g���������ɓǂݍ���
	if ((font_load::font = TTF_OpenFont(font_path.c_str(), font_size)) == nullptr) {
		std::cout << SDL_GetError();
		SDL_Quit();
		exit(1);
	}
}

font_load::~font_load()
{
	// �t�H���g������������������
	TTF_CloseFont(font);
}
