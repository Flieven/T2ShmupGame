#include "DrawManager.h"

void T2::DrawManager::InitWindow(int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow("ShmupGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		if (window)
		{
			// window created
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

void T2::DrawManager::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void T2::DrawManager::Shutdown()
{
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}
