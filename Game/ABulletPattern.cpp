#include "ABulletPattern.h"
#include "ServiceLocator.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

ABPattern::ABPattern()
{
}

ABPattern::ABPattern(int spawners, bool spin, float delay)
{
	objPool = ServiceLocator<T2::ObjectPool>::getService();

	numSpawners = spawners;
	spinning = spin;
	spawnDelay = delay;

	barrels.reserve(numSpawners);

	setupGun();
}

ABPattern::~ABPattern()
{
}

void ABPattern::setupGun()
{
	T2::Transform::Vector2D pos;

	double angle = 0;
	std::vector<double> xPositions(numSpawners);
	std::vector<double> yPositions(numSpawners);

	double rad = 150;

	for (int i = 0; i < numSpawners; i++)
	{
		angle = i * (360 / numSpawners);
		float degree = (angle * 180 / M_PI);
		xPositions[i] = 0 + rad * cos(degree);
		yPositions[i] = 0 + rad * sin(degree);
		
		barrels.push_back(T2::Transform::Vector2D{ (float)xPositions[i], (float)yPositions[i] });
	}
}

void ABPattern::spawnBullets()
{
}
