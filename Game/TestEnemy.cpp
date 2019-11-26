#include "TestEnemy.h"

#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>
#include <InputManager.h>
#include <iostream>

TestEnemy::TestEnemy()
{	
	health = 100;
	sprite = drawManager->LoadTexture(enemySprite, 1, 1, enemyWidth, enemyHeight, 1);
	Obj_Rect = { 100, 100, enemyWidth, enemyHeight };
	collider->rectangle = { Obj_Rect.x, Obj_Rect.y, Obj_Rect.w, Obj_Rect.h };
	tag = enemyTag;
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
	case bulletTag:
		health -= 10;
		std::cout << health << std::endl;
		break;
	}
}

void TestEnemy::setupTextures(const char* texture)
{
}

void TestEnemy::setupObject(SDL_Rect rect)
{
}
