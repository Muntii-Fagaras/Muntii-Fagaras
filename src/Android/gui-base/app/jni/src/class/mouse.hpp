#pragma once
#ifdef __GNUC__
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "../SDL2_mixer/SDL_mixer.h"
#endif
#ifdef _MSC_VER
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#endif

class mouse {
private:
	Uint32 buttons;
	SDL_Cursor* cursor;
	int x_state, y_state;
	bool mouse_state=false;
public:
	//仮想的な四角形の中にマウスカーソルがあるかどうかを判断するメンバ関数
	//使い方(左、上、右、下)
	bool is_cursor_in_box_with_click(int xl, int yu, int xr, int yd);
};
