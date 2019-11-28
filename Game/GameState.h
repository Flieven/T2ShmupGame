#pragma once
#include "AbstractState.h"
#include "GameConfig.h"

#include <Transform.h>

#include <array>

namespace T2
{
	class AbstractState;
	class ObjectPool;
	class Entity;
	class Timer;
	class Transform;
}

class GameState : public T2::AbstractState
{
private:
	T2::ObjectPool* objPool = nullptr;
	T2::Timer* spawnTimer = nullptr;

	T2::Transform::Vector2D spawnPos = { (float)(windowWidth / 2), -10.0f };

	std::array<T2::Entity*,8> enemies = {};

	void addEnemy();

public:

	GameState();
	GameState(std::string stateID);
	~GameState();

	virtual void Enter() override;
	virtual void Run(float deltaTime) override;
	virtual void Exit() override;
};
