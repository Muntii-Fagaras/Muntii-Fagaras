#pragma once
#include <filesystem>
#include <iostream>
#include <string>
#include <iomanip>

class FilePass
{
private:
    std::string directory;  // �t�@�C���̃f�B���N�g��
    std::string name;       // �t�@�C���̖��O
    std::string extension;  // �t�@�C���̊g���q

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