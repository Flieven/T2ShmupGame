#pragma once

#include <EngineApplication.h>

namespace T2
{
	class Input;
}

class ShmupGame : public T2::Engine
{
private:

	bool isRunning = true;

	void EventHandler();

	T2::Input* inputManager;

public:
	ShmupGame() : inputManager(nullptr) {}

	// Inherited via Engine
	virtual bool Initialize() override;
	virtual void Run() override;
	virtual void Shutdown() override;

};

T2::Engine* T2::createEngine() { return new ShmupGame(); }