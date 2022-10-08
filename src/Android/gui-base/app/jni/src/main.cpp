// GCCの時のコンパイルオプション
#ifdef __GNUC__
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#endif
// MSVCの時のコンパイルオプション
#ifdef _MSC_VER
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#endif
// クラスファイルのヘッダファイル
#include "class/load_file.hpp"
#include "class/text.hpp"
#include "class/font.hpp"
#include "class/voice.hpp"
#include "class/image.hpp"
#include "class/checkbox.hpp"
#include "class/mouse.hpp"

#include <vector>
int SDL_main(int argc, char** argv) {
    // ウィンドウ
    SDL_Window* window;
    // 終了イベント
    SDL_Event exit;
    // SDL2の初期化
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Quit();
        return 1;
    }
    // Windowの作成、TTF,mixerの初期化
    if ((window = SDL_CreateWindow("gui_base", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_RESIZABLE)) == nullptr || TTF_Init() == -1 || (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)) == -1) {
        SDL_Quit();
        return 1;
    }
    //レンダラー
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    //背景を黒にする
    SDL_SetRenderDrawColor(renderer, 46, 52, 64, 255);
    //背景をクリア
    SDL_RenderClear(renderer);

    mouse mouse{};
    // フォントの読み込み
    font_load f("assets/fonts/HackGen-Regular.ttf", 18);
    text cat(renderer, f.font, "にゃんこ", 0, 10);
    text cats(renderer, f.font, "ニャンぱーてぃニャン", 0, 50);
    text catt(renderer, f.font, "背景画像", 0, 100);
    // 音声の読み込み
    voice weather("assets/voice/good_weather.wav");
    // 画像の読み込み
    std::vector<std::string>image_path={ "assets/image/buttons/not_check.png","assets/image/buttons/checked.png" };
    //weather.play();
    const static int checkbox_place = 100;
    image back_ground;
    while (1)
    {
        //背景をクリア
        SDL_RenderClear(renderer);
        //閉じるボタンで閉じれるようにする
        SDL_PollEvent(&exit);
        if (exit.type == SDL_QUIT) {
            break;
        }
        checkbox a(image_path, renderer, checkbox_place, checkbox_place, mouse.is_cursor_in_box_with_click(checkbox_place, checkbox_place, checkbox_place+20, checkbox_place+20));
        if (exit.type == SDL_MOUSEBUTTONDOWN) {
            while (1) {
                SDL_PollEvent(&exit);
                if (exit.type == SDL_MOUSEBUTTONUP) {
                    break;
                }
            }
        }
        // チェックボックスがオンになったとき
        if (a.checkbox_state == true) {
            back_ground.load("assets/image/back_ground/back.png", renderer, 0, 0);
            SDL_RenderCopy(renderer, back_ground.texture, nullptr, &back_ground.rect);
        }
        SDL_RenderCopy(renderer, catt.texture, nullptr, &catt.rect);
        SDL_RenderCopy(renderer,cat.texture,nullptr,&cat.rect);
        SDL_RenderCopy(renderer, cats.texture, nullptr, &cats.rect);
        SDL_RenderCopy(renderer, a.texture, nullptr, &a.rect);


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
    //check_button.~image();
    // ウィンドウを解放する
    SDL_DestroyWindow(window);
    IMG_Quit();

    // SDL2を終了する
    SDL_Quit();

    return 0;
}