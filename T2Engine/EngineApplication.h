#pragma once

namespace T2
{
	class Engine
	{
	public:
		virtual ~Engine() {};
		virtual bool Initialize() = 0;
		virtual void Run() = 0;
		virtual void Shutdown() = 0;
	};

	Engine* createEngine();
}