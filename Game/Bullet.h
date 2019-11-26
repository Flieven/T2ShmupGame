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
	// reset bullet, transform.position active = true;
	void ResetBullet(T2::Transform::Vector2D vector2d);


	virtual void setupTextures(const char* texture) override;

	virtual void setupObject(SDL_Rect rect) override;


};

