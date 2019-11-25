#include "Bullet.h"
#include "GameConfig.h"

#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>
#include <InputManager.h>

Bullet::Bullet()
{
	sprite = drawManager->LoadTexture(bulletSprite, 1, 1, bulletWidth, bulletHeight, 1);
	movementSpeed = 0.1f;
}

Bullet::~Bullet()
{

}

void Bullet::Update(float dTime)
{
	if (active)
	{
		OutsideWindow();
		Draw();
		transform.Position.y += movementSpeed;
		fRect = { transform.Position.x, transform.Position.y, sprite->getSource(0).w * xScale, sprite->getSource(0).h * yScale };
	}
}

void Bullet::Draw()
{
	drawManager->Render(sprite, fRect);
}


void Bullet::onCollision(Collision* other)
{

}

void Bullet::OutsideWindow()
{
	if (fRect.y > windowHeight || fRect.y < 0 || fRect.x > windowWidth || fRect.x < 0)
	{
		active = false;
	}
}

void Bullet::setupTextures(const char* texture)
{

}

void Bullet::setupObject(SDL_Rect rect)
{

}
