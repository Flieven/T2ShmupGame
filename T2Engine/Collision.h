#pragma once

#include "Collider.h"

namespace T2
{
	class Collision
	{
	public:

		Collision();
		Collision(Collider* col);
		virtual ~Collision();
		virtual void onCollision(Collision* other) = 0;
		Collider* collider = nullptr;

	};
}

