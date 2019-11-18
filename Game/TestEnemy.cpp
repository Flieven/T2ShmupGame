#include "TestEnemy.h"

#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>
#include <InputManager.h>

TestEnemy::TestEnemy()
{	
	sprite = drawManager->LoadTexture(enemySprite, 1, 1, enemyWidth, enemyHeight, 1);
	Obj_Rect = { 100, 100, enemyWidth, enemyHeight };
	collider->rectangle = { Obj_Rect.x, Obj_Rect.y, Obj_Rect.w, Obj_Rect.h };
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
	}
}

void TestEnemy::Draw()
{
	drawManager->Render(sprite, Obj_Rect);
	drawManager->DebugRender(collider->rectangle);
}

void TestEnemy::onCollision(Collision* other)
{
}
