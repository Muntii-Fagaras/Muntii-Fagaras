#pragma once
#include <fstream>
#include "FilePass.h"

class MyFile {
protected:
    void errorOpeningFile();
    void errorReadingFile();

public:
    FilePass filePass;

    MyFile();
    MyFile(FilePass fileName);
    MyFile(std::string directory,
           std::string name,
           std::string extension);
};