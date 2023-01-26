#pragma once
#ifdef __GNUC__
	#include "../../stdafx.h"
#endif
#include "../Text.hpp"
#include "../font.hpp"
#include "Control.hpp"

class ControlEditSpace : public Control {
   private:
	SDL_Color textColor = SDL_Color{255, 255, 255, 255};
	Text	 *text;
	Font	 *font;

   public:
	ControlEditSpace(SDL_Window *window, SDL_Renderer *renderer, Font *font);
	~ControlEditSpace();
	void put(SDL_Rect area) override;
	void presentText();
	void presentText(Text *text);
	void setTextColor(SDL_Color color);
};