#pragma once
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
#include <vector>
#include "image.hpp"

class checkbox :public image {
public:
	// チェックボックスの状態
	bool checkbox_state = true;

	checkbox(std::vector<std::string>image_path, SDL_Renderer* renderer, int x, int y,bool mouse_state);
	~checkbox();
private:
	SDL_Surface* image_surface= nullptr;
	int img_num = 0;
};
