#pragma once
#ifdef __GNUC__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#endif
#ifdef _MSC_VER
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#endif

#include <iostream>
#include "load_file.hpp"

class font_load :public load_file {
public:
	TTF_Font* font;
	// font‚Ì“Ç‚İ‚İ
	font_load(std::string path, int font_size);
	// font‚Ì”pŠü
	~font_load();
private:
	SDL_Surface* text_surface;
	SDL_Texture* texture;

};
