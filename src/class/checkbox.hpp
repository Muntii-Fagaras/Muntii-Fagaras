#pragma once

#include "button.hpp"
class checkbox : public button {
   public:
	// 未チェック
	image uncheck;
	// チェック済み
	image checked;
	// テクスチャ
	SDL_Texture* texture = nullptr;

	// チェックボックスの状態
	bool checkbox_state = false;
	checkbox(std::vector<std::string> image_path, SDL_Renderer* renderer, int x,
			 int y, bool mouse_state);
	~checkbox();
	void next(bool mouse_state);

   private:
	// チェックボックスのサーフェス
	SDL_Surface* image_surface = nullptr;
};