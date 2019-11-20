#include "Clouds.h"

#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>

Cloud::Cloud()
{
	setupFarCloud();
	setupCloud();
	
}

Cloud::~Cloud(){}


void Cloud::setupCloud()
{
	movementSpeed = 1;
	transform.Scale.x = 2;
	transform.Scale.y = 2;
	
	sprite = drawManager->LoadTexture(cloudSprite, 1, 1, cloudWidth * transform.Scale.x, cloudHeight * transform.Scale.y, 1);

	//sprite = drawManager->LoadTexture(cloudSprite, 1, 1, cloudWidth * transform.Scale.x, cloudHeight * transform.Scale.y, 1);

}

void Cloud::setupFarCloud()
{	
	movementSpeed = 0.4;
	transform.Scale.x = 1.5;
	transform.Scale.y = 1.5;
	sprite = drawManager->LoadTexture(playerSprite, 1, 1, cloudWidth * transform.Scale.x, cloudHeight * transform.Scale.y, 1);
}

void Cloud::updateObject()
{
	Obj_Rect = { (int)transform.Position.x , (int)transform.Position.y, sprite->getSource(0).w, sprite->getSource(0).h };
	transform.Position.y += movementSpeed;

}

void Cloud::Update(float dTime)
{
	updateObject();	
	Draw();
}

void Cloud::Draw()
{
	drawManager->Render(sprite, Obj_Rect);
}

void Cloud::onCollision(Collision* other)
{
}
