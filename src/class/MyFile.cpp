#include "MyFile.hpp"

// MyFileのコンストラクタ
MyFile::MyFile() {
    filePass = FilePass();
}

// MyFileのコンストラクタ(FilePassでパスを指定)
MyFile::MyFile(FilePass filePass) {
    this->filePass = filePass;
}

// MyFileのコンストラクタ(stringでそれぞれ指定)
MyFile::MyFile(std::string directory,
               std::string name,
               std::string extension) {
    filePass = FilePass(directory, name, extension);
}

void MyFile::errorOpeningFile() {
    // TODO:エラー処理
    // "ファイルのオープンに失敗しました。"
    std::cout << "ファイルのオープンに失敗しました。" << std::endl;
}

void MyFile::errorReadingFile() {
    // TODO:エラー処理
    // "ファイルの読み込みに失敗しました。"
    std::cout << "ファイルの読み込みに失敗しました。" << std::endl;
}