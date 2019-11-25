#pragma once

#include "AbstractState.h"

namespace T2
{
	class AbstractState;
	class UI_ButtonManager;
	class FSM;
}

class MainMenuState : public T2::AbstractState
{
private:
	T2::UI_ButtonManager* buttonManager = nullptr;

public:

	T2::FSM* stateMachine = nullptr;

	MainMenuState();
	MainMenuState(std::string stateID);
	~MainMenuState();

	virtual void Enter() override;
	virtual void Run(float deltaTime) override;
	virtual void Exit() override;

	void btnPlay();
	void btnOptions();
	void btnQuit();
};