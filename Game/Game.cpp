#pragma once

#include <EngineEntry.h>
#include <ServiceLocator.h>

#include <StateManager.h>
#include <InputManager.h>
#include <DrawManager.h>
#include <TextManager.h>
#include <FactoryManager.h>
#include <ObjectPool.h>
#include <CollisionManager.h>
#include <UI_ButtonManager.h>
#include <UI_Button.h>

#include "ConcreteFactories.h"
#include "Player.h"
#include "Background.h"
#include "Bullet.h"

#include "GameConfig.h"
#include "StaticIncluder.h"			
#include "Game.h"

#include "GameState.h"
#include "MainMenuState.h"

bool ShmupGame::Initialize()
{
	std::cout << "===== Initalizing Engine =====" << std::endl;
	assert(SDL_Init(SDL_INIT_EVERYTHING) == 0 && "SDL_Init Failed to Initalize");
	assert(IMG_Init(IMG_INIT_PNG) != 0 && "IMG_Init Failed to Initalize");
	assert(Mix_Init(MIX_INIT_MP3) != 0 && "Mix_Init Failed to Initalize");
	assert(TTF_Init() == 0 && "TTF_Init Failed to Initialize");;

	inputManager = new T2::Input();
	ServiceLocator<T2::Input>::setService(inputManager);
	inputManager->initialize();

	drawManager = new T2::DrawManager();
	ServiceLocator<T2::DrawManager>::setService(drawManager);
	drawManager->InitWindow(windowWidth, windowHeight, windowTitle);	

	textManager = new T2::TextManager();
	ServiceLocator<T2::TextManager>::setService(textManager);
	
	factoryManager = new T2::FactoryManager();
	ServiceLocator<T2::FactoryManager>::setService(factoryManager);
	
	colManager = new T2::CollisionManager();
	ServiceLocator<T2::CollisionManager>::setService(colManager);

	objPool = new T2::ObjectPool();
	ServiceLocator<T2::ObjectPool>::setService(objPool);

	buttonManager = new T2::UI_ButtonManager();
	ServiceLocator<T2::UI_ButtonManager>::setService(buttonManager);

	stateManager = new T2::FSM();
	ServiceLocator<T2::FSM>::setService(stateManager);

	// Factory adds
	factoryManager->addFactory(backgroundTag, new BackgroundFactory());
	factoryManager->addFactory(playerTag,new PlayerFactory());
	factoryManager->addFactory(enemyTag, new EnemyFactory());
	factoryManager->addFactory(bulletTag,new BulletFactory());

	// State adds
	stateManager->addState("Game", new GameState("Game"));
	stateManager->addState("MainMenu", new MainMenuState("MainMenu"));

	stateManager->changeState("MainMenu");

	std::cout << "Start State: " << stateManager->currentState->stateName << std::endl;

	std::cout << "===== Engine Intialization completed =====" << std::endl;
	return true;
}

void ShmupGame::Shutdown()
{
	std::cout << "===== Yeet Engine =====" << std::endl;

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
		if (inputManager->isKeyDown(SDL_SCANCODE_ESCAPE))  { isRunning = false; }
		drawManager->Clear();
		stateManager->updateState(deltaTime);
		EventHandler();
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
