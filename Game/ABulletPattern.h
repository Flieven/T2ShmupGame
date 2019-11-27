#pragma once
#include <vector>
#include <Transform.h>

namespace T2
{
	class ObjectPool;
}

class ABPattern
{
private:
	int numSpawners = 0;
	bool spinning = false;
	float spawnDelay = 0.1f;

	T2::ObjectPool* objPool = nullptr;

	std::vector<T2::Transform::Vector2D> barrels;

public:
	ABPattern();
	ABPattern(int spawners, bool spin, float delay);
	~ABPattern();

	void setupGun();
	void spawnBullets();

};
