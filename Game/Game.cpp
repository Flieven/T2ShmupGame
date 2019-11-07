#pragma once

#include <EngineEntry.h>
#include <ServiceLocator.h>

#include "StaticIncluder.h"			
#include "Game.h"

bool ShmupGame::Initialize()
{
	std::cout << "===== Initalizing Engine =====" << std::endl;
	assert(SDL_Init(SDL_INIT_EVERYTHING) == 0 && "SDL_Init Failed to Initalize");
	assert(IMG_Init(IMG_INIT_PNG) != 0 && "IMG_Init Failed to Initalize");
	assert(Mix_Init(MIX_INIT_MP3) != 0 && "Mix_Init Failed to Initalize");
	assert(TTF_Init() == 0 && "TTF_Init Failed to Initialize");;

	ServiceLocator<Input>::setService(inputManager);

	return true;
}

void ShmupGame::Shutdown()
{
	std::cout << "===== Yeet Engine =====" << std::endl;
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

void ShmupGame::Run()
{
	while (isRunning)
	{
		EventHandler();
		// Yoda rave
	}
}

void ShmupGame::EventHandler()
{
	SDL_Event event;

	while (SDL_PollEvent(&event) == 1)
	{
		if (event.type == SDL_QUIT) { isRunning = false; }
		else { /*inputManager->handleEvent(event);*/ }
	}
}
