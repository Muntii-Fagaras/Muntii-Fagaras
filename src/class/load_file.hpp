#pragma once
#ifdef __ANDROID__
#include "stdafx.h"
#endif
#ifdef __GNUC__
#include "../stdafx.h"
#endif
class load_file{
	public:
		std::string load(std::string path);
		bool chk(std::string path);
	private:
};
