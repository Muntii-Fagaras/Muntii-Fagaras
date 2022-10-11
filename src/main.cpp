// クラスファイルのヘッダファイル
#include "class/load_file.hpp"
#include "class/text.hpp"
#include "class/font.hpp"
#include "class/voice.hpp"
#include "class/image.hpp"
#include "class/checkbox.hpp"
#include "class/mouse.hpp"
#ifdef __ANDROID__

int SDL_main(int argc, char** argv) {
#else
int main(int argc, char** argv) {
#endif
	// ウィンドウ
	SDL_Window* window;
	// 終了イベント
	SDL_Event exit;
	// チェックボックスの位置
	const static int checkbox_place = 100;
	// 背景画像
	image back_ground;
	image back_ground_with_cat;

	// SDL2の初期化
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << SDL_GetError();
		SDL_Quit();
		return 1;
	}
	// Windowの作成、TTF,mixerの初期化
	if ((window = SDL_CreateWindow("gui_base",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1280, 720, SDL_WINDOW_RESIZABLE)) == nullptr ||
		TTF_Init() == -1 ||
		(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)) == -1) {
			std::cout << SDL_GetError();
			SDL_Quit();
			return 1;
	}
	//レンダラー
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	//背景を黒にする
	SDL_SetRenderDrawColor(renderer, 46, 52, 64, 255);

	// マウスのクリック
	mouse mouse{};
	// フォントの読み込み
	font_load font("assets/fonts/HackGen-Regular.ttf", 18);
	text gui_base_text(renderer, font.font, "gui-baseテスト", 0, 10);
	text set_background_text(renderer, font.font, "背景画像", 0, 100);
	text set_background_text_with_cat(renderer, font.font, "猫ちゃん", 0, 200);

	// 音声の読み込み
	//voice weather_voice("assets/voice/good_weather.wav");
	// 画像の読み込み
	std::vector<std::string>image_path={ "assets/image/buttons/not_check.png","assets/image/buttons/checked.png" };
	//weather.play();
	back_ground.load("assets/image/back_ground/back.png", renderer, 0, 0);
	back_ground_with_cat.load("assets/image/back_ground/cat_with_bracket.jpg", renderer, 0, 0);

	checkbox back_ground_check(image_path, renderer, checkbox_place, checkbox_place, mouse.is_cursor_in_box_with_click(checkbox_place, checkbox_place, checkbox_place + 20, checkbox_place + 20));
	checkbox back_ground_check_with_cat(image_path, renderer, checkbox_place, checkbox_place+100, mouse.is_cursor_in_box_with_click(checkbox_place, checkbox_place+100, checkbox_place + 20, checkbox_place + 120));
	// メインループ
	while (1)
	{
		//背景をクリア
		SDL_RenderClear(renderer);
		//閉じるボタンで閉じれるようにする
		SDL_PollEvent(&exit);
		if (exit.type == SDL_QUIT) {
			break;
		}
		back_ground_check.next(mouse.is_cursor_in_box_with_click(checkbox_place, checkbox_place, checkbox_place + 20, checkbox_place + 20));
		back_ground_check_with_cat.next(mouse.is_cursor_in_box_with_click(checkbox_place, checkbox_place+100, checkbox_place + 20, checkbox_place + 120));

		// チェックボックスがオンになったとき
		if (back_ground_check.checkbox_state == true) {
			SDL_RenderCopy(renderer, back_ground.texture, nullptr, &back_ground.rect);
		}else if (back_ground_check_with_cat.checkbox_state == true) {
			SDL_RenderCopy(renderer, back_ground_with_cat.texture, nullptr, &back_ground_with_cat.rect);
		}
		// テキストの描画
		SDL_RenderCopy(renderer, set_background_text_with_cat.texture, nullptr, &set_background_text_with_cat.rect);
		SDL_RenderCopy(renderer, set_background_text.texture, nullptr, &set_background_text.rect);
        SDL_RenderCopy(renderer, gui_base_text.texture,nullptr,&gui_base_text.rect);
		// チェックボックスの描画
		SDL_RenderCopy(renderer, back_ground_check.texture, nullptr, &back_ground_check.rect);
		SDL_RenderCopy(renderer, back_ground_check_with_cat.texture, nullptr, &back_ground_check_with_cat.rect);
		// 画面に反映させる
		SDL_RenderPresent(renderer);
	}
	//デストラクタ
	font.~font_load();
	gui_base_text.~text();
	set_background_text.~text();
	//weather_voice.~voice();
	// ウィンドウを解放する
	SDL_DestroyWindow(window);
	IMG_Quit();

	// SDL2を終了する
	SDL_Quit();

	return 0;
}
