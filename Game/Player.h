#pragma once

#include <Entity.h>

namespace T2
{
	class Input;
	class ObjectPool;
}

class BulletFactory;

class Player : public T2::Entity
{
	

private:

	bool keyDown = false;
	
	void setupPlayer();
	void updateObject();

public:
	

	Player();
	~Player();

	T2::Input* inputManager = nullptr;
	T2::ObjectPool* objPool = nullptr;


	BulletFactory* bFactory = nullptr;

	void Update(float dTime);
	bool checkInput();
	void Draw();
	void onCollision(int other);
};