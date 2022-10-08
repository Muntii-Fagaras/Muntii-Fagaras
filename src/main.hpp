#pragma once
// GCCの時のコンパイルオプション
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
// クラスファイルのヘッダファイル
#include "class/load_file.hpp"
#include "class/text.hpp"
#include "class/font.hpp"
#include "class/voice.hpp"
#include "class/image.hpp"
#include <vector>