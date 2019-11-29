#pragma once

#include "StaticIncluder.h"
#include <vector>

namespace T2
{
	class Sprite
	{
	protected:
		Sprite();
		SDL_Texture* texture = nullptr;
		std::vector<SDL_Rect> sources;

	public:
		Sprite(SDL_Texture* tex, int x, int y, int w, int h, int frames);
		~Sprite();

		void setSources(int x, int y, int w, int h, int frames);
		SDL_Rect getSource(int frame);
		SDL_Texture* getTexture();
		int getLength();
		int getFrame();

		int currentFrame = 0;
		SDL_Rect currentFrameRect;

	};
}