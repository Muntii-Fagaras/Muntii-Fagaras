#pragma once

#include "font.hpp"

class text:public load_file{
	public:
		// �e�L�X�g�̕`��ʒu
		SDL_Rect rect{
		rect.x = 520,
		rect.y = 260,
		rect.w = 0,
		rect.h = 0
	};
		// �e�L�X�g�e�N�X�`��
		SDL_Texture* texture=nullptr;
		text(SDL_Renderer* renderer,TTF_Font* font,std::string text_show,int x,int y);
		~text();
	private:
		// �e�L�X�g�T�[�t�F�X
		SDL_Surface* text_surface=nullptr;
};
