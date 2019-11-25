#pragma once
#include "Object.h"

namespace T2
{
	class FSM;

	class Entity : public Object
	{
	public:

		float health = 0.0f;
		float movementSpeed = 0.0f;

		FSM* stateMachine = nullptr;

		Entity();
		virtual ~Entity();
		void UpdateColliders();

		// Inherited via Object
		virtual void setupTextures(const char* texture) = 0;
		virtual void setupObject(SDL_Rect rect) = 0;
	};
}