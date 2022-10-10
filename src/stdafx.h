// このファイルは変更される可能性がほぼないヘッダファイルを追記する場所
// GCCの時のコンパイルオプション
#pragma once

#ifdef __GNUC__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#endif
// MSVCの時のコンパイルオプション
#ifdef _MSC_VER
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#endif
#include <vector>
#include <iostream>
#include <filesystem>
