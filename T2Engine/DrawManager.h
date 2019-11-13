#pragma once

#include <SDL.h>
#include "SDL_image.h"
#include <iostream>

namespace T2
{
	class DrawManager
	{
	public:
		DrawManager() {}
		~DrawManager() {}

		void InitWindow(int width, int height, const char* title);
		void Update();
		void Render();
		void Shutdown();

		// Load textures
		static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);

	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
	};
}