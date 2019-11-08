#include "MouseManager.h"

#include "StaticIncluder.h"

T2::Mouse::Mouse() : buttons{}, buttonsPrevious{}, motion{}, position{}
{
	std::cout << "Mouse created!" << std::endl;
}

T2::Mouse::~Mouse()
{
}

bool T2::Mouse::getButtonDown(Uint8 index)
{
	if (index > 4) { return false; }
	else { return buttons[index]; }
}

bool T2::Mouse::getButtonPressed(Uint8 index)
{
	if (index > 4) { return false; }
	else { return (buttonsPrevious[index] == false && buttons[index] == true); }
}

bool T2::Mouse::getButtonReleased(Uint8 index)
{
	if (index > 4) { return false; }
	else { return (buttonsPrevious[index] == true && buttons[index] == false); }
}

void T2::Mouse::setButton(Uint8 button, bool value)
{
	buttons[button - 1] = value;
}

SDL_Point T2::Mouse::getPosition()
{
	return position;
}

SDL_Point T2::Mouse::getMotion()
{
	return motion;
}

void T2::Mouse::setMoition(SDL_MouseMotionEvent event)
{
	position.x = event.x;
	position.y = event.y;
	motion.x = event.xrel;
	motion.y = event.y;
}

void T2::Mouse::Update()
{
	for (int i = 0; i < 5; i++)
	{
		buttonsPrevious[i] = buttons[i];
	}
	motion.x = 0;
	motion.y = 0;
}
