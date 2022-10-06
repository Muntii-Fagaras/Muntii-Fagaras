#pragma once
// GCCの時のコンパイルオプション
#ifdef __GNUC__
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "../SDL2_mixer/SDL_mixer.h"
#endif
#ifdef _MSC_VER
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#endif

#include <iostream>
#include "font.hpp"

class text:public load_file{
public:
	SDL_Rect rect{
			rect.x = 520,
			rect.y = 260,
			rect.w = 0,
			rect.h = 0
	};
	SDL_Texture* texture;
	text(SDL_Renderer* renderer,TTF_Font* font,std::string text_show,int x,int y);
	~text();
private:
	SDL_Surface* text_surface;
};
