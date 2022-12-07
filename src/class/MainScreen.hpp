#pragma once
#include <list>
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "TileSupportCharactor.hpp"

class MainScreen {
   private:
	// �E�B���h�E
	SDL_Window *window = nullptr;
	// �C�x���g
	SDL_Event event;
	// �����_���[
	SDL_Renderer *renderer;
	// �^�C���̃��X�g
	std::list<Tile *> tiles;
	// �w�i�F
	Color bgColor;
   public:
	MainScreen(SDL_Window *window, SDL_Renderer *renderer, Color bgColor);
	~MainScreen();
	int mainRoop();
};
