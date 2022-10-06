#pragma once
#include "text.hpp"

text::text(SDL_Renderer* renderer,TTF_Font* font,std::string text_show,int x,int y){
    text_surface=TTF_RenderUTF8_Blended(font, text_show.c_str(), SDL_Color{ 0,216, 222, 233 });
    rect.x=x;
    rect.y=y;
    texture=SDL_CreateTextureFromSurface(renderer,text_surface);
    SDL_QueryTexture(texture,nullptr,nullptr,&rect.w,&rect.h);
}

text::~text()
{
    // テクスチャの解放
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(text_surface);
    texture = nullptr;	//とりあえずNULLを入れとく
}
