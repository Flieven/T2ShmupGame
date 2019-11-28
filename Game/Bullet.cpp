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
	movementSpeed = 400.0f;	
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
		OutsideWindow();

		transform.Position.x += (movementSpeed * transform.normalize(transform.movementDirection).x * dTime);
		transform.Position.y += (movementSpeed * transform.normalize(transform.movementDirection).y * dTime);
		fRect = { transform.Position.x, transform.Position.y, sprite->getSource(0).w * transform.Scale.x, sprite->getSource(0).h * transform.Scale.y };
		collider->rectangle = { (int)fRect.x, (int)fRect.y, bulletWidth, bulletHeight };
	}
}

void Bullet::Draw()
{
	drawManager->Render(sprite, fRect);
	drawManager->DebugRender(collider->rectangle);
}

void Bullet::onCollision(int other)
{
	if (tag == enemyBulletTag)
	{
		switch (other)
		{
		case playerTag:			
			active = false;
			break;
		}
	}
	else if (tag == playerBulletTag)
	{
		switch (other)
		{
		case enemyTag:
			active = false;
			break;
		}
	}
}

void Bullet::OutsideWindow()
{
	if (transform.Position.x > windowWidth ||
		transform.Position.x < 0 ||
		transform.Position.y > windowHeight ||
		transform.Position.y < 0)
	{
		active = false;
	}
}

void Bullet::ResetBullet(T2::Transform::Vector2D vector2d,T2::Transform::Vector2D movDir, int givenTag)
{
	tag = givenTag;
	transform.movementDirection = movDir;
	transform.movementDirection.x = transform.movementDirection.x / 360;
	transform.movementDirection.y = transform.movementDirection.y / 360;

	//std::cout << "===== Changed values ===== \n";
	//std::cout << transform.movementDirection.x << std::endl;
	//std::cout << transform.movementDirection.y << std::endl;

	transform.Position = vector2d;
	fRect = { transform.Position.x, transform.Position.y, sprite->getSource(0).w * transform.Scale.x, sprite->getSource(0).h * transform.Scale.y };
	collider->rectangle = { (int)fRect.x, (int)fRect.y, Obj_Rect.w, Obj_Rect.h };
	UpdateColliders();
	active = true;
}
