#pragma once
#include <SDL.h>

namespace T2
{
	class DrawManager
	{
	public:
		void InitWindow(const char* title, int xPos, int yPos, int width, int height);

		void Update();
		void Render();
		void Shutdown();

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
	};
}