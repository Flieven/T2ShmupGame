#pragma once

#include <EngineApplication.h>

namespace T2
{
	class Input;
	class DrawManager;
	class FactoryManager;
	class ObjectPool;
}

class PlayerFactory;
class Player;

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

	PlayerFactory* pFactory;
	Player* player;

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