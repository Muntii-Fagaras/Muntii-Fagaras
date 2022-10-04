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

class voice :public load_file {
public:
	Mix_Chunk* voice_file;
	voice(std::string voice_file_path);
	~voice();
	void play();
private:
	SDL_Surface* text_surface;
};
