#include "Timer.h"

T2::Timer::Timer()
{
}

T2::Timer::~Timer()
{
}

void T2::Timer::setTimer(float target)
{
	targetTime = target;
	currentTime = 0.0f;
	timerActive = true;
	timerFinished = false;
}

void T2::Timer::Update(float dTime)
{
	currentTime = dTime;

	if (timerActive && currentTime >= targetTime)
	{
		timerFinished = true;
		timerActive = false;
	}

}

void T2::Timer::RestartTimer()
{
	currentTime = 0.0f;
	timerActive = true;
	timerFinished = false;
}
