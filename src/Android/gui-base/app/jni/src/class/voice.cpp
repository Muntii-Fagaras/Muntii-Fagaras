#pragma once
#include "voice.hpp"

voice::voice(const std::string& voice_file_path)
{
	//音声を読み込む
	voice_file = Mix_LoadWAV(voice_file_path.c_str());
}

voice::~voice()
{
	// メモリの解放
	Mix_FreeChunk(voice_file);
}

void voice::play() const
{
	//　音声をループなしで再生する
	Mix_PlayChannel(-1, voice_file, 0);
}
