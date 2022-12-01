#include "TextFile.hpp"

// ファイルからテキストを取り出す
std::list<std::string> TextFile::takeOutText() {
    // ファイルのパスを取得
    std::string pass = filePass.getPass();

    // 読み込んだテキストを保存するstring型のリスト
    std::list<std::string> text;

    // ファイルを開く(ifstreamは読み込み専用)
    std::ifstream ifs = std::ifstream(pass);
    if (!ifs) {
        errorOpeningFile();
        return text;
    }

    // 1行ずつ読み込む
    std::string buffer;
    while (std::getline(ifs, buffer)) {
        text.push_back(buffer);
    }

    return text;
}

// ファイルにテキストを上書きする
// ファイルがない場合は新しく作成される
bool TextFile::overwriteText(std::list<std::string> text) {
    // ファイルのパスを取得
    std::string pass = filePass.getPass();
    
    // ファイルを開く(ofstreamは書き込み専用)
    std::ofstream ofs = std::ofstream(pass);
    if (!ofs) {
        errorOpeningFile();
        return false;
    }

    // 1行ずつ書き込む
    for (std::string x : text) {
        ofs << x << std::endl;
    }

    return true;
}