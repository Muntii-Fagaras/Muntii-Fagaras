#include "MuntiiFagaras.hpp"

MuntiiFagaras::MuntiiFagaras(SDL_Window* window, SDL_Renderer* renderer)
{
	this->window   = window;
	this->renderer = renderer;

	windowID = SDL_GetWindowID(window);

	mainScreen = new MainScreen(window, windowID, &event, renderer,
								SDL_Color{50, 50, 0, 255}, &tasks);
	manageTexts = new ManageTexts(&tasks);
}

MuntiiFagaras::~MuntiiFagaras()
{
	delete mainScreen;
	delete manageTexts;
}

int MuntiiFagaras::mainloop()
{
	while (true) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) break;
		mainScreen->handleEvent();

		while (!(tasks.empty())) {
			switch (tasks.front()->receiver) {
				case RECEIVER::MAIN_SCREEN :
					mainScreen->runTask();
					break;
				case RECEIVER::MANAGE_TEXTS :
					manageTexts->runTask();
					break;
				case RECEIVER::SUPPORT :
					break;
			}

			delete tasks.front();
			tasks.pop_front();
		}
	}

	return 0;
}