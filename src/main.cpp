#ifdef __GNUC__
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
#include "class/font.hpp"
#include "class/voice.hpp"
int main(int argc, char** argv) {
	// ウィンドウ
	SDL_Window* window;
	// 終了イベント
	SDL_Event exit;
	// SDL2の初期化
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Quit();
		return 1;
	}
	// Windowの作成、TTFの初期化に失敗したとき
	if ((window = SDL_CreateWindow("Tajpado", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_RESIZABLE)) == NULL || TTF_Init() == -1 || (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)) == -1) {
		SDL_Quit();
		return 1;
	}
	//レンダラー
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	//背景を黒にする
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//背景をクリア
	SDL_RenderClear(renderer);
	// フォントの読み込み
	font_load f("HackGen-Regular.ttf", 100);
	text cat(renderer, f.font, "にゃんこ", 0, 10);
	text cats(renderer, f.font, "ニャンぱーてぃニャン", 0, 110);
	// 音声の読み込み
	voice weather("assets/voice/good_weather.wav");
	weather.play();
	while (1)
	{
		//背景をクリア
		SDL_RenderClear(renderer);
		//閉じるボタンで閉じれるようにする
		SDL_PollEvent(&exit);
		if (exit.type == SDL_QUIT) {
			break;
		}
		SDL_RenderCopy(renderer,cat.texture,NULL,&cat.rect);
		SDL_RenderCopy(renderer, cats.texture, NULL, &cats.rect);

		// 画面に反映させる
		SDL_RenderPresent(renderer);
		// 無限ループが早すぎてフリーズするのを防ぐ
		SDL_Delay(10);
	}
	//デストラクタ
	f.~font_load();
	cat.~text();
	cats.~text();
	weather.~voice();
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
