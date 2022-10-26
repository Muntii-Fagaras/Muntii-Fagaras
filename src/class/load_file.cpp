
#include "load_file.hpp"

std::string load_file::load(std::string file) { return file; }

bool load_file::chk(std::string path)
{
	return std::filesystem::exists(path);
}
