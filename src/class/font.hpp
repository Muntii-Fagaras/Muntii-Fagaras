#pragma once
#include <filesystem>
#include <string>
#ifdef __GNUC__
	#include "../stdafx.h"
#endif

namespace fs = std::filesystem;

class Font {
   public:
	TTF_Font *font = nullptr;
	fs::path  path;

	~Font();
	void load(fs::path path, int ptSize, long faceIndex);
};