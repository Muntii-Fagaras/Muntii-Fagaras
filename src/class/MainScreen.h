#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif

class MainScreen {   
   private:
	// ウィンドウ
	SDL_Window *window = nullptr;
	// イベント
	SDL_Event event;
	// レンダラー
	SDL_Renderer *renderer;
   public:
	MainScreen(SDL_Window *window, SDL_Renderer *renderer);
	~MainScreen();
	int run();
};
