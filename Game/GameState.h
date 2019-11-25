#pragma once
#include "AbstractState.h"

namespace T2
{
	class AbstractState;
	class ObjectPool;
}

class GameState : public T2::AbstractState
{
private:
	T2::ObjectPool* objPool = nullptr;

public:

	GameState();
	GameState(std::string stateID);
	~GameState();

	virtual void Enter() override;
	virtual void Run(float deltaTime) override;
	virtual void Exit() override;
};
