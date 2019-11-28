#include "TestEnemy.h"

#include "GameConfig.h"
#include "ABulletPattern.h"

#include <ServiceLocator.h>
#include <DrawManager.h>
#include <StateManager.h>
#include <Sprite.h>
#include <InputManager.h>
#include <iostream>

TestEnemy::TestEnemy()
{	
	health = 100;

	gunPattern = new ABPattern(3, false, 1.0f);

	transform.Position = { 100, 100 };
	
	hpbarSprite = drawManager->LoadTexture(hpSprite, 1, 1, 10, 10, 1);		
	hpRect = { (int)transform.Position.x, (int)transform.Position.y, enemyWidth, enemyHeight  };

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
	int hpBar = enemyWidth * (health * 0.01);
	if(active)
	{
		Draw();
		UpdateColliders();
		stateMachine->updateState(dTime);
		collider->rectangle = { Obj_Rect.x, Obj_Rect.y, Obj_Rect.w, Obj_Rect.h };
		
		if (hpBar <= 0)
		{
			active = false;
		}
	}
	
	hpRect = { (int)transform.Position.x, (int)transform.Position.y, (int)hpBar, enemyHeight / 5 };
}

void TestEnemy::Draw()
{
	drawManager->Render(sprite, Obj_Rect);	
	drawManager->DebugRender(collider->rectangle);

	drawManager->Render(hpbarSprite, hpRect);
}

void TestEnemy::onCollision(int other)
{
	switch (other)
	{
	case playerTag:
		break;

	case bulletTag:
		health -= 10;
		break;

	case enemyTag:
		break;
	}
}

void TestEnemy::setupTextures(const char* texture)
{
}

void TestEnemy::setupObject(SDL_Rect rect)
{
}
