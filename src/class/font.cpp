#include "font.hpp"

font_load::font_load(std::string font_path, int font_size)
{
		// フォントファイルの存在確認
		if (chk(font_path) == false) {
			throw std::invalid_argument(SDL_GetError());
		}
		// フォントをメモリに読み込む
		if ((font_load::font = TTF_OpenFont(font_path.c_str(), font_size)) ==
			nullptr) {
			throw std::invalid_argument(SDL_GetError());
		}
}

font_load::~font_load()
{
	// フォントをメモリから解放する
	TTF_CloseFont(font);
}
