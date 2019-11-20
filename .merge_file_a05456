#include "Player.h"

#include "GameConfig.h"
#include <ServiceLocator.h>
#include <DrawManager.h>
#include <Sprite.h>
#include <InputManager.h>

Player::Player()
{
	setupPlayer();
	inputManager = ServiceLocator<T2::Input>::getService();
	movementSpeed = 10;
	transform.Scale.x = 2;
	transform.Scale.y = 2;
	sprite = drawManager->LoadTexture(enemySprite, 1, 1, enemyWidth * transform.Scale.x, enemyHeight * transform.Scale.y, 1);
}

Player::~Player()
{
}

void Player::setupPlayer()
{
}

void Player::updateObject()
{
	Obj_Rect = { (int)transform.Position.x , (int)transform.Position.y, sprite->getSource(0).w, sprite->getSource(0).h };
}

void Player::Update(float dTime)
{
	checkInput();
	updateObject();
	Draw();
}

bool Player::checkInput()
{
	keyDown = false;
	if (inputManager->isKeyDown(SDL_SCANCODE_W)) { transform.Position.y -= movementSpeed; keyDown = true; }
	else if (inputManager->isKeyDown(SDL_SCANCODE_S)) { transform.Position.y += movementSpeed; keyDown = true; }

	if (inputManager->isKeyDown(SDL_SCANCODE_A)) { transform.Position.x -= movementSpeed; keyDown = true; }
	else if (inputManager->isKeyDown(SDL_SCANCODE_D)) { transform.Position.x += movementSpeed; keyDown = true; }

	return keyDown;
}

void Player::Draw()
{
	drawManager->Render(sprite, Obj_Rect);
}

void Player::onCollision(Collision* other)
{
}
