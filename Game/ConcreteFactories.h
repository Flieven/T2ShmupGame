#pragma once
#include <AFactory.h>

#include "Player.h"
#include "TestEnemy.h"

namespace T2 { class AFactory; }

class Player;

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