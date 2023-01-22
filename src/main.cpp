// クラスファイルのヘッダファイル
#include "class/TextFile.hpp"
#include "class/button.hpp"
#include "class/checkbox.hpp"
#include "class/font.hpp"
#include "class/image.hpp"
#include "class/load_file.hpp"
#include "class/mouse.hpp"
#include "class/rpn.hpp"
#include "class/text.hpp"
#include "class/voice.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	// ウィンドウ
	SDL_Window* window = nullptr;
		try {
			// 終了イベント
			SDL_Event exit;
				// SDL2の初期化
				if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
					throw std::runtime_error(SDL_GetError());
				}
				// Windowの作成、TTF,mixerの初期化
				if ((window = SDL_CreateWindow(
						 "Muntii-Fagaras メイン画面", SDL_WINDOWPOS_UNDEFINED,
						 SDL_WINDOWPOS_UNDEFINED, 1280, 720,
						 SDL_WINDOW_RESIZABLE)) == nullptr ||
					TTF_Init() == -1 ||
					(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)) == -1) {
					throw std::runtime_error(SDL_GetError());
				}
			// レンダラー
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
			// 背景を黒にする
			SDL_SetRenderDrawColor(renderer, 46, 52, 64, 255);
			// 逆ポーランド記法
			reverse_polish_notation rpn;
			int						ans = rpn.calc("1+2*3");
			std::string				output;
				for (auto x : rpn.fixed_reverse_polish_notation_formula) {
					output += x;
				}
			// ウィンドウのタイトル名変更
			SDL_SetWindowTitle(window, (std::to_string(ans).c_str()));
			// メインループ
				while (SDL_WaitEvent(&exit)) {
					// 背景をクリア
					SDL_RenderClear(renderer);
					// 閉じるボタンで閉じれるようにする
						if (exit.type == SDL_QUIT) {
							break;
						}
					// 画面に反映させる
					SDL_RenderPresent(renderer);
				}
			//  ウィンドウを解放する
			SDL_DestroyWindow(window);

			// SDL2を終了する
			SDL_Quit();

			return 0;
		}
		catch (std::runtime_error& exception) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "エラーだよっ!",
									 exception.what(), window);
			// SDL2を終了する
			SDL_Quit();
			return 0;
		}
}
