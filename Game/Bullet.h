#pragma once

#include <Entity.h>

class Bullet : public T2::Entity
{
public:
	Bullet();
	~Bullet();
		
	void Update(float dTime);
	void Draw();
	void Fire();
	void onCollision(Collision* other);

	virtual void setupTextures(const char* texture) override;

	virtual void setupObject(SDL_Rect rect) override;


};

