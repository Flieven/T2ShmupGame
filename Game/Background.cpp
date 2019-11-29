#include "Background.h"

#include <InputManager.h>
#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>

Background::Background()
{
	sprite = drawManager->LoadTexture(backgroundSprite, 1, 1, backgroundWidth, backgroundHeight, 1);
}

Background::~Background()
{
}

float y2 = (float)-windowHeight; // spawn 2 "one screen up"
void Background::Update(float dTime)
{	
	Draw();	
	
	movementSpeed = 0.03f;
	float xScale = 1;
	float yScale = 1;

	fRect.y += movementSpeed;
	y2 += movementSpeed;

	fRect = { fRect.x, fRect.y, sprite->getSource(0).w * xScale, sprite->getSource(0).h * yScale };
	if (fRect.y > windowHeight) { fRect.y -= windowHeight * 2; }	
	
	fRect2 = { fRect2.x, y2, sprite->getSource(0).w * xScale, sprite->getSource(0).h * yScale };
	if (y2 > windowHeight) { y2 -= windowHeight * 2; }	
}

void Background::Draw()
{
	drawManager->Render(sprite, fRect);
	drawManager->Render(sprite, fRect2);
}

void Background::onCollision(Collision* other)
{
}
