#pragma once
#include <map>
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "TileEditSpace.hpp"
#include "TileSupportCharactor.hpp"

class MainScreen {
   private:
	// �E�B���h�E
	SDL_Window *window = nullptr;
	Uint32		windowID;
	// �C�x���g
	SDL_Event event;
	// �����_���[
	SDL_Renderer *renderer;
	// �^�C���̃}�b�v
	std::map<const char *, Tile *> tiles;
	// �w�i�F
	MuntiiColor bgColor;

	void putTiles();
	void putTiles(int winW, int winH);

   public:
	MainScreen(SDL_Window *window, SDL_Renderer *renderer, MuntiiColor bgColor);
	~MainScreen();
	int mainLoop();
};
