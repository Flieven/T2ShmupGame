#pragma once
#include "StaticIncluder.h"

#include <map>

namespace T2
{
	class AbstractState;

	class FSM
	{
	public:

		std::map<std::string, T2::AbstractState*> states;
		T2::AbstractState* currentState = nullptr;

		FSM();
		~FSM();

		void addState(std::string key, AbstractState* state);
		void changeState(std::string key);
		void updateState(float deltaTime);

		//Remove state?
	};
}

