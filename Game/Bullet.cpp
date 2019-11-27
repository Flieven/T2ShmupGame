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
	movementSpeed = 1000.0f;	
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

		float XDir = 0;
		float YDir = 0;
		if(transform.movementDirection.x < 0) { XDir = -1; }
		else { XDir = 1; }
		if (transform.movementDirection.y < 0) { YDir = -1; }
		else { YDir = 1; }


		transform.Position.x += (movementSpeed * sqrt(transform.movementDirection.x * transform.movementDirection.x) * dTime) * XDir;
		transform.Position.y += (movementSpeed * sqrt(transform.movementDirection.y * transform.movementDirection.y) * dTime) * YDir;
		fRect = { transform.Position.x, transform.Position.y, sprite->getSource(0).w * transform.Scale.x, sprite->getSource(0).h * transform.Scale.y };
		collider->rectangle = { (int)fRect.x, (int)fRect.y, Obj_Rect.w, Obj_Rect.h };

		std::cout << "===== SHOOTING ===== \n";
		std::cout << movementSpeed * sqrt(transform.movementDirection.x * transform.movementDirection.x) * dTime << std::endl;
		std::cout << movementSpeed * sqrt(transform.movementDirection.y * transform.movementDirection.y) * dTime << std::endl;
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
		//active = false;
		break;
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

void Bullet::setupTextures(const char* texture)
{
	
}

void Bullet::setupObject(SDL_Rect rect)
{
	
}
