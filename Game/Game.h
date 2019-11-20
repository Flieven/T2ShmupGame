#pragma once

#include <EngineApplication.h>

namespace T2
{
	class Input;
	class DrawManager;
	class FactoryManager;
	class ObjectPool;
	class CollisionManager;
}

class PlayerFactory;
class EnemyFactory;
class Player;
class TestEnemy;

class ShmupGame : public T2::Engine
{
private:

	bool isRunning = true;

	void EventHandler();
	void CalcDeltaTime();

	T2::Input* inputManager = nullptr;
	T2::DrawManager* drawManager = nullptr;
	T2::FactoryManager* factoryManager = nullptr;
	T2::ObjectPool* objPool = nullptr;
	T2::CollisionManager* colManager = nullptr;

	PlayerFactory* pFactory = nullptr;
	EnemyFactory* eFactory = nullptr;
	Player* player = nullptr;
	TestEnemy* enemy = nullptr;

	float deltaTime = 0.0f;
	float lastTick = 0.0f;

public:
	ShmupGame() {}

	// Inherited via Engine
	virtual bool Initialize() override;
	virtual void Run() override;
	virtual void Shutdown() override;

};

T2::Engine* T2::createEngine() { return new ShmupGame(); }