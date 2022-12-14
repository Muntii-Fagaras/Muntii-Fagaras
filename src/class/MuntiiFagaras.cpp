#include "MuntiiFagaras.hpp"

MuntiiFagaras::MuntiiFagaras(SDL_Window* window, SDL_Renderer* renderer)
{
	this->window   = window;
	this->renderer = renderer;

	windowID = SDL_GetWindowID(window);

	mainScreen =
		new MainScreen(window, windowID, &event, renderer, SDL_Color{50, 50, 0, 255});
}

MuntiiFagaras::~MuntiiFagaras() { delete mainScreen; }

int MuntiiFagaras::mainloop()
{
	while (1) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

		mainScreen->handleEvent();
	}

	SDL_Quit();
	return 0;
}