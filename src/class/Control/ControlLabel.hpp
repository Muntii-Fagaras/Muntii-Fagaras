#pragma once
#include <string>
#ifdef __GNUC__
	#include "../../stdafx.h"
#endif
#include "../font.hpp"
#include "Control.hpp"

class ControlLabel : public Control {
   private:
	SDL_Texture *texture;
	std::string	 text	   = "";
	SDL_Color	 textColor = SDL_Color{255, 255, 255, 255};
	Font		*font;
	int			 textureW, textureH;

   public:
	ControlLabel(SDL_Window *window, SDL_Renderer *renderer, std::string text,
				 Font *font);
	virtual ~ControlLabel();
	virtual void put(SDL_Rect area) override;
	virtual void setTextColor(SDL_Color color);
};