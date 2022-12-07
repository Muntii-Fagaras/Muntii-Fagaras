#include "MainScreen.hpp"

MainScreen::MainScreen(SDL_Window *window, SDL_Renderer *renderer, Color bgColor)
{
	this->window   = window;
	this->renderer = renderer;
	this->bgColor = bgColor;

	int winW, winH;
	SDL_GetWindowSize(window, &winW, &winH);

	SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
	SDL_RenderClear(renderer);

	// �^�C���𐶐�
	TileSupportCharactor *tileSupportCharactor = new TileSupportCharactor(window, renderer);
	tileSupportCharactor->setArea({winW / 4 * 3, winH / 3 * 2, winW / 4, winH / 3});

	// �^�C�������X�g�ɒǉ�
	tiles.push_back(tileSupportCharactor);
}

MainScreen::~MainScreen()
{
	// �^�C����j��
	for (Tile *tile : tiles) {
		delete tile;
	}
}

int MainScreen::mainRoop()
{
		// ���C�����[�v
		while (1) {
			// �e�^�C���̏���
			for (Tile *tile : tiles) {
				tile->run();
			}

			// �C�x���g������
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
					case SDL_QUIT:	// �u����v�{�^���ŏI��
						return 0;
						break;
				}
			}

			SDL_Delay(10);
		}
}