#include "DrawManager.h"
#include "Sprite.h"

void T2::DrawManager::InitWindow(int width, int height, const char* title)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		if (!window)
		{
			std::cout << "Window creation error" << SDL_GetError;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 30, 30, 60, 255);
		}
	}
}

void T2::DrawManager::Update()
{
}

void T2::DrawManager::Render(Sprite* sprite, SDL_Rect rect)
{	
	SDL_RenderCopy(renderer, sprite->getTexture() , &sprite->getSource(0), &rect);
}

void T2::DrawManager::Render(Sprite* sprite, SDL_FRect fRect)
{
	SDL_RenderCopyF(renderer, sprite->getTexture(), &sprite->getSource(0), &fRect);
	
}

void T2::DrawManager::DebugRender(SDL_Rect deugRect)
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawRect(renderer, &deugRect);
	SDL_SetRenderDrawColor(renderer, 30, 30, 60, 255);
}

void T2::DrawManager::Shutdown()
{
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}

void T2::DrawManager::Clear() { SDL_RenderClear(renderer); }

void T2::DrawManager::Present() { SDL_RenderPresent(renderer); }

T2::Sprite* T2::DrawManager::LoadTexture(const char* texture, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int frames)
{
	auto it = textures.find(texture);
	if (it == textures.end())
	{
		SDL_Surface* tempSurface = IMG_Load(texture);
		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
		textures.insert(std::pair<std::string, SDL_Texture*>(texture, tex));
		it = textures.find(texture);
	}

	Sprite* sprite = new Sprite(it->second, x, y, w, h, frames);
	sprites.push_back(sprite);

	return sprite;
}


