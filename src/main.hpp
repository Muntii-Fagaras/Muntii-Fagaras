#pragma once
// GCC�̎��̃R���p�C���I�v�V����
#ifdef __GNUC__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#endif
// MSVC�̎��̃R���p�C���I�v�V����
#ifdef _MSC_VER
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#endif
// �N���X�t�@�C���̃w�b�_�t�@�C��
#include "class/load_file.hpp"
#include "class/text.hpp"
#include "class/font.hpp"
#include "class/voice.hpp"
#include "class/image.hpp"
#include <vector>