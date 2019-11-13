#include "DrawManager.h"
#include "EngineConfig.h"

#include "gameObject.h" // plm

//SDL_Texture* fireTexture; // plm
//SDL_Rect sourceRect, destinationRect; // plm
T2::GameObject* campfire;

void T2::DrawManager::InitWindow(int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
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

	//fireTexture = LoadTexture("../Assets/Sprites/CampFire.PNG", renderer); // plm
	campfire = new GameObject("..Assets/Sprites/CampFire.PNG", renderer);
}

void T2::DrawManager::Update()
{
	//scaling rectangle
	//destinationRect.w = 348; // 87 // plm
	//destinationRect.h = 92; // 23 // plm
	
	//destinationRect.x = testCounter * 0.1;		

	campfire->Update();
}

void T2::DrawManager::Render()
{
	SDL_RenderClear(renderer);
	
	campfire->Render();
	//SDL_RenderCopy(renderer, fireTexture, NULL, &destinationRect); //plm
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


