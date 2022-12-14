#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif

class Tile {
   protected:
	SDL_Window	 *window;
	SDL_Renderer *renderer;
	SDL_Rect	  area		= SDL_Rect{0, 0, 0, 0};
	SDL_Color	  baseColor = SDL_Color{0, 0, 0, 0};

   public:
	Tile(SDL_Window *window, SDL_Renderer *renderer);
	virtual ~Tile();
	void		 put(SDL_Rect area);
	virtual void setBaseColor(SDL_Color color);
	virtual int	 handleEvent(SDL_Event *event);
};
