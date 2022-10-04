#pragma once
#include "voice.hpp"

voice::voice(std::string voice_file_path)
{
	//‰¹º‚ğ“Ç‚İ‚Ş
	voice_file = Mix_LoadWAV(voice_file_path.c_str());
}

voice::~voice()
{
	// ƒƒ‚ƒŠ‚Ì‰ğ•ú
	Mix_FreeChunk(voice_file);
}

void voice::play()
{
	//@‰¹º‚ğƒ‹[ƒv‚È‚µ‚ÅÄ¶‚·‚é
	Mix_PlayChannel(-1, voice_file, 0);
}
