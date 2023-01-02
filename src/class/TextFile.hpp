﻿#pragma once
#include <list>

#include "MyFile.hpp"

class TextFile : public MyFile {
	using MyFile::MyFile;  // MyFileのコンストラクタ
   public:
	std::list<std::string> takeOutText();
	bool				   overwriteText(std::list<std::string> text);
};