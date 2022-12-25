#include "FilePass.hpp"

// FilePassのコンストラクタ(パスはデフォルト設定)
FilePass::FilePass() {
    directory = "./"; // デフォルトのファイル保存先
    // SDL_GetPrefPath(const char* org, const char* app) が使えそう

    time_t t = time(nullptr);
    struct tm lt;
#ifdef _MSC_VER
	localtime_s(&lt, &t);
#endif
#ifdef __MINGW64__
	localtime_s(&lt, &t);
#elif __GNUC__	
    localtime_r(&t, &lt);
#endif
#if _MSC_VER >= 1930

    std::stringstream s;
    s << lt.tm_year + 1900;
    s << std::setw(2) << std::setfill('0') << lt.tm_mon + 1;
    s << std::setw(2) << std::setfill('0') << lt.tm_mday;
    s << std::setw(2) << std::setfill('0') << lt.tm_hour;
    s << std::setw(2) << std::setfill('0') << lt.tm_min;
    s << std::setw(2) << std::setfill('0') << lt.tm_sec;

    name = s.str(); // 時刻をファイル名とする
#endif

    this->extension = ".txt"; // デフォルトのファイル拡張子
}

// FilePassのコンストラクタ(パスを指定)
FilePass::FilePass  (std::string set_directory,
                     std::string set_name,
                     std::string set_extension) {
    this->directory = set_directory;    // ファイル保存先
    this->name      = set_name;         // ファイルの名前

    if (name[0] == '.') {
        this->extension = set_extension;    // ファイル拡張子
    }
    else {
        this->extension = ".txt";
    }
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
