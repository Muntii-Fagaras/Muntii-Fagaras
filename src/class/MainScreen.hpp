#pragma once
#include <map>
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "Tile/TileEditSpace.hpp"
#include "Tile/TileSupportCharactor.hpp"

class MainScreen {
   private:
	// �E�B���h�E
	SDL_Window *window = nullptr;
	Uint32		windowID;
	// �C�x���g
	SDL_Event *eventPtr;
	// �����_���[
	SDL_Renderer *renderer;
	// �^�C���̃}�b�v
	std::map<const char *, Tile *> tiles;
	// �w�i�F
	SDL_Color bgColor;

	void putTiles();
	void putTiles(int winW, int winH);

   public:
	MainScreen(SDL_Window *window, Uint32 windowID, SDL_Event *eventPtr,
			   SDL_Renderer *renderer, SDL_Color bgColor);
	~MainScreen();

	void handleEvent();
};
