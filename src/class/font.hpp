#pragma once
#ifdef __ANDROID__
	#include "stdafx.h"
#endif
#include "load_file.hpp"

class font_load : public load_file {
   public:
	// フォント
	TTF_Font* font;
	// fontの読み込み
	font_load(std::string font_path, int font_size);
	// fontの廃棄
	~font_load();

   private:
};