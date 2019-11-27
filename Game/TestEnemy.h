#pragma once

#include <Entity.h>
#include <AbstractState.h>
#include <StateManager.h>

#include "GameConfig.h"

class ABPattern;

class TestEnemy : public T2::Entity
{
public:
	TestEnemy();
	~TestEnemy();

	void Update(float dTime);
	void Draw();
	void onCollision(int other);

	ABPattern* gunPattern = nullptr; 

	// Inherited via Entity
	virtual void setupTextures(const char* texture) override;
	virtual void setupObject(SDL_Rect rect) override;
};


//Example EnemyState
class PatrolState : public T2::AbstractState, public T2::FSM
{
public:

	PatrolState(T2::Entity* ent) : newXPos(0), newYPos(0) { entity = ent; };
	~PatrolState() {};

	int newXPos;
	int newYPos;

	T2::Entity* entity = nullptr;

	virtual void Enter() override
	{
		newXPos = (std::rand() % windowWidth);
		newYPos = (std::rand() % windowHeight);
	}

	virtual void Run(float deltaTime) override
	{
		if (entity->transform.Distance( { (float)newXPos, (float)newYPos }) > 231)
		{
			entity->transform.Position = entity->transform.lerp(entity->transform.Position, { (float)newXPos, (float)newYPos }, deltaTime);
			entity->Obj_Rect = { (int)entity->transform.Position.x, (int)entity->transform.Position.y, enemyWidth, enemyHeight };
		}
		else
		{
			entity->stateMachine->changeState("Attack");
		}
	}

	virtual void Exit() override
	{

	}
};

class AttackState : public T2::AbstractState, public T2::FSM
{
public:
	AttackState(T2::Entity* ent) { entity = ent; };
	~AttackState() {};

	T2::Entity* entity = nullptr;

	virtual void Enter() override { }
	virtual void Run(float deltaTime) override { entity->stateMachine->changeState("Patrol"); }
	virtual void Exit() override { }
};