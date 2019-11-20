#pragma once
#include "AbstractState.h"
#include "StaticIncluder.h"

#include <map>

//Finite State Machine
class FSM
{
public:
	
	std::map<std::string, AbstractState*> states;
	AbstractState* currentState;

	FSM();
	~FSM();

	void addState(std::string key, AbstractState* state);
	void changeState(std::string key);
	void updateState(float deltaTime);

	//Remove state?
};

