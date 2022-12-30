#include "mouse.hpp"

bool mouse::is_cursor_in_box_with_click(int xl, int yu, int xr, int yd)
{
	// マウスの現在位置を取得する
	buttons = SDL_GetMouseState(&x_state, &y_state);
		// カーソルがチェックボックスの中にあるとき
		if ((x_state > xl) && (y_state > yu) &&
			((x_state < xr) && (y_state < yd))) {
			update_cursor("HAND");
			SDL_WaitEvent(&left_clicked_event);
				// 左クリックされたとき
				if (clicked_left_down(left_clicked_event)) {
						// 押しっぱなしの時にルーレット状態になるのを防ぐ
						// マウスが放されたときループから脱出する
						while (1) {
							SDL_PollEvent(&left_clicked_event);
								// マウスから放れたとき
								if (clicked_left_up(left_clicked_event)) {
									return true;
								}
						}
				}
		}
		else {
			update_cursor("ARROW");
			// マウスの状態を返す
			return false;
		}
	return false;
}

void mouse::update_cursor(std::string mouse_cursor)
{
		if (mouse_cursor == "HAND") {
			// カーソルを手のアイコンにする
			cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
			// カーソルの状態を更新する
			SDL_SetCursor(cursor);
		}
		else if (mouse_cursor == "ARROW") {
			// チェックボックスの外にカーソルが移動したとき
			cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
			// カーソルを更新する
			SDL_SetCursor(cursor);
		}
}

bool mouse::clicked_left_down(SDL_Event update_left_clicked_event)
{
		if (update_left_clicked_event.button.button == SDL_BUTTON_LEFT &&
			update_left_clicked_event.button.state == SDL_PRESSED) {
			update_cursor("ARROW");

			return true;
		}
		else {
			return false;
		}
}
bool mouse::clicked_left_up(SDL_Event update_left_clicked_event)
{
		if (update_left_clicked_event.button.button == SDL_BUTTON_LEFT &&
			update_left_clicked_event.button.state == SDL_RELEASED) {
			return true;
		}
		else {
			return false;
		}
}
