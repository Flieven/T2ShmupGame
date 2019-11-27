#include "ABulletPattern.h"
#include "ServiceLocator.h"
#include "GameConfig.h"
#include "Bullet.h"
#include "Entity.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <complex>

#include <ObjectPool.h>
#include <iostream>

ABPattern::ABPattern()
{
}

ABPattern::ABPattern(int spawners, bool spin, float delay, T2::Entity* givenOwner)
{
	objPool = ServiceLocator<T2::ObjectPool>::getService();
	owner = givenOwner;

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
	double angle = 0;
	std::vector<double> xPositions(numSpawners);
	std::vector<double> yPositions(numSpawners);

	double rad = 150;

	for (int i = 0; i < numSpawners; i++)
	{
		angle = i * (360 / numSpawners) + 90;
		float degree = (angle * (M_PI / 180));
		xPositions[i] = 0 + rad * cos(degree);
		yPositions[i] = 0 + rad * sin(degree);
		//std::cout << "Degree: " << degree << std::endl;
		//std::cout << "Degree: " << cos(degree) << std::endl;
		//std::cout << "rad: " << rad << std::endl;
		//std::cout << "result: " << (float)cos(degree) * rad << std::endl;

		barrels.push_back(T2::Transform::Vector2D{ (float)xPositions[i], (float)yPositions[i] });
	
		std::cout << "===== X/Y POSITIONS ===== \n";
		std::cout << xPositions[i] << std::endl;
		std::cout << yPositions[i] << std::endl;
	}
}

void ABPattern::spawnBullets(T2::Transform::Vector2D center)
{
	for (int i = 0; i < barrels.size(); i++)
	{
		if (spinning) { rotateGun(i, center); }
		dynamic_cast<Bullet*>(objPool->getObject(bulletTag))->ResetBullet({ owner->transform.Position.x + ((enemyWidth / 2) - (bulletWidth/2)) , owner->transform.Position.y + ((enemyHeight /2) - (bulletHeight / 2)) }, barrels[i], bulletTag);
	}
}

//TODO: FIX THIS SHIT.
void ABPattern::rotateGun(int barrel, T2::Transform::Vector2D center)
{
	barrels[barrel].x = cos(M_PI / 18) * (barrels[barrel].x - center.x) - sin(M_PI / 18) * (barrels[barrel].y - center.y) + center.x;
	barrels[barrel].y = cos(M_PI / 18) * (barrels[barrel].x - center.x) - sin(M_PI / 18) * (barrels[barrel].y - center.y) + center.y;
}
