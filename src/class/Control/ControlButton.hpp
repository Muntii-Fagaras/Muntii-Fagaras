#pragma once
#include <string>

#include "../image.hpp"
#include "Control.hpp"

class ControlButton : public Control {
   private:
	std::string text = "";
	SDL_Color	slctColor =
		SDL_Color{50, 50, 0, 50};  // ボタンが選ばれたときに変化する色

   public:
	ControlButton(SDL_Window *window, SDL_Renderer *renderer, std::string text);
	virtual ~ControlButton();
	virtual void put(SDL_Rect area);
	void		 setText(std::string text);
	void		 setSlctColor(SDL_Color color);
};