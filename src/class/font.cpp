#include "font.hpp"

void Font::load(fs::path path, int ptSize, long faceIndex)
{
	this->path = path;

		if (font != nullptr) {
			// フォントをメモリから解放する
			TTF_CloseFont(font);
		}

		// フォントファイルの存在を確認
		if (!fs::exists(path)) {
			throw std::invalid_argument(SDL_GetError());
		}

	std::string pathStr = path.string();

	// フォントをメモリに書き込む
	font = TTF_OpenFont(pathStr.c_str(), ptSize);

		if (font == nullptr) {
			throw std::invalid_argument(SDL_GetError());
		}
}

Font::~Font()
{
	// フォントをメモリから解放する
	TTF_CloseFont(font);
}