#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif

class MainScreen {   
   private:
	// �E�B���h�E
	SDL_Window *window = nullptr;
	// �C�x���g
	SDL_Event event;
	// �����_���[
	SDL_Renderer *renderer;
   public:
	MainScreen(SDL_Window *window, SDL_Renderer *renderer);
	~MainScreen();
	int run();
};
