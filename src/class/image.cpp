#pragma once
#include "image.hpp"

image::image(std::vector<std::string>image_path, SDL_Renderer* renderer, int x, int y)
{
	image_surface = IMG_Load(image_path.at(img_num).c_str());
	rect.x = x;
	rect.y = y;
	texture = SDL_CreateTextureFromSurface(renderer, image_surface);
	SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);

}

void image::image_next(std::vector<std::string>image_path, SDL_Renderer* renderer, int x, int y)
{
	img_num++;

	try {
		image_surface = IMG_Load(image_path.at(img_num).c_str());
	}
	catch (const std::out_of_range& oor) {
		img_num = 0;
		image_surface = IMG_Load(image_path.at(img_num).c_str());

	}
	rect.x = x;
	rect.y = y;
	texture = SDL_CreateTextureFromSurface(renderer, image_surface);
	SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
}

image::~image()
{
	SDL_FreeSurface(image_surface);
	SDL_DestroyTexture(texture);
	texture = nullptr;	//とりあえずnullptrを入れとく
}
