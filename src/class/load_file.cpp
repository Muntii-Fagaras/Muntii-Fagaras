#pragma once

#include "load_file.hpp"

std::string load_file::load(std::string file) {
	return file;
}

bool load_file::chk(std::string path) {
#ifdef __ANDROID__
	return std::__fs::filesystem::exists(path);
#else
	return std::filesystem::exists(path);
#endif
}