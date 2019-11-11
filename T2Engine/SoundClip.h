#pragma once

#include <SDL_mixer.h>
#include <string>

namespace T2
{
	class Sound
	{
	private: 
		Mix_Chunk* currentSound = nullptr;
		int lastChannel;
		int currentChannel;
		std::string soundName;

	public:
		Sound(std::string sound);
		~Sound();

		void Play(int loops);
		void Stop();

		std::string getName();
	};
}