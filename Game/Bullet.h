#pragma once
#include <Entity.h>


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
	void onCollision(Collision* other);
	void OutsideWindow();


	virtual void setupTextures(const char* texture) override;

	virtual void setupObject(SDL_Rect rect) override;


};

