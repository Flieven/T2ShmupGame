#include "Bullet.h"
#include <InputManager.h>
#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>

Bullet::Bullet()
{
	transform.Scale.x = 1;
	transform.Scale.y = 1;
	sprite = drawManager->LoadTexture(bulletSprite, 1, 1, bulletWidth, bulletHeight, 1);
	collider->rectangle = { (int)fRect.x, (int)fRect.y, Obj_Rect.w, Obj_Rect.h };
	movementSpeed = 0.2f;	
}

Bullet::~Bullet()
{

}

void Bullet::Update(float dTime)
{	
	if (active)
	{
		UpdateColliders();
		Draw();

		transform.Position.y -= movementSpeed;		
		fRect = { transform.Position.x, transform.Position.y, sprite->getSource(0).w * transform.Scale.x, sprite->getSource(0).h * transform.Scale.y };
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
		active = false;
		break;
	}
}

void Bullet::ResetBullet(T2::Transform::Vector2D vector2d)
{
	transform.Position = vector2d;
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
