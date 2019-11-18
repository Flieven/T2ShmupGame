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
class BackgroundFactory;
class Player;
class TestEnemy;
class Background;

class ShmupGame : public T2::Engine
{
private:

	bool isRunning = true;

	void EventHandler();
	void CalcDeltaTime();

	T2::Input* inputManager;
	T2::DrawManager* drawManager;
	T2::FactoryManager* factoryManager;
	T2::ObjectPool* objPool;
	T2::CollisionManager* colManager;

	PlayerFactory* pFactory;
	EnemyFactory* eFactory;
	BackgroundFactory* bgFactory;
	Player* player;
	TestEnemy* enemy;
	Background* background;

	float deltaTime = 0.0f;
	float lastTick = 0.0f;

public:
	ShmupGame() : inputManager(nullptr), drawManager(nullptr) {}

	// Inherited via Engine
	virtual bool Initialize() override;
	virtual void Run() override;
	virtual void Shutdown() override;

};

T2::Engine* T2::createEngine() { return new ShmupGame(); }