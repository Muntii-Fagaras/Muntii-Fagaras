// GCCの時のコンパイルオプション
#ifdef __GNUC__
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "../SDL2_mixer/SDL_mixer.h"
#endif
#ifdef _MSC_VER
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#endif

#include <iostream>
#include "load_file.hpp"

class voice :public load_file {
public:
	Mix_Chunk* voice_file=NULL;
	// コンストラクタ
	voice(const std::string& voice_file_path);
	//　デストラクタ
	~voice();
	// 音声再生
	void play() const;
private:
};
