#pragma once

#include <EngineEntry.h>
#include <ServiceLocator.h>

#include <InputManager.h>
#include <DrawManager.h>

#include "Player.h"
#include "Clouds.h"

#include "GameConfig.h"
#include "StaticIncluder.h"			
#include "Game.h"

bool ShmupGame::Initialize()
{
	std::cout << "===== Initalizing Engine =====" << std::endl;
	assert(SDL_Init(SDL_INIT_EVERYTHING) == 0 && "SDL_Init Failed to Initalize");
	assert(IMG_Init(IMG_INIT_PNG) != 0 && "IMG_Init Failed to Initalize");
	assert(Mix_Init(MIX_INIT_MP3) != 0 && "Mix_Init Failed to Initalize");
	assert(TTF_Init() == 0 && "TTF_Init Failed to Initialize");;

	inputManager = new T2::Input();
	inputManager->initialize();

	drawManager = new T2::DrawManager();
	drawManager->InitWindow(windowWidth, windowHeight, windowTitle);	

	ServiceLocator<T2::Input>::setService(inputManager);
	ServiceLocator<T2::DrawManager>::setService(drawManager);	

	player = new Player();
	cloud = new Cloud();

	return true;
}

void ShmupGame::Shutdown()
{
	std::cout << "===== Yeet Engine =====" << std::endl;

	drawManager->Shutdown();
	delete drawManager;
	drawManager = nullptr;

	inputManager->shutdown();
	delete inputManager;
	inputManager = nullptr;

	std::cout << "===== Yeet SDL =====" << std::endl;
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

void ShmupGame::Run()
{
	while (isRunning)
	{
		if (inputManager->isKeyDown(SDL_SCANCODE_ESCAPE)) { isRunning = false; }
		EventHandler();
		drawManager->Clear();

		player->Update(deltaTime);
		cloud->Update(deltaTime);

		drawManager->Present();
		SDL_Delay(10);

	}
	
	
}

void ShmupGame::EventHandler()
{
	SDL_Event event;

	while (SDL_PollEvent(&event) == 1)
	{
		if (event.type == SDL_QUIT) { isRunning = false; }
		else { inputManager->handleEvent(event); }
	}
}

void ShmupGame::CalcDeltaTime()
{
	deltaTime = 0.001f * (SDL_GetTicks() - lastTick);
	lastTick = SDL_GetTicks();
}
