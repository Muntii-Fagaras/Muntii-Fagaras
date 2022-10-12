#pragma once
#include "text.hpp"

text::text(SDL_Renderer* renderer,TTF_Font* font,std::string text_show,int x,int y){
	text_surface=TTF_RenderUTF8_Blended(font, text_show.c_str(), SDL_Color{ 0,216, 222, 233 });
	// テキストファイルの生成失敗
	if (text_surface == NULL) {
		std::cout << SDL_GetError();
		SDL_Quit();
		exit(1);
	}
	// フォントのx座標とy座標
	rect.x=x;
	rect.y=y;
	// テクスチャを生成する
	texture=SDL_CreateTextureFromSurface(renderer,text_surface);
	// フォントのサイズを取得する
	SDL_QueryTexture(texture, nullptr, nullptr,&rect.w,&rect.h);
}

text::~text()
{
	// テクスチャの解放
	SDL_DestroyTexture(texture);
	// サーフェスの解放
	SDL_FreeSurface(text_surface);
	texture = nullptr;	//とりあえずnullptrを入れとく
}
