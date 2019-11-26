#include "TestEnemy.h"

#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <StateManager.h>
#include <Sprite.h>
#include <InputManager.h>
#include <iostream>

TestEnemy::TestEnemy()
{	
	health = 100;
	transform.Position = { windowWidth * 0.5f, 0 };

	sprite = drawManager->LoadTexture(enemySprite, 1, 1, enemyWidth, enemyHeight, 1);
	Obj_Rect = { (int)transform.Position.x, (int)transform.Position.y, enemyWidth, enemyHeight };
	collider->rectangle = { Obj_Rect.x, Obj_Rect.y, Obj_Rect.w, Obj_Rect.h };
	tag = enemyTag;
	stateMachine = new T2::FSM();

	std::cout << transform.Position.x << std::endl;
	std::cout << transform.Position.y << std::endl;

	stateMachine->addState("Patrol", new PatrolState(this));
	stateMachine->addState("Attack", new AttackState(this));
	stateMachine->changeState("Patrol");
}

TestEnemy::~TestEnemy()
{
}

void TestEnemy::Update(float dTime)
{
	if(active)
	{
		Draw();
		UpdateColliders();
		stateMachine->updateState(dTime);
		collider->rectangle = { Obj_Rect.x, Obj_Rect.y, Obj_Rect.w, Obj_Rect.h };
		if (health <= 0)
		{
			active = false;
		}
	}
}

void TestEnemy::Draw()
{
	drawManager->Render(sprite, Obj_Rect);
	drawManager->DebugRender(collider->rectangle);
}

void TestEnemy::onCollision(int other)
{
	switch (other)
	{
	case playerTag:; break;
	case bulletTag:
		health -= 10;		
		break;
	case enemyTag:; break;
	}
}

void TestEnemy::setupTextures(const char* texture)
{
}

void TestEnemy::setupObject(SDL_Rect rect)
{
}
