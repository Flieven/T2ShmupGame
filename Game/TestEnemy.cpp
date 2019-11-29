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

	transform.Position = { 100, 100 };
	
	hpbarSprite = drawManager->LoadTexture(hpSprite, 1, 1, 10, 10, 1);

	sprite = drawManager->LoadTexture(enemySprite, 1, 1, enemyWidth, enemyHeight, 1);
	Obj_Rect = { (int)transform.Position.x, (int)transform.Position.y, enemyWidth, enemyHeight };

	collider->rectangle = { Obj_Rect.x, Obj_Rect.y, Obj_Rect.w, Obj_Rect.h };
	tag = enemyTag;
	stateMachine = new T2::FSM();

	//std::cout << transform.Position.x << std::endl;
	//std::cout << transform.Position.y << std::endl;

	stateMachine->addState("Patrol", new PatrolState(this));
	stateMachine->addState("Attack", new AttackState(this));
	stateMachine->changeState("Patrol");	
}

TestEnemy::~TestEnemy()
{
}

void TestEnemy::Update(float dTime)
{
	int hpBarWidth = enemyWidth * (health * 0.01);
	int hpBarHeight = 5;

	if(active)
	{
		Draw();
		UpdateColliders();
		stateMachine->updateState(dTime);
		collider->rectangle = { Obj_Rect.x, Obj_Rect.y, Obj_Rect.w, Obj_Rect.h };
		
		if (hpBarWidth <= 0)
		{
			active = false;
		}
	}
	
	hpRect = { (int)transform.Position.x, (int)transform.Position.y -10, hpBarWidth, hpBarHeight };
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

	case playerBulletTag:
		health -= 10;
		break;

	case enemyTag:
		break;
	}
}

void TestEnemy::setupObject(float x, float y)
{
	health = 100;
	transform.Position = { x, y };
	Obj_Rect = { (int)transform.Position.x, (int)transform.Position.y, enemyWidth, enemyHeight };
	collider->rectangle = { Obj_Rect.x, Obj_Rect.y, Obj_Rect.w, Obj_Rect.h };
}

void TestEnemy::setupGun(int numGuns, int rot, float delay, bool MoveAndShoot)
{
	shootMove = MoveAndShoot;
	if(gunPattern == nullptr) { gunPattern = new ABPattern(numGuns, rot, delay, this); }
	else { gunPattern->updateGun(numGuns, rot, delay); }
}
