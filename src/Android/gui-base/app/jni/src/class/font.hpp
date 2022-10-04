#pragma once
#ifdef __GNUC__
#ifdef __linux__
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_mixer.h>
#endif
#ifdef __ANDROID__
#include <SDL.h>
#include <SDL_ttf.h>
//#include <SDL_image.h>
//#include <SDL_mixer.h>
#endif
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
	// fontの読み込み
	font_load(std::string path, int font_size);
	// fontの廃棄
	~font_load();
private:
	SDL_Surface* text_surface;
	SDL_Texture* texture;

};
