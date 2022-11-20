#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class FilePass
{
private:
    std::string directory;  // ファイルのディレクトリ
    std::string name;       // ファイルの名前
    std::string extension;  // ファイルの拡張子

public:
    FilePass();
    FilePass(std::string directory,
             std::string name,
             std::string extension);
    FilePass changeDirectory(std::string newDirectory);
    FilePass changeName     (std::string newName);
    FilePass changeExtension(std::string newExtension);
    std::string getPass();
};