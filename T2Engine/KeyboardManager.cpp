#include "KeyboardManager.h"

#include "StaticIncluder.h"

T2::Keyboard::Keyboard() : keys{}, keysPrevious{}
{
	std::cout << "Keyboard created!" << std::endl;
}

T2::Keyboard::~Keyboard()
{
}

void T2::Keyboard::setKey(SDL_Scancode key, bool value)
{
	keys[key] = value;
}

bool T2::Keyboard::getKeyDown(SDL_Scancode key)
{
	return keys[key];
}

bool T2::Keyboard::getKeyDownOnce(SDL_Scancode key)
{
	return (keysPrevious[key] == false && keys[key] == true);
}

void T2::Keyboard::Update()
{
	//std::cout << "UPDATING: Keyboard" << std::endl;
	for (int i = 0; i < SDL_NUM_SCANCODES; i++)
	{
		keysPrevious[i] = keys[i];
	}
}
