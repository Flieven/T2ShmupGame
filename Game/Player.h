#pragma once

#include <Entity.h>

namespace T2
{
	class Input;
}

class Player : public T2::Entity
{
private:
	bool keyDown = false;

	void setupPlayer();
	void updateObject();

public:
	Player();
	~Player();

	T2::Input* inputManager;

	void Update(float dTime);
	bool checkInput();
	void Draw();
	void onCollision(int other);

	// Inherited via Entity
	virtual void setupTextures(const char* texture) override;
	virtual void setupObject(SDL_Rect rect) override;
};