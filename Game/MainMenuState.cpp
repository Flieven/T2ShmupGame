#include "MainMenuState.h"
#include "ServiceLocator.h"
#include "UI_ButtonManager.h"
#include "UI_Button.h"
#include "GameConfig.h"
#include "StateManager.h"

#include <iostream>

MainMenuState::MainMenuState() : buttonManager(nullptr), stateMachine(nullptr)
{
}

MainMenuState::MainMenuState(std::string stateID)
{
	stateName = stateID;
	buttonManager = ServiceLocator<T2::UI_ButtonManager>::getService();
	stateMachine = ServiceLocator<T2::FSM>::getService();
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Enter()
{
	buttonManager->addButton({ 200, 200, 200, 100 }, "Play", 102);
	buttonManager->getButton("Play")->pairFunction(std::bind(&MainMenuState::btnPlay, this));

	buttonManager->addButton({ 200, 500, 200, 100 }, "Options", 102);
	buttonManager->getButton("Options")->pairFunction(std::bind(&MainMenuState::btnOptions, this));

	buttonManager->addButton({ windowWidth - 50, (windowHeight + 10) - windowHeight, 40, 40 }, "Quit", 86);
	buttonManager->getButton("Quit")->pairFunction(std::bind(&MainMenuState::btnQuit, this));
}

void MainMenuState::Run(float deltaTime)
{
	buttonManager->Update(deltaTime);
}

void MainMenuState::Exit()
{
}

void MainMenuState::btnPlay()
{
	stateMachine->changeState("Game");
}

void MainMenuState::btnOptions()
{
	std::cout << "Options button Pressed." << std::endl;
}

void MainMenuState::btnQuit()
{
	SDL_Quit();
}
