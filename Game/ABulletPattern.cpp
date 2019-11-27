#include "ABulletPattern.h"
#include "ServiceLocator.h"
#include "GameConfig.h"
#include "Bullet.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <ObjectPool.h>
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
	for (int i = 0; i < barrels.size(); i++)
	{
		if (spinning) { rotateGun(i); }
		dynamic_cast<Bullet*>(objPool->getObject(bulletTag))->transform.movementDirection = { barrels[i].x, barrels[i].y };
	}
}

void ABPattern::rotateGun(int barrel)
{
	float sinCalc = sin(10);
	float cosCalc = cos(10);

	barrels[barrel].x = ((barrels[barrel].x * cosCalc) - (barrels[barrel].y * sinCalc));
	barrels[barrel].y = ((barrels[barrel].y * cosCalc) - (barrels[barrel].x * sinCalc));
}
