#pragma once

#include "Transform.h"
#include "Collision.h"
#include "IDrawable.h"
#include "IObject.h"

namespace T2
{
	class Object : public IObject, public IDrawable, public Collision
	{
	public:
		bool active = false;
		Transform transform;
		SDL_Rect Obj_Rect = { 0,0,0,0 };
		SDL_FRect fRect;
		int tag = 0;

		Object();
		virtual ~Object();

		virtual void Reset();
		virtual void Update(float dTime);
		virtual void Draw();
		virtual void onCollision(int other);
		virtual void setupTextures(const char* texture) = 0;
		virtual void setupObject(SDL_Rect rect) = 0;
	};
}