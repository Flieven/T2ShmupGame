#pragma once

#include "Collider.h"
#include "Collision.h"


class Collider;
class Collision;

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	static bool checkCollision(Collider* objectA, Collider* objectB);
	static bool checkCollision(Collision* objectA, Collision* objectB);

};

