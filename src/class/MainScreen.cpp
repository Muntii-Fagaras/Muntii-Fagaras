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

	// タイルを生成
	TileSupportCharactor *tileSupportCharactor = new TileSupportCharactor(window, renderer);
	tileSupportCharactor->setArea({winW / 4 * 3, winH / 3 * 2, winW / 4, winH / 3});

	// タイルをリストに追加
	tiles.push_back(tileSupportCharactor);
}

MainScreen::~MainScreen()
{
	// タイルを破棄
	for (Tile *tile : tiles) {
		delete tile;
	}
}

int MainScreen::mainRoop()
{
		// メインループ
		while (1) {
			// 各タイルの処理
			for (Tile *tile : tiles) {
				tile->run();
			}

			// イベントを処理
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
					case SDL_QUIT:	// 「閉じる」ボタンで終了
						return 0;
						break;
				}
			}

			SDL_Delay(10);
		}
}