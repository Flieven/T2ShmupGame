#pragma once
#include "StaticIncluder.h"

#include <map>

//Finite State Machine
namespace T2 //Allt inom "T2Engine" skall vara i ett "T2" namespace.
{
	class AbstractState; // Forward Declaration: "This is a thing we will use, but we don't need to know exactly what it does".

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

