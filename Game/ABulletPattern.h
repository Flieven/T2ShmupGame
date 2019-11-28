#pragma once
#include <vector>
#include <Transform.h>

namespace T2
{
	class ObjectPool;
	class Entity;
	class Timer;
}

class ABPattern
{
private:
	int numSpawners = 0;
	bool spinning = false;
	float spawnDelay = 0.1f;
	float currentSpin = 80.0;

	T2::ObjectPool* objPool = nullptr;
	T2::Entity* owner = nullptr;
	T2::Timer* timer = nullptr;

	std::vector<T2::Transform::Vector2D> barrels;

public:
	ABPattern();
	ABPattern(int spawners, bool spin, float delay, T2::Entity* givenOwner);
	~ABPattern();

	void setupGun();
	void spawnBullets(float dTime, T2::Transform::Vector2D center);
	void rotateGun(int barrel, T2::Transform::Vector2D center);

};
