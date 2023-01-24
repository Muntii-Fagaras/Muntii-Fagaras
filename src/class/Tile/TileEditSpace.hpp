#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "Tile.hpp"
#include "../Task/TaskMainScreen.hpp"
#include "../Control/ControlEditSpace.hpp"

class TileEditSpace : public Tile {
   private:
	Text *text;
	Font *font;
	ControlEditSpace *editSpace;
	void			  putControls();

   public:
	TileEditSpace(SDL_Window *window, SDL_Event *eventPtr, SDL_Renderer *renderer);
	~TileEditSpace();

	void put(SDL_Rect area) override;
	void present(PresentText &task);
};
