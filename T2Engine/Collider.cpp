#include "Collider.h"


T2::Collider::Collider()
{
	bounds.left = rectangle.x;
	bounds.right = rectangle.x + rectangle.w;

	bounds.up = rectangle.y;
	bounds.down = rectangle.y + rectangle.h;
}

T2::Collider::~Collider()
{
}
