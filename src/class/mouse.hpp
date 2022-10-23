#pragma once

#ifdef __ANDROID__
	#include "stdafx.h"
#endif
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
class mouse {
   private:
	// クリックボタン
	Uint32 buttons;
	// カーソル
	SDL_Cursor* cursor	= nullptr;
	int			x_state = 0;
	int			y_state = 0;
	// マウスがクリックされているかの状態
	bool mouse_state = false;
	void update_cursor(std::string cursor_state);
	bool clicked_left_down(SDL_Event left_clicked_event);
	bool clicked_left_up(SDL_Event left_clicked_event);
	// 終了イベント
	SDL_Event left_clicked_event;

   public:
	// 仮想的な四角形の中にマウスカーソルがあるかどうかを判断するメンバ関数
	// 使い方(左、上、右、下)
	bool is_cursor_in_box_with_click(int xl, int yu, int xr, int yd);
};