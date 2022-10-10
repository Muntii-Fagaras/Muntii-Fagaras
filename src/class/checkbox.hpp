#pragma once
#ifdef __ANDROID__
#include "stdafx.h"
#endif
#include "image.hpp"

class checkbox :public image {
public:
	image uncheck;
	image checked;
	SDL_Texture* texture = nullptr;

	// チェックボックスの状態
	bool checkbox_state = false;
	checkbox(std::vector<std::string>image_path, SDL_Renderer* renderer, int x, int y,bool mouse_state);
	~checkbox();
	void next( bool mouse_state);
private:
	// チェックボックスのサーフェス
	SDL_Surface* image_surface= nullptr;
};
