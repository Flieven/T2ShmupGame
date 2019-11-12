#pragma once
#include <SDL.h>

namespace T2
{
	class DrawManager
	{
	public:
		DrawManager() {}
		~DrawManager() {}

		void Initalize(int width, int height);

		void Update();
		void Render();
		void Shutdown();

	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
	};
}