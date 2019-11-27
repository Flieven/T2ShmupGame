#include "GameState.h"
#include "GameConfig.h"

#include "ServiceLocator.h"
#include "ObjectPool.h"

#include "Object.h"

GameState::GameState()
{
}

GameState::GameState(std::string stateID)
{
	stateName = stateID;
	objPool = ServiceLocator<T2::ObjectPool>::getService();
}

GameState::~GameState()
{
}

void GameState::Enter()
{
	//INITIALIZE THINGS HERE
	objPool->getObject(backgroundTag)->active = true;
	objPool->getObject(playerTag)->active = true;
	objPool->getObject(enemyTag)->active = true;
	objPool->getObject(bulletTag);
}

void GameState::Run(float deltaTime)
{
	//GAME HERE
	objPool->Update(deltaTime);
	objPool->checkCollisions();
}

void GameState::Exit()
{
	//SHUTDOWN THINGS HERE
}
