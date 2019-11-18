#pragma once

#include <Entity.h>

class Cloud : public T2::Entity
{
private:
	void setupCloud();
	void setupFarCloud();
	void updateObject();

public:
	Cloud();
	~Cloud();
	void Update(float dTime);
	void Draw();


	// Inherited via Entity
	virtual void onCollision(Collision* other) override;

};