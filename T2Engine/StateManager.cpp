#include "StateManager.h"

FSM::FSM()
{
}

FSM::~FSM()
{
}

void FSM::addState(std::string key, AbstractState* state)
{
	auto it = states.find(key);
	if (it != states.end()) {}
	else { states.insert(std::pair<std::string, AbstractState*>(key, state));  }
}

void FSM::changeState(std::string key)
{
	auto state = states.find(key);
	if (state != states.end() && state->first != currentState->stateName)
	{
		if (currentState != nullptr) { currentState->Exit(); }

		currentState = state->second;
		currentState->stateName = state->first;
		currentState->Enter();
	}

}

void FSM::updateState(float deltaTime)
{
	if (currentState != nullptr) { currentState->Run(deltaTime); }
}
