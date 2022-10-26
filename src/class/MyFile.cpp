#include "MyFile.hpp"

// MyFileのコンストラクタ
MyFile::MyFile() {
    filePass = FilePass();
}

// MyFileのコンストラクタ(Filenameでパスを指定)
MyFile::MyFile(FilePass fileName) {
    this->filePass = fileName;
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
    std::cerr << "ファイルのオープンに失敗しました。" << std::endl;
}

void MyFile::errorReadingFile() {
    // TODO:エラー処理
    // "ファイルの読み込みに失敗しました。"
    std::cerr << "ファイルの読み込みに失敗しました。" << std::endl;
}
