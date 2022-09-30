#pragma once
#include "text.hpp"

void text::load_file_with_chk(std::string file,int font_size){
	if ((text::font = TTF_OpenFont(file.c_str(),font_size)) == NULL) {
		SDL_Quit();
	}
}
