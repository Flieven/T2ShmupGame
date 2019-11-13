#include "Sprite.h"

T2::Sprite::Sprite()
{
}

T2::Sprite::Sprite(SDL_Texture* tex, int x, int y, int w, int h, int frames)
{
	texture = tex;
	setSources(x, y, w, h, frames);
}

T2::Sprite::~Sprite()
{
}

void T2::Sprite::setSources(int x, int y, int w, int h, int frames)
{
	for (size_t i = 0; i < frames; i++)
	{
		SDL_Rect rect;
		rect.x = x + (i * w);
		rect.y = y;
		rect.w = w;
		rect.h = h;

		sources.push_back(rect);
	}
}

SDL_Rect T2::Sprite::getSource(int frame)
{
	return sources[frame];
}

SDL_Texture* T2::Sprite::getTexture()
{
	return texture;
}

int T2::Sprite::getLength()
{
	return sources.size();
}

int T2::Sprite::getFrame()
{
	return currentFrame;
}
