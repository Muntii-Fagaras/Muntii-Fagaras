#pragma once
#include "image.hpp"

image::image(std::string image_path)
{
	image_surface = IMG_Load(image_path.c_str());
}

void image::create_image(SDL_Renderer* renderer,int x,int y)
{
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
