#include "stdafx.h"
#include "class/MuntiiFagaras.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer;

	try {
		// SDL2の初期化
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			throw std::runtime_error(SDL_GetError());
		}

		// Windowの作成、TTF,mixerの初期化
		window = SDL_CreateWindow(
			"Muntii-Fagaras", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_RESIZABLE);

		if (window == nullptr || TTF_Init() == -1 ||
			Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
			throw std::runtime_error(SDL_GetError());
		}

		// レンダラーを生成
		renderer = SDL_CreateRenderer(window, -1, 0);

		MuntiiFagaras muntiiFagaras = MuntiiFagaras(window, renderer);
		muntiiFagaras.mainloop();
	}
	catch (std::runtime_error &exception) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
								 "エラーだよっ!", exception.what(), window);
		return -1;
	}
	
	//  ウィンドウを解放する
	SDL_DestroyWindow(window);
	// SDL2を終了する
	SDL_Quit();

	return 0;
}