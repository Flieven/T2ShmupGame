#include "Bullet.h"
#include <InputManager.h>
#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>

Bullet::Bullet()
{
	sprite = drawManager->LoadTexture(bulletSprite, 1, 1, bulletWidth, bulletHeight, 1);
	movementSpeed = 0.03f;	
}

	bool pewPew = false;
Bullet::~Bullet()
{

}

void Bullet::Update(float dTime)
{
	float xScale = 1;
	float yScale = 1;
	Draw();
	
	if (pewPew)
	{
		fRect.y += movementSpeed;
		fRect = { fRect.x, fRect.y, sprite->getSource(0).w * xScale, sprite->getSource(0).h * yScale };
	}
}

void Bullet::Draw()
{
	drawManager->Render(sprite, fRect);
}

void Bullet::Fire()
{
	pewPew = true;
}

void Bullet::onCollision(Collision* other)
{

}

void Bullet::setupTextures(const char* texture)
{
	
}

void Bullet::setupObject(SDL_Rect rect)
{

}
