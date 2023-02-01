#pragma once
#include <string>
#ifdef __GNUC__
	#include "../../stdafx.h"
#endif
#include "Control.hpp"
#include "ControlLabel.hpp"

class ControlButton : public Control {
   private:
	// 表示するテキスト
	std::string text = "";
	// ボタンが選ばれたときに変化する色
	SDL_Color slctColor = SDL_Color{50, 50, 0, 50};

	ControlLabel *label;

   public:
	ControlButton(SDL_Window *window, SDL_Renderer *renderer, std::string text,
				  Font *font);
	virtual ~ControlButton();
	virtual void put(SDL_Rect area);
	void		 setText(std::string text);
	void		 setSlctColor(SDL_Color color);
};