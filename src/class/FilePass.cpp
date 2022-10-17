#pragma once
#include "FilePass.h"

// FileNameのコンストラクタ(パスはデフォルト設定)
FilePass::FilePass() {
    directory   = "..\\";       // デフォルトのファイル保存先
    // SDL_GetPrefPath(const char* org, const char* app) が使えそう
    name        = "newfile";    // デフォルトのファイル名
    extension   = ".txt";       // デフォルトのファイル拡張子

    /*
    for (int i = 0; std::filesystem::exists(getPass()); i++) {
        name = "newfile" + std::to_string(i);
    }
    */
}

// FileNameのコンストラクタ(パスを指定)
FilePass::FilePass  (std::string directory,
                     std::string name,
                     std::string extension) {
    this->directory = directory;    // ファイル保存先
    this->name      = name;         // ファイルの名前
    this->extension = extension;    // ファイル拡張子
}

// ディレクトリを変更
FilePass FilePass::changeDirectory(std::string newDirectory) {
    FilePass newFilePass = FilePass(newDirectory, name, extension);

    return newFilePass;
}

// ファイルの名前を変更
FilePass FilePass::changeName(std::string newName) {
    FilePass newFilePass = FilePass(directory, newName, extension);

    return newFilePass;
}

// 拡張子を変更
FilePass FilePass::changeExtension(std::string newExtension) {
    FilePass newFilePass = FilePass(directory, name, newExtension);

    return newFilePass;
}

// ファイルのパスを取得
std::string FilePass::getPass() {
    std::string pass = directory + name + extension;

    return pass;
}