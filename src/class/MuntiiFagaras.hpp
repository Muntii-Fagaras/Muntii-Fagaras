#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "MainScreen.hpp"

class MuntiiFagaras {
   private:
	// ウィンドウ
	SDL_Window *window = nullptr;
	Uint32		windowID;
	// イベント
	SDL_Event event;
	// レンダラー
	SDL_Renderer *renderer;

	MainScreen *mainScreen;

   public:
	MuntiiFagaras(SDL_Window *window, SDL_Renderer *renderer);
	~MuntiiFagaras();
	int mainloop();
};