#include "Entity.h"

T2::Entity::Entity()
{
}

T2::Entity::~Entity()
{
}

void T2::Entity::UpdateColliders()
{
	collider->bounds.left = collider->rectangle.x;
	collider->bounds.right = collider->rectangle.x + collider->rectangle.w;

	collider->bounds.up = collider->rectangle.y;
	collider->bounds.down = collider->rectangle.y + collider->rectangle.h;
}
