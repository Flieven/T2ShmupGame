#include "GameState.h"
#include "GameConfig.h"

#include "ServiceLocator.h"
#include "ObjectPool.h"

#include "Object.h"
#include "Entity.h"
#include "TestEnemy.h"

#include <Timer.h>
#include <cstdlib>
#include <ctime>

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
	objPool->addNewPool(enemyTag);

	srand(std::time(NULL));

	spawnTimer = new T2::Timer();

	spawnTimer->setTimer(10.0f);
	spawnTimer->timerFinished = true;

	for (int i = 0; i < enemies.size(); i++) 
	{ 
		if (enemies[i] == nullptr) 
		{ 
			objPool->addObjectToPool(new TestEnemy(), enemyTag); 
			enemies[i] = dynamic_cast<T2::Entity*>(objPool->getSpecificObject(enemyTag, i)); 
		} 
	}
}

void GameState::Run(float deltaTime)
{
	//GAME HERE
	objPool->Update(deltaTime);
	objPool->checkCollisions();
	if (!spawnTimer->timerFinished) { spawnTimer->Update(deltaTime); /*std::cout << "Timer update. \n";*/ }
	else { addEnemy(); spawnTimer->RestartTimer(); }
}

void GameState::Exit()
{
	//SHUTDOWN THINGS HERE
	objPool->clearPools();
}

void GameState::addEnemy()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		std::cout << "Enemy: " << i << std::endl;
		std::cout << "Active: " << enemies[i]->active << std::endl;
		if (!enemies[i]->active)
		{
			std::cout << " ===== NEW ENEMY ===== \n";
			dynamic_cast<TestEnemy*>(enemies[i])->setupObject(spawnPos.x, spawnPos.y);

			int randGuns = std::rand() % 6 + 1;
			
			int randShootMove = std::rand() % 2;
			int randSpinning = std::rand() % 2;
			float delay = 0.0f;
			int spinDir = 0;

			if (randShootMove) 
			{ 
				delay = std::rand() % (11 - 5) + 5; 
				std::cout << "Pre-edit Delay: " << delay << std::endl;
				delay /= 10;
			}


			if (randSpinning) { spinDir = std::rand() % 31 + (-15); }
			std::cout << "ShootMove: " << randShootMove << std::endl;
			std::cout << "Delay: " << delay << std::endl;
			std::cout << "Guns: " << randGuns << std::endl;
			std::cout << "Spinning: " << randSpinning << std::endl;
			std::cout << "SpinDir: " << spinDir << std::endl;

			dynamic_cast<TestEnemy*>(enemies[i])->setupGun(randGuns, spinDir, delay, randShootMove);
			enemies[i]->active = true;
			std::cout << "Enemy: " << i << std::endl;
			std::cout << "Active: " << enemies[i]->active << std::endl;
			break;
		}
	}
	spawnTimer->RestartTimer();
}
