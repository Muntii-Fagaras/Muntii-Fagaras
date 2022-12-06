#include "MainScreen.h"

MainScreen::MainScreen(SDL_Window *window, SDL_Renderer *renderer) {
	this->window = window;
	this->renderer = renderer;
}

MainScreen::~MainScreen() {

}

int MainScreen::run() {
	// メインループ
	while (1) {
		// 背景をクリア
		SDL_RenderClear(renderer);

		// イベントを処理
		while (SDL_PollEvent(&event)) {
			// 「閉じる」ボタンで終了
			if (event.type == SDL_QUIT) {
				return 0;
			}
		}

		// 画面に反映させる
		SDL_RenderPresent(renderer);

		SDL_Delay(10);
	}
}