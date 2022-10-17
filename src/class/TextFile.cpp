#pragma once
#include "TextFile.h"

// �t�@�C������e�L�X�g�����o��
std::list<std::string> TextFile::takeOutText() {
    // �t�@�C���̃p�X���擾
    std::string pass = filePass.getPass();

    // �ǂݍ��񂾃e�L�X�g��ۑ�����string�^�̃��X�g
    std::list<std::string> text;

    // �t�@�C�����J��(ifstream�͓ǂݍ��ݐ�p)
    std::ifstream ifs = std::ifstream(pass);
    if (!ifs) {
        errorOpeningFile();
        return text;
    }

    // 1�s���ǂݍ���
    std::string buffer;
    while (std::getline(ifs, buffer)) {
        text.push_back(buffer);
    }

    return text;
}

// �t�@�C���Ƀe�L�X�g���㏑������
// �t�@�C�����Ȃ��ꍇ�͐V�����쐬�����
bool TextFile::overwriteText(std::list<std::string> text) {
    // �t�@�C���̃p�X���擾
    std::string pass = filePass.getPass();
    
    // �t�@�C�����J��(ofstream�͏������ݐ�p)
    std::ofstream ofs = std::ofstream(pass);
    if (!ofs) {
        errorOpeningFile();
        return false;
    }

    // 1�s����������
    for (std::string x : text) {
        ofs << x << std::endl;
    }

    return true;
}