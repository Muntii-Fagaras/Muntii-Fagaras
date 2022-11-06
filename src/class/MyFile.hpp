#pragma once
#include <fstream>
#include "FilePass.hpp"

class MyFile {
protected:
    void errorOpeningFile();
    void errorReadingFile();

public:
    FilePass filePass;

    MyFile();
    MyFile(FilePass filePass);
    MyFile(std::string directory,
           std::string name,
           std::string extension);
};