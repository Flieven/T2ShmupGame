#include "Background.h"

#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>

Background::Background()
{
	movementSpeed = 0.01;
	sprite = drawManager->LoadTexture(backgroundSprite, 1, 1, backgroundWidth, backgroundHeight, 1);	
}

Background::~Background()
{
}

void Background::Update(float dTime)
{
	float xScale = 5;
	float yScale = 5;
	Draw();
	Obj_Rect = { (int)transform.Position.x , (int)transform.Position.y, sprite->getSource(0).w * (int)xScale, sprite->getSource(0).h * (int)yScale };
	transform.Position.y += movementSpeed;
}

void Background::Draw()
{
	drawManager->Render(sprite, Obj_Rect);
}

void Background::onCollision(Collision* other)
{
}
