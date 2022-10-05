#pragma once
#include <iostream>
// GCCの時のコンパイルオプション
#ifdef __GNUC__
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "../SDL2_mixer/SDL_mixer.h"
#endif
class load_file{
	public:
		std::string load(std::string path);
	private:
};
