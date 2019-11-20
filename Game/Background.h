#pragma once

#include <Entity.h>

class Background : public T2::Entity
{
public:
	Background();
	~Background();

	

	void Update(float dTime);
	void Draw();
	void onCollision(Collision* other);
	SDL_FRect fRect2;
	


	// Inherited via Entity
	virtual void setupTextures(const char* texture) override;

	virtual void setupObject(SDL_Rect rect) override;

};

