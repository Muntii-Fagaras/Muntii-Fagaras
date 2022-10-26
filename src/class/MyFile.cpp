#include "MyFile.hpp"

// MyFile�̃R���X�g���N�^
MyFile::MyFile() {
    filePass = FilePass();
}

// MyFile�̃R���X�g���N�^(Filename�Ńp�X���w��)
MyFile::MyFile(FilePass fileName) {
    this->filePass = fileName;
}

// MyFile�̃R���X�g���N�^(string�ł��ꂼ��w��)
MyFile::MyFile(std::string directory,
               std::string name,
               std::string extension) {
    filePass = FilePass(directory, name, extension);
}

void MyFile::errorOpeningFile() {
    // TODO:�G���[����
    // "�t�@�C���̃I�[�v���Ɏ��s���܂����B"
    std::cerr << "�t�@�C���̃I�[�v���Ɏ��s���܂����B" << std::endl;
}

void MyFile::errorReadingFile() {
    // TODO:�G���[����
    // "�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B"
    std::cerr << "�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B" << std::endl;
}
