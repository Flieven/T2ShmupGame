#include "Bullet.h"

#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>
#include <InputManager.h>

Bullet::Bullet()
{
	sprite = drawManager->LoadTexture(bulletSprite, 1, 1, bulletWidth, bulletHeight, 1);
	Obj_Rect = { 10, 100, bulletWidth, bulletHeight };
	collider->rectangle = { Obj_Rect.x, Obj_Rect.y, Obj_Rect.w, Obj_Rect.h };
	tag = bulletTag;
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
		UpdateColliders();
		transform.Position.y -= movementSpeed;
		fRect = { transform.Position.x, transform.Position.y, sprite->getSource(0).w * xScale, sprite->getSource(0).h * yScale };
		collider->rectangle = { (int)fRect.x, (int)fRect.y, Obj_Rect.w, Obj_Rect.h };
	}
}

void Bullet::Draw()
{
	drawManager->Render(sprite, fRect);
	drawManager->DebugRender(collider->rectangle);
}


void Bullet::onCollision(int other)
{
	switch (other)
	{
	case enemyTag:
		std::cout << "Bullet collide with enemy" << std::endl;
		active = false;
		break;
	}
}

void Bullet::OutsideWindow()
{
	if (fRect.y > windowHeight || fRect.y < 0 || fRect.x > windowWidth || fRect.x < 0)
	{
		active = false;
	}
}

void Bullet::ResetBullet(T2::Transform::Vector2D vector2d)
{
	transform.Position = vector2d;

	fRect = { transform.Position.x, transform.Position.y, sprite->getSource(0).w * xScale, sprite->getSource(0).h * yScale };
	collider->rectangle = { (int)fRect.x, (int)fRect.y, Obj_Rect.w, Obj_Rect.h };
	UpdateColliders();
	active = true;
}

void Bullet::setupTextures(const char* texture)
{

}

void Bullet::setupObject(SDL_Rect rect)
{

}
