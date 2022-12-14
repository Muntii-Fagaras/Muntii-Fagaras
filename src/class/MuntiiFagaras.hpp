#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "MainScreen.hpp"

class MuntiiFagaras {
   private:
	// �E�B���h�E
	SDL_Window *window = nullptr;
	Uint32		windowID;
	// �C�x���g
	SDL_Event event;
	// �����_���[
	SDL_Renderer *renderer;

	MainScreen *mainScreen;

   public:
	MuntiiFagaras(SDL_Window *window, SDL_Renderer *renderer);
	~MuntiiFagaras();
	int mainloop();
};