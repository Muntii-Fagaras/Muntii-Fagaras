#pragma once
#include <iomanip>
#include <iostream>
#include <string>

class FilePass {
   private:
	std::string directory = "./";		// ファイルのディレクトリ
	std::string name	  = "default";	// ファイルの名前
	std::string extension = "txt";		// ファイルの拡張子

   public:
	FilePass();
	FilePass(std::string set_directory, std::string set_name,
			 std::string set_extension);
	FilePass	changeDirectory(std::string newDirectory);
	FilePass	changeName(std::string newName);
	FilePass	changeExtension(std::string newExtension);
	std::string getPass();
};