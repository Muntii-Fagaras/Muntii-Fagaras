// ���̃t�@�C���͕ύX�����\�����قڂȂ��w�b�_�t�@�C����ǋL����ꏊ
// GCC�̎��̃R���p�C���I�v�V����
#pragma once

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
#include <vector>
#include <iostream>
#include <filesystem>
