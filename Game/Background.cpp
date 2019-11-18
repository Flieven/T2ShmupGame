#include "Background.h"

#include <InputManager.h>
#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>


Background::Background()
{
	movementSpeed = 0.1;
	sprite = drawManager->LoadTexture(backgroundSprite, 1, 1, backgroundWidth, backgroundHeight, 1);
}

Background::~Background()
{
}

void Background::Update(float dTime)
{	
	float xScale = 5;
	float yScale = 5;

	float topY = 0;

	Draw();	

	Obj_RectTop = { (int)transform.Position.x , (int)topY * (int)yScale, sprite->getSource(0).w * (int)xScale, sprite->getSource(0).h * (int)yScale };
	//Obj_Rect = { (int)transform.Position.x , (int)transform.Position.y, sprite->getSource(0).w * (int)xScale, sprite->getSource(0).h * (int)yScale };
	//Obj_RectBottom = { (int)transform.Position.x , ((int)transform.Position.y + backgroundHeight * (int)yScale), sprite->getSource(0).w * (int)xScale, sprite->getSource(0).h * (int)yScale };
		
	topY += movementSpeed;
	
	if (Obj_RectTop.y > windowHeight) topY -= windowHeight * 3;	

	if (Obj_Rect.y > windowHeight) Obj_Rect.y -= windowHeight * 2;

	if (Obj_RectBottom.y > windowHeight) Obj_RectBottom.y -= windowHeight * 2;
	
	//transform.position kör vi istället om blabla
}

void Background::Draw()
{
	drawManager->Render(sprite, Obj_RectTop);
	drawManager->Render(sprite, Obj_Rect);
	drawManager->Render(sprite, Obj_RectBottom);
}

void Background::onCollision(Collision* other)
{
}
