#pragma once

#include <EngineApplication.h>

namespace T2
{
	class Input;
	class DrawManager;
	class FactoryManager;
	class ObjectPool;
	class CollisionManager;
	class UI_ButtonManager;
	class TextManager;
}

class PlayerFactory;
class EnemyFactory;
class BulletFactory;
class Player;
class TestEnemy;
class Bullet;

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
	T2::UI_ButtonManager* buttonManager = nullptr;
	T2::TextManager* textManager = nullptr;

	BackgroundFactory* bgFactory = nullptr;
	PlayerFactory* pFactory = nullptr;
	EnemyFactory* eFactory = nullptr;
	BulletFactory* bFactory = nullptr;
	Background* background = nullptr;
	Player* player = nullptr;
	TestEnemy* enemy = nullptr;
	Bullet* bullet = nullptr;

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

void btnPlay();