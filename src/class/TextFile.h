#pragma once
#include <list>
#include "MyFile.h"

class TextFile : public MyFile
{
    using MyFile::MyFile;   // MyFile�̃R���X�g���N�^
public:
    std::list<std::string> takeOutText();
    bool overwriteText(std::list<std::string> text);
};