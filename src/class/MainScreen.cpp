#include "MainScreen.hpp"

MainScreen::MainScreen(SDL_Window *window, SDL_Renderer *renderer,
					   MuntiiColor bgColor)
{
	this->window   = window;
	this->renderer = renderer;
	this->bgColor  = bgColor;

	windowID = SDL_GetWindowID(window);

	// �^�C���𐶐�
	TileEditSpace		 *tileEditSpace = new TileEditSpace(window, renderer);
	TileSupportCharactor *tileSupportCharactor =
		new TileSupportCharactor(window, renderer);

	// �^�C�������X�g�ɒǉ�
	tiles.insert(std::make_pair("editSpace", tileEditSpace));
	tiles.insert(std::make_pair("supportCharactor", tileSupportCharactor));

	// �^�C����z�u
	putTiles();
}

MainScreen::~MainScreen()
{
	// �^�C����j��
	for (std::pair<const char *, Tile *> object : tiles) {
		delete object.second;
	}
}

int MainScreen::mainLoop()
{
	// ���C�����[�v �C�x���g������
	while (1) {
		SDL_PollEvent(&event);
		switch (event.type) {
			case SDL_QUIT:	// �u����v�{�^���ŏI��
				return 0;
				break;
			case SDL_WINDOWEVENT:
				if (event.window.windowID == windowID) {
					switch (event.window.event) {
						case SDL_WINDOWEVENT_SIZE_CHANGED:
							putTiles(event.window.data1, event.window.data2);
							break;
						case SDL_WINDOWEVENT_CLOSE:
							event.type = SDL_QUIT;
							SDL_PushEvent(&event);
							break;
					}
				}
				break;
		}
	}
}

void MainScreen::putTiles()
{
	int winW, winH;
	SDL_GetWindowSize(window, &winW, &winH);
	putTiles(winW, winH);
}

void MainScreen::putTiles(int winW, int winH)
{
	SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b,
						   bgColor.a);
	SDL_RenderClear(renderer);

	tiles.at("editSpace")
		->setArea({0, 50, winW / 5 * 4, winH});
	tiles.at("supportCharactor")
		->setArea({winW / 5 * 4, winH / 3 * 2, winW / 5, winH / 3});
}