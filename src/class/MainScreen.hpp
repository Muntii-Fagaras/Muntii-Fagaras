#pragma once
#include <list>
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "TileSupportCharactor.hpp"

class MainScreen {
   private:
	// ウィンドウ
	SDL_Window *window = nullptr;
	// イベント
	SDL_Event event;
	// レンダラー
	SDL_Renderer *renderer;
	// タイルのリスト
	std::list<Tile *> tiles;
	// 背景色
	Color bgColor;
   public:
	MainScreen(SDL_Window *window, SDL_Renderer *renderer, Color bgColor);
	~MainScreen();
	int mainRoop();
};
