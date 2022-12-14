#pragma once
#include <map>
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "Tile/TileEditSpace.hpp"
#include "Tile/TileSupportCharactor.hpp"

class MainScreen {
   private:
	// ウィンドウ
	SDL_Window *window = nullptr;
	Uint32		windowID;
	// イベント
	SDL_Event *eventPtr;
	// レンダラー
	SDL_Renderer *renderer;
	// タイルのマップ
	std::map<const char *, Tile *> tiles;
	// 背景色
	SDL_Color bgColor;

	void putTiles();
	void putTiles(int winW, int winH);

   public:
	MainScreen(SDL_Window *window, Uint32 windowID, SDL_Event *eventPtr,
			   SDL_Renderer *renderer, SDL_Color bgColor);
	~MainScreen();

	void handleEvent();
};
