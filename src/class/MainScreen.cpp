#include "MainScreen.h"

MainScreen::MainScreen(SDL_Window *window, SDL_Renderer *renderer) {
	this->window = window;
	this->renderer = renderer;
}

MainScreen::~MainScreen() {

}

int MainScreen::run() {
	// ���C�����[�v
	while (1) {
		// �w�i���N���A
		SDL_RenderClear(renderer);

		// �C�x���g������
		while (SDL_PollEvent(&event)) {
			// �u����v�{�^���ŏI��
			if (event.type == SDL_QUIT) {
				return 0;
			}
		}

		// ��ʂɔ��f������
		SDL_RenderPresent(renderer);

		SDL_Delay(10);
	}
}