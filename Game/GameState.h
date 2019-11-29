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
	class AudioManager;

	class Music;
	class Sound;
}

class GameState : public T2::AbstractState
{
private:
	T2::ObjectPool* objPool = nullptr;
	T2::Timer* spawnTimer = nullptr;
	T2::AudioManager* audioManager = nullptr;

	T2::Transform::Vector2D spawnPos = { (float)(windowWidth / 2), -10.0f };

	std::array<T2::Entity*,8> enemies = {};

	T2::Music* bgMusic = nullptr;
	T2::Sound* shootSound = nullptr;

	void addEnemy();

public:

	GameState();
	GameState(std::string stateID);
	~GameState();

	virtual void Enter() override;
	virtual void Run(float deltaTime) override;
	virtual void Exit() override;
};
