#include "Player.h"
#include "Bullet.h"

#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>
#include <InputManager.h>
#include <ObjectPool.h>

Player::Player()
{
	health = 100;
	transform.Position = { windowWidth * 0.5f, windowHeight * 0.8f };
	inputManager = ServiceLocator<T2::Input>::getService();
	objPool = ServiceLocator<T2::ObjectPool>::getService();	
	setupPlayer();
}

Player::~Player()
{
}

void Player::setupPlayer()
{
	sprite = drawManager->LoadTexture(playerSprite, 1, 1, playerWidth, playerHeight, 1);
	hpbarSprite = drawManager->LoadTexture(hpSprite, 1, 1, 10, 10, 1);
	movementSpeed = 0.1;
}

void Player::updateObject()
{
	Obj_Rect = { (int)transform.Position.x , (int)transform.Position.y, sprite->getSource(0).w, sprite->getSource(0).h };
	collider->rectangle = { Obj_Rect.x, Obj_Rect.y, Obj_Rect.w, Obj_Rect.h };	
}

void Player::Update(float dTime)
{
	int hpBarWidth = playerWidth * (health * 0.01);
	int hpBarHeight = 5;

	checkInput();
	updateObject();
	UpdateColliders();
	Draw();

	if (hpBarWidth <= 0)
	{
		active = false;
		std::cout << "Gaym ovah" << std::endl;
	}

	hpRect = { (int)transform.Position.x, (int)transform.Position.y - 10, hpBarWidth, hpBarHeight };
}

bool Player::checkInput()
{
	// movement
	keyDown = false;
	if (inputManager->isKeyDown(SDL_SCANCODE_W) ||inputManager->isKeyDown(SDL_SCANCODE_UP))
	{ transform.Position.y -= movementSpeed; keyDown = true; }

	else if (inputManager->isKeyDown(SDL_SCANCODE_S) || inputManager->isKeyDown(SDL_SCANCODE_DOWN))
	{ transform.Position.y += movementSpeed; keyDown = true; }

	if (inputManager->isKeyDown(SDL_SCANCODE_A) || inputManager->isKeyDown(SDL_SCANCODE_LEFT))
	{ transform.Position.x -= movementSpeed; keyDown = true; }

	else if (inputManager->isKeyDown(SDL_SCANCODE_D) || inputManager->isKeyDown(SDL_SCANCODE_RIGHT))
	{ transform.Position.x += movementSpeed; keyDown = true; }

	// fire bullet
	if (inputManager->isKeyDownOnce(SDL_SCANCODE_LCTRL) || inputManager->isKeyDownOnce(SDL_SCANCODE_RCTRL))
	{
		std::cout << transform.Position.x << std::endl;
		std::cout << transform.Position.y << std::endl;
		dynamic_cast<Bullet*>(objPool->getObject(bulletTag))->ResetBullet(transform.Position, transform.down, bulletTag);
		keyDown = true;
	}

	return keyDown;
}

void Player::Draw()
{
	drawManager->Render(sprite, Obj_Rect);
	drawManager->DebugRender(collider->rectangle);

	drawManager->Render(hpbarSprite, hpRect);
}

void Player::onCollision(int other)
{
	switch (other)
	{
	case enemyTag:
		health -= 0.01;
		break;
	}
}

//IMPLEMENT THESE WITH OBJECT POOL SO THAT WE CAN MAKE THE CLOUDY BOIS
void Player::setupTextures(const char* texture)
{
	textureList.push_back(texture);
}

void Player::setupObject(SDL_Rect rect)
{
	Obj_Rect = rect;
}
