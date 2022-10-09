#pragma once
#include "image.hpp"

void image::load(std::string image_path, SDL_Renderer* renderer, int x, int y)
{
	image_surface = IMG_Load(image_path.c_str());
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