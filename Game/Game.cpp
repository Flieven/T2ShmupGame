#pragma once

#include <EngineEntry.h>
#include <ServiceLocator.h>

#include <InputManager.h>
#include <DrawManager.h>
#include <FactoryManager.h>
#include <ObjectPool.h>
#include <CollisionManager.h>
#include <UI_ButtonManager.h>
#include <UI_Button.h>

#include "ConcreteFactories.h"
#include "Player.h"
#include "Background.h"

#include "GameConfig.h"
#include "StaticIncluder.h"			
#include "Game.h"


// UI BUTTONS
void testButton()
{
	std::cout << "Button Clicked!" << std::endl;	
}

void quitButtonTest()
{	
	SDL_Quit();
}

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

	factoryManager = new T2::FactoryManager();

	colManager = new T2::CollisionManager();

	ServiceLocator<T2::Input>::setService(inputManager);
	ServiceLocator<T2::DrawManager>::setService(drawManager);
	ServiceLocator<T2::FactoryManager>::setService(factoryManager);
	ServiceLocator<T2::CollisionManager>::setService(colManager);

	objPool = new T2::ObjectPool();
	ServiceLocator<T2::ObjectPool>::setService(objPool);


	buttonManager = new T2::UI_ButtonManager();

	buttonManager->addButton({ 200, 200, 200, 200 }, "Play");
	buttonManager->getButton("Play")->pairFunction(testButton);

	buttonManager->addButton({ windowWidth - 50, (windowHeight + 10) - windowHeight, 40, 40 }, "Quit");
	buttonManager->getButton("Quit")->pairFunction(quitButtonTest);

	bgFactory = new BackgroundFactory();
	pFactory = new PlayerFactory();
	eFactory = new EnemyFactory();

	factoryManager->addFactory(backgroundTag, bgFactory);
	factoryManager->addFactory(playerTag, pFactory);
	factoryManager->addFactory(enemyTag, eFactory);

	objPool->getObject(backgroundTag);
	objPool->getObject(playerTag);	
	objPool->getObject(enemyTag);

	return true;
}

void ShmupGame::Shutdown()
{
	std::cout << "===== Yeet Engine =====" << std::endl;

	delete pFactory;
	pFactory = nullptr;

	delete factoryManager;
	factoryManager = nullptr;

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
		drawManager->Clear();
		objPool->Update(deltaTime);
		EventHandler();

		buttonManager->Update(deltaTime);
		drawManager->Present();
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
