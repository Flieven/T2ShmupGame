#include "AbstractState.h"

T2::AbstractState::AbstractState()
{
}

T2::AbstractState::~AbstractState()
{
}

void T2::AbstractState::Enter()
{
}

void T2::AbstractState::Run(float deltaTime)
{
	//Text Feedback
	std::cout << "Run.." << std::endl;
}

void T2::AbstractState::Exit()
{
}
