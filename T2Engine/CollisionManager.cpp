#include "CollisionManager.h"

#include "Object.h"

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

bool T2::CollisionManager::checkCollision(T2::Object* objectA, T2::Object* objectB)
{
	if (T2::CollisionManager::checkCollision(objectA->collider, objectB->collider))
	{
		objectA->onCollision(objectB->tag);
		objectB->onCollision(objectA->tag);
		return true;
	}
	return false;
}
