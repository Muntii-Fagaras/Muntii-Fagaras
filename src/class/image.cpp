#pragma once
#include "image.hpp"

void image::load(std::string image_path, SDL_Renderer* renderer, int x, int y)
{
	// 画像ファイルの存在確認
	if (chk(image_path)==false) {
		std::cout << SDL_GetError();
		SDL_Quit();
		exit(1);
	}
	// 画像をサーフェスに読み込む
	image_surface = IMG_Load(image_path.c_str());
	// 画像のx座標とy座標の更新
	rect.x = x;
	rect.y = y;
	// テクスチャをサーフェスから作る
	texture = SDL_CreateTextureFromSurface(renderer, image_surface);
	// 画像のサイズを取得する
	SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
}

image::~image()
{
	// 作成したサーフェスをメモリから解放する
	SDL_FreeSurface(image_surface);
	// 作成したテクスチャをメモリから解放する
	SDL_DestroyTexture(texture);
	texture = nullptr;	//とりあえずnullptrを入れとく
}
