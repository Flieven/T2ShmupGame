#pragma once
#include "StaticIncluder.h"

class AbstractState
{
public:

	std::string stateName = "";

	AbstractState();
	virtual ~AbstractState();

	virtual void Enter();
	virtual void Run(float deltaTime);
	virtual void Exit();
};

