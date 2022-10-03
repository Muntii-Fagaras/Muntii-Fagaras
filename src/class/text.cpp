#pragma once
#include "text.hpp"

void text::load(std::string file,int font_size){
	if ((text::font = TTF_OpenFont(file.c_str(),font_size)) == NULL) {
		SDL_Quit();
	}
}

SDL_Texture* text::draw(SDL_Renderer* renderer,TTF_Font* font,std::string text,int x,int y){
	SDL_Surface* text_surface;
	text_surface=TTF_RenderUTF8_Blended(font,text.c_str(), SDL_Color{ 0,120, 120, 120 });
	rect.x=x;
	rect.y=y;
	SDL_Texture* texture;
	texture=SDL_CreateTextureFromSurface(renderer,text_surface);
	SDL_QueryTexture(texture,NULL,NULL,&rect.w,&rect.h);	
	return texture;
}
