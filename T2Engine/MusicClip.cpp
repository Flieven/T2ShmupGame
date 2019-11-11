#include "MusicClip.h"

T2::Music::Music(std::string music)
{
	musicName = music;
	currentMusic = Mix_LoadMUS(music.c_str());
}

T2::Music::~Music()
{
	Mix_FreeMusic(currentMusic);
	currentMusic = nullptr;
}

void T2::Music::Play()
{
	Mix_PlayMusic(currentMusic, -1);
}

void T2::Music::Stop()
{
	Mix_HaltMusic();
}

std::string T2::Music::getName()
{
	return musicName;
}
