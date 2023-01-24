#pragma once
#include <map>
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "Task/TaskMainScreen.hpp"
#include "Task/TaskManageTexts.hpp"
#include "Tile/TileEditSpace.hpp"
#include "Tile/TileMenuBar.hpp"
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
	// タスク
	list<Task> &tasks;
	// タイルのマップ
	std::map<const char *, Tile *> tiles;
	// 背景色
	SDL_Color bgColor;
	// 現在、文字の入力を受けつけているタイル
	Tile *tileAcceptingTyping;
	// 現在のマウスカーソルの位置
	SDL_Point mouseCursorPosition;

	void putTiles();
	void putTiles(int winW, int winH);

   public:
	MainScreen(SDL_Window *window, Uint32 windowID, SDL_Event *eventPtr,
			   SDL_Renderer *renderer, SDL_Color bgColor, list<Task> &tasks);
	~MainScreen();

	void handleEvent();
	void runTask();
};
