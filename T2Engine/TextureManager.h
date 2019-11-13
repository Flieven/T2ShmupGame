#pragma once

#include <SDL.h>
#include "SDL_image.h"
#include <iostream>

namespace T2
{
	class TextureManager
	{
		static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer renderer);
	};
}