#pragma once
#include <Entity.h>

namespace T2
{
	class Transform;
};

class Bullet : public T2::Entity
{
private:
	float xScale = 1;
	float yScale = 1;

public:
	Bullet();
	~Bullet();
		
	void Update(float dTime);
	void Draw();
	void onCollision(int other);
	void OutsideWindow();
	void ResetBullet(T2::Transform::Vector2D vector2d, T2::Transform::Vector2D movDir, int givenTag);


	virtual void setupTextures(const char* texture) override;

	virtual void setupObject(SDL_Rect rect) override;


};

