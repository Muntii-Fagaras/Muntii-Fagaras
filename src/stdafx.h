// このファイルは変更される可能性がほぼないヘッダファイルを追記する場所
#pragma once
// GCCの時のコンパイルオプション
#ifdef __GNUC__
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
	#include <SDL2/SDL_mixer.h>
	#include <SDL2/SDL_ttf.h>
#endif
// MSVCの時のコンパイルオプション
#ifdef _MSC_VER
	#include <SDL.h>
	#include <SDL_image.h>
	#include <SDL_mixer.h>
	#include <SDL_ttf.h>
#endif
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include <curl/curl.h>
