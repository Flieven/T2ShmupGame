#include "AbstractState.h"

AbstractState::AbstractState()
{
}

AbstractState::~AbstractState()
{
}

void AbstractState::Enter()
{
}

void AbstractState::Run(float deltaTime)
{
	//Text Feedback
	std::cout << "Run.." << std::endl;
}

void AbstractState::Exit()
{
}
