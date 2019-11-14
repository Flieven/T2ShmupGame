#pragma once
#include <AFactory.h>
#include "Player.h"

class Player;

class PlayerFactory : public T2::AFactory
{

public:
	PlayerFactory() {}
	~PlayerFactory() {}

	T2::Object* createObject() { return new Player(); }
	//Is this pointer? Or just a straight object?
};
