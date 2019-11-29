#include "AudioManager.h"

#include "SoundClip.h"
#include "MusicClip.h"

#include <SDL_mixer.h>

bool T2::AudioManager::initialize()
{
	return false;
}

void T2::AudioManager::shutdown()
{
	for (int i = 0; i < soundClips.size(); i++)
	{
		if (soundClips[i] != nullptr)
		{
			soundClips[i]->~Sound();
			soundClips.erase(std::find(soundClips.begin(), soundClips.end(), soundClips[i]));
		}
		soundClip = nullptr;
	}

	for (int i = 0; i < musicClips.size(); i++)
	{
		if (musicClips[i] != nullptr)
		{
			musicClips[i]->~Music();
			musicClips.erase(std::find(musicClips.begin(), musicClips.end(), musicClips[i]));
		}
		musicClip = nullptr;
	}
}

T2::Sound* T2::AudioManager::createSound(const std::string& file)
{
	auto it = soundFiles.find(file);
	if (it == soundFiles.end())
	{
		currentSound = new Sound(file);
		soundFiles.insert(std::pair<std::string, Sound*>(file, currentSound));
	}
	soundClip = new Sound(file);
	soundClips.push_back(soundClip);
	return soundClip;
}

void T2::AudioManager::destroySound(Sound* soundClip)
{
	for (int i = 0; i < soundClips.size(); i++)
	{
		if (soundClip->getName() == soundClips[i]->getName())
		{
			soundClips.erase(std::find(soundClips.begin(), soundClips.end(), soundClips[i]));
		}
		auto it = soundFiles.find(soundClip->getName());
		soundFiles.erase(it, soundFiles.end());
	}
}

T2::Music* T2::AudioManager::createMusic(const std::string& file)
{
	auto it = musicFiles.find(file);
	if (it == musicFiles.end())
	{
		currentMusic = new Music(file);
		musicFiles.insert(std::pair<std::string, Music*>(file, currentMusic));
	}
	musicClip = new Music(file);
	musicClips.push_back(musicClip);
	return musicClip;
}

void T2::AudioManager::destroyMusic(Music* musicClip)
{
	for (int i = 0; i < musicClips.size(); i++)
	{
		if (musicClip->getName() == musicClips[i]->getName())
		{
			musicClips.erase(std::find(musicClips.begin(), musicClips.end(), musicClips[i]));
		}
		auto it = musicFiles.find(musicClip->getName());
		musicFiles.erase(it, musicFiles.end());
	}
}
