#pragma once

#include "load_file.hpp"

class voice :public load_file {
public:
	// 音声ファイル
	Mix_Chunk* voice_file;
	// コンストラクタ
	voice(std::string voice_file_path);
	//　デストラクタ
	~voice();
	// 音声再生
	void play();
private:
};
