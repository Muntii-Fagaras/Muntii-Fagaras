#include "FilePass.hpp"
// FileName�̃R���X�g���N�^(�p�X�̓f�t�H���g�ݒ�)
FilePass::FilePass() {
    directory = "..\\"; // �f�t�H���g�̃t�@�C���ۑ���
    // SDL_GetPrefPath(const char* org, const char* app) ���g������

    time_t t = time(nullptr);
    struct tm lt;
    localtime_s(&lt, &t);
    std::stringstream s;
    
    s << lt.tm_year + 1900;
    s << std::setw(2) << std::setfill('0') << lt.tm_mon + 1;
    s << std::setw(2) << std::setfill('0') << lt.tm_mday;
    s << std::setw(2) << std::setfill('0') << lt.tm_hour;
    s << std::setw(2) << std::setfill('0') << lt.tm_min;
    s << std::setw(2) << std::setfill('0') << lt.tm_sec;

    name = s.str(); // �������t�@�C�����Ƃ���
    
    extension = ".txt"; // �f�t�H���g�̃t�@�C���g���q
}

// FileName�̃R���X�g���N�^(�p�X���w��)
FilePass::FilePass  (std::string directory,
                     std::string name,
                     std::string extension) {
    this->directory = directory;    // �t�@�C���ۑ���
    this->name      = name;         // �t�@�C���̖��O
    this->extension = extension;    // �t�@�C���g���q
}

// �f�B���N�g����ύX
FilePass FilePass::changeDirectory(std::string newDirectory) {
    FilePass newFilePass = FilePass(newDirectory, name, extension);
    return newFilePass;
}

// �t�@�C���̖��O��ύX
FilePass FilePass::changeName(std::string newName) {
    FilePass newFilePass = FilePass(directory, newName, extension);
    return newFilePass;
}

// �g���q��ύX
FilePass FilePass::changeExtension(std::string newExtension) {
    FilePass newFilePass = FilePass(directory, name, newExtension);
    return newFilePass;
}

// �t�@�C���̃p�X���擾
std::string FilePass::getPass() {
    std::string pass = directory + name + extension;
    return pass;
}