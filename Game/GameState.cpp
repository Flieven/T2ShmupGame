#include "GameState.h"
#include "GameConfig.h"

#include "ServiceLocator.h"
#include "ObjectPool.h"

#include "Object.h"
#include "TestEnemy.h"

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
	dynamic_cast<TestEnemy*>(objPool->getSpecificObject(enemyTag, 0))->setupGun(100, 0, 0.0f, false);

	//objPool->getObject(enemyTag)->active = true;
	//dynamic_cast<TestEnemy*>(objPool->getSpecificObject(enemyTag, 1))->setupObject(300, 100, true);
	//dynamic_cast<TestEnemy*>(objPool->getSpecificObject(enemyTag, 1))->setupGun(2, 10, 0.05f);

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
