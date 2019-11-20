#pragma once

#include "Collider.h"
#include "Collision.h"

namespace T2
{
	class Collider;
	class Object;

	class CollisionManager
	{
	public:
		CollisionManager();
		~CollisionManager();

		static bool checkCollision(T2::Collider* objectA, T2::Collider* objectB);
		static bool checkCollision(T2::Object* objectA, T2::Object* objectB);

	};
}

