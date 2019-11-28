#pragma once
#include "Object.h"

namespace T2
{
	class FSM;

	class Entity : public Object
	{
	public:

		float health = 0.0f;
		float movementSpeed = 0.0f;

		FSM* stateMachine = nullptr;

		Entity();
		virtual ~Entity();
		void UpdateColliders();
	};
}