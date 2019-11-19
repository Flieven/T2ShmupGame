#pragma once

#include <SDL.h>

namespace T2
{
	class GameObject
	{
	public:
		GameObject(const char* texturesheet, SDL_Renderer* ren);
		~GameObject();

		void Update();
		void Render();

	private:
		int xPos, yPos;
		
		SDL_Texture* objectTexture;
		SDL_Rect sourceRect, destinationRect;
		SDL_Renderer* renderer;

	};
}