#pragma once
#include "Object.h"

namespace T2
{
	class Entity : public Object
	{
	public:

		float health;
		float movementSpeed;

		Entity();
		virtual ~Entity();
	};
}