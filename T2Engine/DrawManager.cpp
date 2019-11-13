#include "DrawManager.h"

//
float testCounter;
SDL_Texture* fireTexture;
SDL_Rect sourceRect, destinationRect;

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

	/*SDL_Surface* tempSurface = IMG_Load("../Assets/Sprites/CampFire.PNG");
	fireTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);*/ // using LoadTexture function istället...
	fireTexture = LoadTexture("../Assets/Sprites/CampFire.PNG", renderer);
}

void T2::DrawManager::Update()
{
	testCounter++;
	//scaling rectangle
	destinationRect.w = 348; // 87
	destinationRect.h = 92; // 23
	
	destinationRect.x = testCounter * 0.1;		

	std::cout << testCounter << std::endl;
}

void T2::DrawManager::Render()
{
	SDL_RenderClear(renderer);
	
	SDL_RenderCopy(renderer, fireTexture, NULL, &destinationRect); 
	SDL_RenderPresent(renderer);
}

void T2::DrawManager::Shutdown()
{
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}

SDL_Texture* T2::DrawManager::LoadTexture(const char* texture, SDL_Renderer* ren)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}


