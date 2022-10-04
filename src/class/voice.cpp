#pragma once
#include "voice.hpp"

voice::voice(std::string voice_file_path)
{
	//������ǂݍ���
	voice_file = Mix_LoadWAV(voice_file_path.c_str());
}

voice::~voice()
{
	// �������̉��
	Mix_FreeChunk(voice_file);
}

void voice::play()
{
	//�@���������[�v�Ȃ��ōĐ�����
	Mix_PlayChannel(-1, voice_file, 0);
}
