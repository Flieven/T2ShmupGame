#pragma once

#include <SDL_mixer.h>
#include <string>

namespace T2
{
	class Music
	{
	private:
		Mix_Music* currentMusic;
		std::string musicName;

	public:
		Music(std::string music);
		~Music();

		void Play();
		void Stop();
		std::string getName();
	};
}