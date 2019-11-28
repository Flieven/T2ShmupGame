#pragma once

#include <Entity.h>
#include <AbstractState.h>
#include <StateManager.h>

#include "GameConfig.h"
#include "ABulletPattern.h"

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
	bool shootMove = false;

	void setupObject(float x, float y);
	void setupGun(int numGuns, int rot, float delay, bool MoveAndShoot);
};


//Example EnemyState
class PatrolState : public T2::AbstractState, public T2::FSM
{
public:

	PatrolState(TestEnemy* ent) : newXPos(0), newYPos(0) { entity = ent; };
	~PatrolState() {};

	int newXPos;
	int newYPos;

	TestEnemy* entity = nullptr;

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
			
			if (entity->shootMove)
			{
				entity->gunPattern->spawnBullets(deltaTime, entity->transform.Position);
			}
		}
		else
		{
			if (!entity->shootMove)
			{
				entity->stateMachine->changeState("Attack");
			}
			else
			{
				newXPos = (std::rand() % windowWidth);
				newYPos = (std::rand() % windowHeight);
			}
		}
	}

	virtual void Exit() override
	{

	}
};

class AttackState : public T2::AbstractState, public T2::FSM
{
public:
	AttackState(TestEnemy* ent) { entity = ent; };
	~AttackState() {};

	TestEnemy* entity = nullptr;

	virtual void Enter() override 
	{ 
	}
	virtual void Run(float deltaTime) override 
	{
		entity->gunPattern->spawnBullets(deltaTime, entity->transform.Position);
		entity->stateMachine->changeState("Patrol"); 
	}
	virtual void Exit() override { }
};