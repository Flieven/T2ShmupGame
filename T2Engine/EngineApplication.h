#pragma once
/*
T2Engine produced by:
(*) Ebba Taberman	  (*)
(*) Richard Nordström (*)
(*) Leon Andersson	  (*)

Supervisor: 
(*) Krister Cederlund (*)

@ FutureGames - ChangeMaker Educations (2019)
*/


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