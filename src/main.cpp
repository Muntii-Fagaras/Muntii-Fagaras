﻿#ifdef __GNUC__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#endif
#ifdef _MSC_VER
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#endif
#include "class/load_file.hpp"
#include "class/text.hpp"
int main(int argc, char** argv) {
	SDL_Window* window;
	// 終了イベント
	SDL_Event exit;
	// 文字列描画構造体
	SDL_Rect time_rect{
		time_rect.x = 520,
		time_rect.y = 260,
		time_rect.w = 150,
		time_rect.h = 90
	};
	// 
	
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
	text test;
	test.load_file_with_chk("HackGen-Regular.ttf", 50);
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
			TTF_RenderUTF8_Blended(test.font,reinterpret_cast<const char*>(u8"ねこ"), SDL_Color{ 0,120, 120, 120 })),NULL, &time_rect);
		// 画面に反映させる
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
