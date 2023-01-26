#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "../Task/TaskMainScreen.hpp"
#include "../Task/TaskManageTexts.hpp"

class Tile {
   protected:
	SDL_Window	 *window;
	SDL_Event	 *eventPtr;
	SDL_Renderer *renderer;
	SDL_Rect	  area		= SDL_Rect{0, 0, 0, 0};	// ウィンドウに対しての領域
	SDL_Color	  baseColor = SDL_Color{0, 0, 0, 0};

   public:
	Tile(SDL_Window *window, SDL_Event *eventPtr, SDL_Renderer *renderer);
	virtual ~Tile();
	virtual void put(SDL_Rect area);
	virtual void setBaseColor(SDL_Color color);
	virtual bool selectedByMouse();
	virtual bool selectedByMouse(SDL_Point mouseCorsorPosition);

	// イベント処理
	virtual void handleEventMOUSEMOTION(list<Task *> *tasks);
	virtual void handleEventMOUSEBUTTONDOWN(list<Task *> *tasks);
	virtual void handleEventMOUSEBUTTONUP(list<Task *> *tasks);
	virtual void handleEventMOUSEWHEEL(list<Task *> *tasks);
};
