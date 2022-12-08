#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif

struct MuntiiColor
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
};

class Tile {
   protected:
	SDL_Window	 *window;
	SDL_Renderer *renderer;
	SDL_Rect	  area;

	MuntiiColor baseColor = {0, 0, 0, 0};

   public:
	Tile(SDL_Window *window, SDL_Renderer *renderer);
	virtual ~Tile();
	void		 setArea(SDL_Rect area);
	virtual void setBackgroundColor(MuntiiColor color);
	virtual int	 handleEvent(SDL_Event *event);
};
