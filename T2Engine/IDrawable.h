#pragma once
#include <vector>

namespace T2
{
	class Sprite;
	class DrawManager;

	class IDrawable
	{
	protected:
		Sprite* sprite = nullptr;
		Sprite* hpbarSprite = nullptr;
		DrawManager* drawManager = nullptr;

		std::vector<const char*> textureList;

	public:
		IDrawable();
		virtual ~IDrawable();
		virtual void Draw() = 0;
	};

}