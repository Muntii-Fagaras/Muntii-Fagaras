#ifdef __GNUC__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "class/load_file.hpp"
#endif
#ifdef _MSC_VER
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "class/load_file.hpp"
#endif
int main(int argc, char** argv) {
	SDL_Window* window;
	// 終了イベント
	SDL_Event exit;
	// フォント
	TTF_Font* font = NULL;
	// 文字列描画構造体
	SDL_Rect time_rect{
		time_rect.x = 520,
		time_rect.y = 260,
		time_rect.w = 300,
		time_rect.h = 90
	};
	// load_fileコンストラクタ
	load_file loading("test");
	// SDL2の初期化
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Quit();
		return 1;
	}
	// Windowの作成、TTFの初期化に失敗したとき
	if ((window = SDL_CreateWindow("Tajpado", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_RESIZABLE)) == NULL || TTF_Init() == -1) {
		SDL_Quit();
		return 1;
	}

	SDL_SetWindowTitle(window, "Tajpado");
	//レンダラー
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	//背景を黒にする
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//背景をクリア
	SDL_RenderClear(renderer);
	if ((font = TTF_OpenFont("HackGen-Regular.ttf", 50)) == NULL) {
		SDL_Quit();
		return 1;
	}
	while (1)
	{
		//背景をクリア
		SDL_RenderClear(renderer);
		//閉じるボタンで閉じれるようにする
		SDL_PollEvent(&exit);
		if (exit.type == SDL_QUIT) {
			break;
		}
		SDL_RenderCopy(renderer,
		SDL_CreateTextureFromSurface(renderer,
			TTF_RenderUTF8_Blended(font,u8"ねこちゃん", SDL_Color{ 0,120, 120, 120 })),NULL, &time_rect);
		// 画面に反映させる
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
