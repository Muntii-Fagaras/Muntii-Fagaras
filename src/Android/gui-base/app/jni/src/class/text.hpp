#pragma once
#ifdef __GNUC__
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_ttf.h>
#endif
#ifdef _MSC_VER
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#endif

#include <iostream>
#include "load_file.hpp"

class text:public load_file{
	public:
		TTF_Font* font;
		SDL_Rect rect{
		rect.x = 520,
		rect.y = 260,
		rect.w = 0,
		rect.h = 0
	};
		void load(std::string path,int font_size);
		SDL_Texture* draw(SDL_Renderer* renderer,TTF_Font* font,std::string text,int x,int y);
	private:
};
