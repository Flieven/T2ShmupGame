#pragma once

namespace T2
{
	class Sprite;
	class DrawManager;

	class IDrawable
	{
	protected:
		Sprite* sprite = nullptr;
		DrawManager* drawManager = nullptr;

	public:
		IDrawable();
		virtual ~IDrawable();
		virtual void Draw() = 0;
	};

}