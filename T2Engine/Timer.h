#pragma once

namespace T2
{
	class Timer
	{
	protected:
		float targetTime = 0.0f;
		float currentTime = 0.0f;

	public:

		Timer();
		~Timer();

		void setTimer(float target);
		void Update(float dTime);
		void RestartTimer();

		bool timerActive = true;
		bool timerFinished = false;
	};
}
