#pragma once

#include <cmath>

namespace T2
{
	class Transform
	{
	protected:

		struct Vector2D
		{
			float x = 0.0f;
			float y = 0.0f;
		};

		Vector2D zero = { 0.0f, 0.0f };
		Vector2D one = { 1.0f, 1.0f };

		Vector2D up = { 0.0f, 1.0f };
		Vector2D down = { 0.0f, -1.0f };
		Vector2D left = { -1.0f, 0.0f };
		Vector2D right = { 1.0f, 0.0f };

	public:

		Vector2D Position;
		Vector2D Scale;

		float Distance(Vector2D other)
		{
			float Pow1 = std::pow(Position.x, other.x);
			float Pow2 = std::pow(Position.y, other.y);
			float res = std::sqrt(Pow1 + Pow2);
			return res;
		}
	};
}
