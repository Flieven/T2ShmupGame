#pragma once

#include <Entity.h>
#include <AbstractState.h>

class TestEnemy : public T2::Entity
{
public:
	TestEnemy();
	~TestEnemy();

	void Update(float dTime);
	void Draw();
	void onCollision(int other);

	// Inherited via Entity
	virtual void setupTextures(const char* texture) override;
	virtual void setupObject(SDL_Rect rect) override;
};


//Example EnemyState
class PatrolState : public T2::AbstractState
{
public:

	PatrolState() {};
	~PatrolState() {};

	virtual void Enter() override
	{

	}

	virtual void Run(float deltaTime) override
	{

	}

	virtual void Exit() override
	{

	}
};