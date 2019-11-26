#pragma once

#include <cmath>
#include <iostream>

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

	public:

		Vector2D Position;
		Vector2D Scale;

		//===== BASE SETS =====
		Vector2D zero = { 0.0f, 0.0f };
		Vector2D one = { 1.0f, 1.0f };

		Vector2D up = { 0.0f, 1.0f };
		Vector2D down = { 0.0f, -1.0f };
		Vector2D left = { -1.0f, 0.0f };
		Vector2D right = { 1.0f, 0.0f };
		//=====================

		float Distance(const Vector2D& other)
		{
			return std::sqrt(((Position.x - other.x) * (Position.x - other.x)) + ((Position.y - other.y) * (Position.y - other.y)));
		}

		void setPosition(const Vector2D& position)
		{
			this->Position.x = position.x;
			this->Position.y = position.y;
		}

		Vector2D lerp(const Vector2D& origin, const Vector2D& target, float time)
		{
			float X = (origin.x + time * (target.x - origin.x));
			float Y = (origin.y + time * (target.y - origin.y));

			Vector2D XY{ X, Y };

			return XY;
		}

	};
}
