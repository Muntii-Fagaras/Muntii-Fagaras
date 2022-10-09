#pragma once
#include "mouse.hpp"

bool mouse::is_cursor_in_box_with_click(int xl, int yu, int xr, int yd) {
	SDL_PumpEvents();
	buttons = SDL_GetMouseState(&x_state, &y_state);
	if ((x_state > xl) && (y_state > yu) && ((x_state < xr) && (y_state < yd))) {
		cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
		SDL_SetCursor(cursor);
		//左クリックされたとき
		if ((buttons & SDL_MOUSEBUTTONDOWN) != 0) {
			if (mouse_state == true) {
				mouse_state = false;
			}
			else {
				mouse_state = true;
			}
		}
	}
	else {
		cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
		SDL_SetCursor(cursor);
	}
	return mouse_state;
}