#pragma once

#include "EngineConfig.h"
#include <vector>

namespace T2
{
	class Sprite
	{
	protected:
		Sprite();
		SDL_Texture* texture = nullptr;
		std::vector<SDL_Rect> sources;

		SDL_Rect currentFrameRect;
		int currentFrame = 0;

	public:
		Sprite(SDL_Texture* tex, int x, int y, int w, int h, int frames);
		~Sprite();

		void setSources(int x, int y, int w, int h, int frames);
		SDL_Rect getSource(int frame);
		SDL_Texture* getTexture();
		int getLength();
		int getFrame();

	};
}