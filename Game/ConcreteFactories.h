#pragma once
#include <AFactory.h>

#include "Player.h"
#include "TestEnemy.h"
#include "Background.h"
#include "Bullet.h"

namespace T2 { class AFactory; }

class Player;
class Bullet;

class PlayerFactory : public T2::AFactory
{
public:
	PlayerFactory() {}
	~PlayerFactory() {}

	T2::Object* createObject() { return new Player(); }
};

class EnemyFactory : public T2::AFactory
{
public:
	EnemyFactory() {}
	~EnemyFactory() {}

	T2::Object* createObject() { return new TestEnemy(); }
};

class BackgroundFactory : public T2::AFactory
{
public:
	BackgroundFactory() {}
	~BackgroundFactory() {}

	T2::Object* createObject() { return new Background(); }
};

class BulletFactory : public T2::AFactory
{
public:
	BulletFactory() {}
	~BulletFactory() {}

	T2::Object* createObject() { return new Bullet(); }
};