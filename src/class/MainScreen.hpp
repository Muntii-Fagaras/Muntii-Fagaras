#pragma once
#include <map>
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "TileEditSpace.hpp"
#include "TileSupportCharactor.hpp"

class MainScreen {
   private:
	// ウィンドウ
	SDL_Window *window = nullptr;
	Uint32		windowID;
	// イベント
	SDL_Event event;
	// レンダラー
	SDL_Renderer *renderer;
	// タイルのマップ
	std::map<const char *, Tile *> tiles;
	// 背景色
	MuntiiColor bgColor;

	void putTiles();
	void putTiles(int winW, int winH);

   public:
	MainScreen(SDL_Window *window, SDL_Renderer *renderer, MuntiiColor bgColor);
	~MainScreen();
	int mainLoop();
};
