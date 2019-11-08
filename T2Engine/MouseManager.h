#pragma once

#include <SDL.h>

namespace T2
{
	class Mouse
	{
	private:

		bool buttons[5];
		bool buttonsPrevious[5];
		SDL_Point position;
		SDL_Point motion;

	public:

		Mouse();
		~Mouse();

		bool getButtonDown(Uint8 index);
		bool getButtonPressed(Uint8 index);
		bool getButtonReleased(Uint8 index);

		void setButton(Uint8 button, bool value);
		SDL_Point getPosition();
		SDL_Point getMotion();
		void setMoition(SDL_MouseMotionEvent event);
		void Update();
	};
}