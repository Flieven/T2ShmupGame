#include "SoundClip.h"

T2::Sound::Sound(std::string sound)
{
	soundName = sound;
	currentSound = Mix_LoadWAV(sound.c_str());
}

T2::Sound::~Sound()
{
	Mix_FreeChunk(currentSound);
	currentSound = nullptr;
}

void T2::Sound::Play(int loops)
{
	const int& lastChannel = Mix_PlayChannel(-1, currentSound, loops);
}

void T2::Sound::Stop()
{
	if(lastChannel != -1) { Mix_HaltChannel(lastChannel); }
}

std::string T2::Sound::getName()
{
	return soundName;
}
