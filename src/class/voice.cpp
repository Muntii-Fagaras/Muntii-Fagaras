#include "voice.hpp"

voice::voice(std::string voice_file_path)
{
		// 音声ファイルの存在確認
		if (chk(voice_file_path) == false) {
			throw std::invalid_argument(SDL_GetError());
		}
	// 音声を読み込む
	voice_file = Mix_LoadMUS(voice_file_path.c_str());
}

voice::~voice()
{
	// メモリの解放
	// Mix_FreeChunk(voice_file);
}

void voice::play()
{
	// 　音声をループなしで再生する
	// Mix_PlayChannel(-1, voice_file, 0);
	Mix_PlayMusic(voice_file, 1);
}
