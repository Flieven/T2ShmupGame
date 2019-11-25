#include "StateManager.h"
#include "AbstractState.h"
#include <string>

T2::FSM::FSM() : currentState(nullptr)
{
}

T2::FSM::~FSM()
{
}

void T2::FSM::addState(std::string key, AbstractState* state)
{
	auto it = states.find(key);
	if (it != states.end()) {}
	else { states.insert(std::pair<std::string, AbstractState*>(key, state));  }
}

void T2::FSM::changeState(std::string key)
{
	auto state = states.find(key);
	if (currentState != nullptr)
	{
		if (state != states.end() && state->first != currentState->stateName)
		{
			if (currentState != nullptr) { currentState->Exit(); }

			currentState = state->second;
			currentState->Enter();
		}
	}
	else
	{
		currentState = state->second;
		currentState->Enter();
	}
}

void T2::FSM::updateState(float deltaTime)
{
	if (currentState != nullptr) { currentState->Run(deltaTime); }
}
