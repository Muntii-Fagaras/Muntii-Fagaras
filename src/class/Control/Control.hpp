#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif

class Control {
   protected:
	SDL_Window	 *window;
	SDL_Renderer *renderer;
	SDL_Rect	  area		= SDL_Rect{0, 0, 0, 0};
	SDL_Color	  baseColor = SDL_Color{0, 0, 0, 0};
	SDL_Color	  edgeColor = SDL_Color{255, 255, 255, 255};

   public:
	Control(SDL_Window *window, SDL_Renderer *renderer);
	virtual ~Control();
	virtual void put(SDL_Rect area);
	virtual void setBaseColor(SDL_Color color);
	virtual void setEdgeColor(SDL_Color color);
	virtual bool selectedByMouse(SDL_Point mouseCursorPosition);
};