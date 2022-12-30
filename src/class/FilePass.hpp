#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class FilePass
{
private:
    std::string directory=nullptr;  // ファイルのディレクトリ
    std::string name=nullptr;       // ファイルの名前
    std::string extension=nullptr;  // ファイルの拡張子

public:
    FilePass();
    FilePass(std::string set_directory,
             std::string set_name,
             std::string set_extension);
    FilePass changeDirectory(std::string newDirectory);
    FilePass changeName     (std::string newName);
    FilePass changeExtension(std::string newExtension);
    std::string getPass();
};