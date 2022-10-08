#pragma once
#include "checkbox.hpp"
#include "mouse.hpp"
checkbox::checkbox(std::vector<std::string> image_path, SDL_Renderer* renderer, int x, int y,bool mouse_state)
{
checkbox_state = mouse_state;
	load(image_path.at(checkbox_state), renderer, x, y);

}

checkbox::~checkbox()
{
	SDL_FreeSurface(image_surface);
	SDL_DestroyTexture(texture);
	texture = nullptr;	//とりあえずnullptrを入れとく
}
