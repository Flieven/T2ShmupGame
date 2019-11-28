#include "ABulletPattern.h"
#include "ServiceLocator.h"
#include "GameConfig.h"
#include "Bullet.h"
#include "Entity.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <complex>

#include <ObjectPool.h>
#include <Timer.h>
#include <iostream>

ABPattern::ABPattern()
{
}

ABPattern::ABPattern(int spawners, bool spin, float delay, T2::Entity* givenOwner)
{
	objPool = ServiceLocator<T2::ObjectPool>::getService();
	owner = givenOwner;
	timer = new T2::Timer();
	if (delay > 0) { timer->setTimer(delay); }

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
		angle = i * (360.0 / numSpawners) + 90.0;
		float degree = (angle * (M_PI / 180));
		xPositions[i] = cos(degree);
		yPositions[i] = sin(degree);
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

void ABPattern::spawnBullets(float dTime, T2::Transform::Vector2D center)
{
	if (timer->timerFinished)
	{
		for (int i = 0; i < barrels.size(); i++)
		{
			if (spinning) { rotateGun(i, center); }
			dynamic_cast<Bullet*>(objPool->getObject(bulletTag))->ResetBullet({ owner->transform.Position.x + ((enemyWidth / 2) - (bulletWidth / 2)) , owner->transform.Position.y + ((enemyHeight / 2) - (bulletHeight / 2)) }, barrels[i], bulletTag);
		}
		timer->RestartTimer();
	}
	else
	{
		timer->Update(dTime);
	}
}

//TODO: FIX THIS SHIT.
void ABPattern::rotateGun(int barrel, T2::Transform::Vector2D center)
{
	double rad = 150;
	double angle = 0;

	angle = barrel * (360.0 / numSpawners) + (currentSpin += 10.0);
	float degree = (angle * (M_PI / 180));

	barrels[barrel].x = cos(degree);
	barrels[barrel].y = sin(degree);
}
