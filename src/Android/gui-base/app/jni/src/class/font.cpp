#pragma once
#include "font.hpp"

font_load::font_load(std::string path, int font_size)
{
	if ((font_load::font = TTF_OpenFont(path.c_str(), font_size)) == NULL) {
		SDL_Quit();
	}
}

font_load::~font_load()
{
	TTF_CloseFont(font);
}
