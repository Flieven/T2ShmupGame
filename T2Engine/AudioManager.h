#pragma once

#include <map>
#include <vector>
#include <string>

namespace T2
{
	class Sound;
	class Music;

	class AudioManager
	{
	private:

		std::map<std::string, Sound*> soundFiles;
		std::map<std::string, Music*> musicFiles;

		std::vector<Sound*> soundClips;
		std::vector<Music*> musicClips;

	public:

		Sound* currentSound = nullptr;
		Sound* soundClip = nullptr;

		Music* currentMusic = nullptr;
		Music* musicClip = nullptr;

		bool initialize();
		void shutdown();

		T2::Sound* createSound(const std::string& file);
		void destroySound(Sound* soundClip);

		T2::Music* createMusic(const std::string& file);
		void destroyMusic(Music* musicClip);

	};
}