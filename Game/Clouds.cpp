#include "Clouds.h"

#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>

Cloud::Cloud()
{
	setupCloud();
	movementSpeed = 1;
	transform.Scale.x = 2;
	transform.Scale.y = 2;
	sprite = drawManager->LoadTexture(cloudSprite, 1, 1, cloudWidth * transform.Scale.x, cloudHeight * transform.Scale.y, 1);
}

Cloud::~Cloud(){}


void Cloud::setupCloud()
{
}

void Cloud::updateObject()
{
	Obj_Rect = { (int)transform.Position.x , (int)transform.Position.y, sprite->getSource(0).w, sprite->getSource(0).h };
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
