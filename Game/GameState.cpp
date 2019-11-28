#include "GameState.h"
#include "GameConfig.h"

#include "ServiceLocator.h"
#include "ObjectPool.h"

#include "Object.h"
#include "Entity.h"
#include "TestEnemy.h"

#include <Timer.h>

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

	spawnTimer = new T2::Timer();

	spawnTimer->setTimer(2.0f);

	for (int i = 0; i < enemies.size(); i++) { if (enemies[i] == nullptr) { enemies[i] = dynamic_cast<T2::Entity*>(objPool->getObject(enemyTag)); } }
}

void GameState::Run(float deltaTime)
{
	//GAME HERE
	objPool->Update(deltaTime);
	objPool->checkCollisions();
	if (!spawnTimer->timerFinished) { spawnTimer->Update(deltaTime); /*std::cout << "Timer update. \n";*/ }
	else { addEnemy(); /*std::cout << "Add enemy \n";*/ }
}

void GameState::Exit()
{
	//SHUTDOWN THINGS HERE
}

void GameState::addEnemy()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (!enemies[i]->active)
		{
			dynamic_cast<TestEnemy*>(enemies[i])->setupObject(spawnPos.x, spawnPos.y);

			int randGuns = rand() % 6 + 1;
			
			int randShootMove = rand() % 2;
			int randSpinning = rand() % 2;
			float delay = 0.0f;
			int spinDir = 0;

			std::cout << "ShootMove: " << randShootMove << std::endl;
			std::cout << "Delay: " << delay << std::endl;
			std::cout << "Guns: " << randGuns << std::endl;
			std::cout << "Spinning: " << randSpinning << std::endl;
			std::cout << "SpinDir: " << spinDir << std::endl;

			if (randShootMove) { delay = rand() % 1 + 0.5f; }

			if (randSpinning) { spinDir = rand() % 15 + -15; }

			dynamic_cast<TestEnemy*>(enemies[i])->setupGun(randGuns, spinDir, delay, randShootMove);
			enemies[i]->active = true;
			break;
		}
	}
	spawnTimer->RestartTimer();
}
