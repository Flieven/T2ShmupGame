#include "Collision.h"

T2::Collision::Collision()
{
	collider = new Collider();
}

T2::Collision::Collision(T2::Collider* col)
{
	collider = col;
}

T2::Collision::~Collision()
{
	delete collider;
	collider = nullptr;
}
