#pragma once

#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include <map>
#include<string>
#include <vector>

namespace T2
{

	class Sprite;

	class DrawManager
	{
	public:
		DrawManager() {}
		~DrawManager() {}

		void InitWindow(int width, int height, const char* title);
		void Update();
		void Render(Sprite* sprite, SDL_Rect rect);
		void DebugRender(SDL_Rect deugRect);
		void Shutdown();
		void Clear();
		void Present();

		SDL_Renderer* getRenderer();

		// Load textures
		Sprite* LoadTexture(const char* fileName, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int frames);

	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

		std::vector<Sprite*> sprites;
		std::map<std::string, SDL_Texture*> textures;

	};
}