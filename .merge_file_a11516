#include "CollisionManager.h"

T2::CollisionManager::CollisionManager()
{
}

T2::CollisionManager::~CollisionManager()
{
}

bool T2::CollisionManager::checkCollision(T2::Collider* objectA, T2::Collider* objectB)
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

bool T2::CollisionManager::checkCollision(T2::Collision* objectA, T2::Collision* objectB)
{
	if (T2::CollisionManager::checkCollision(objectA->collider, objectB->collider))
	{
		objectA->onCollision(objectB);
		objectB->onCollision(objectB);
		return true;
	}
	return false;
}
