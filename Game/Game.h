#pragma once

#include <EngineApplication.h>

namespace T2
{
	class Input;
	class DrawManager;
}

class ShmupGame : public T2::Engine
{
private:

	bool isRunning = true;

	void EventHandler();

	T2::Input* inputManager;
	T2::DrawManager* drawManager;

public:
	ShmupGame() : inputManager(nullptr), drawManager(nullptr) {}

	// Inherited via Engine
	virtual bool Initialize() override;
	virtual void Run() override;
	virtual void Shutdown() override;

};

T2::Engine* T2::createEngine() { return new ShmupGame(); }