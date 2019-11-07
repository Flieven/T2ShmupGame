#pragma once

#include "EngineApplication.h"

extern T2::Engine* T2::createEngine();


int main(int argc, char* argv[])
{
	T2::Engine* gameEngine = T2::createEngine();

	if (!gameEngine->Initialize())
	{
		gameEngine->Shutdown();
		delete gameEngine;
		return -1;
	}

	gameEngine->Run();

	gameEngine->Shutdown();
	delete gameEngine;

	return 0;
}