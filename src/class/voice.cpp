#include "voice.hpp"

voice::voice(std::string voice_file_path)
{
		// 音声ファイルの存在確認
		if (chk(voice_file_path) == false) {
			std::cout << SDL_GetError();
			SDL_Quit();
			exit(1);
		}
	// 音声を読み込む
	voice_file = Mix_LoadWAV(voice_file_path.c_str());
}

voice::~voice()
{
	// メモリの解放
	Mix_FreeChunk(voice_file);
}

void voice::play()
{
	// 　音声をループなしで再生する
	Mix_PlayChannel(-1, voice_file, 0);
}
