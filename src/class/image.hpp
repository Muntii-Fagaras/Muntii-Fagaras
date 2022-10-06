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
#include <vector>
#include "load_file.hpp"

class image :public load_file {
public:
	SDL_Texture* texture=nullptr;
	SDL_Rect rect{
		rect.x = 520,
		rect.y = 260,
		rect.w = 0,
		rect.h = 0
	};
	image(std::vector<std::string>image_path,SDL_Renderer* renderer, int x, int y);
	void image_next(std::vector<std::string>image_path, SDL_Renderer* renderer, int x, int y);
	~image(); 
private:
	SDL_Surface* image_surface= nullptr;
	int img_num = 0;
};
