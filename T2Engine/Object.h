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
		SDL_Rect Obj_Rect;

		Object();
		virtual ~Object();

		virtual void Reset();
		virtual void Update(float dTime);
		virtual void Draw();
		virtual void onCOllision(Collision* other);
	};
}