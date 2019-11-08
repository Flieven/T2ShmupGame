#pragma once
#include <SDL.h>

namespace T2
{
	class Keyboard;
	class Mouse;

	class Input
	{
	private:
		Mouse* mouse;
		Keyboard* keyboard;

	public:

		Input();
		~Input();

		void initialize();
		void shutdown();
		SDL_Point getMousePosition();
		SDL_Point getMouseMotion();

		bool isMouseButtonDown(int button);
		bool isMouseButtonPressed(int button);
		bool isMouseButtonReleased(int button);
		bool isKeyDown(SDL_Scancode key);
		bool isKeyDownOnce(SDL_Scancode key);

		void handleEvent(SDL_Event& event);
		void Update();
	};
}