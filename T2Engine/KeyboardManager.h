#pragma once

#include <SDL.h>

namespace T2
{
	class Keyboard
	{
	private:

		bool keys[SDL_NUM_SCANCODES];
		bool keysPrevious[SDL_NUM_SCANCODES];

	public:

		Keyboard();
		~Keyboard();

		void setKey(SDL_Scancode key, bool value);
		bool getKeyDown(SDL_Scancode key);
		bool getKeyDownOnce(SDL_Scancode key);
		void Update();

	};
}