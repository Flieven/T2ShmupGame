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
};

