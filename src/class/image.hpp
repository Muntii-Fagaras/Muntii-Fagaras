#pragma once
#include "load_file.hpp"
class image :public load_file {
public:
	// イメージのテクスチャ
	SDL_Texture* texture=nullptr;
	// 画像の位置
	SDL_Rect rect{
		rect.x = 520,
		rect.y = 260,
		rect.w = 0,
		rect.h = 0
	};
	void load(std::string image_path,SDL_Renderer* renderer, int x, int y);

	~image(); 
private:
	// 画像のサーフェス
	SDL_Surface* image_surface= nullptr;
};
