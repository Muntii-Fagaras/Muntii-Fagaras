#pragma once
#ifdef __ANDROID__
	#include "stdafx.h"
#endif
#include "image.hpp"

class button : public image {
   public:
	// 未チェック
	image uncheck;
	// チェック済み
	image checked;
	// テクスチャ
	SDL_Texture* texture = nullptr;

	// チェックボックスの状態
	bool checkbox_state = false;
	button();

	button(std::vector<std::string> image_path, SDL_Renderer* renderer, int x,
		   int y, bool mouse_state);
	~button();
	void next(bool mouse_state);

   private:
	// チェックボックスのサーフェス
	SDL_Surface* image_surface = nullptr;
};