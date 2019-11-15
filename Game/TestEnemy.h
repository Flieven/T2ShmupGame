#pragma once

#include <Entity.h>

class TestEnemy : public T2::Entity
{
public:
	TestEnemy();
	~TestEnemy();

	void Update(float dTime);
	void Draw();
	void onCollision(Collision* other);
};