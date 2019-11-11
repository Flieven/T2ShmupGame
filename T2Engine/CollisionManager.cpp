#include "CollisionManager.h"

bool CollisionManager::checkCollision(Collider* objectA, Collider* objectB)
{
	if (objectA->bounds.right < objectB->bounds.left ||
		objectB->bounds.right < objectA->bounds.left ||
		objectA->bounds.down < objectB->bounds.up ||
		objectB->bounds.down < objectA->bounds.up)
	{
		return false;
	}
	return true;
}

bool CollisionManager::checkCollision(Collision* objectA, Collision* objectB)
{
	if (CollisionManager::checkCollision(objectA->collider, objectB->collider))
	{
		objectA->onCollision(objectB);
		objectB->onCollision(objectB);
		return true;
	}
	return false;
}
