#include "InputManager.h"

#include "StaticIncluder.h"

#include "KeyboardManager.h"
#include "MouseManager.h"

T2::Input::Input()
{
	mouse = nullptr;
	keyboard = nullptr;
}

T2::Input::~Input()
{
}

void T2::Input::initialize()
{
	mouse = new Mouse();
	keyboard = new T2::Keyboard();
	std::cout << "Keyboard is: " << keyboard << std::endl;
	std::cout << "Mouse is: " << mouse << std::endl;
}

void T2::Input::shutdown()
{
	delete mouse;
	mouse = nullptr;
	delete keyboard;
	keyboard = nullptr;
}

SDL_Point T2::Input::getMousePosition()
{
	return mouse->getPosition();
}

SDL_Point T2::Input::getMouseMotion()
{
	return mouse->getMotion();
}

bool T2::Input::isMouseButtonDown(int button)
{
	return mouse->getButtonDown(button);
}

bool T2::Input::isMouseButtonPressed(int button)
{
	return mouse->getButtonPressed(button);
}

bool T2::Input::isMouseButtonReleased(int button)
{
	return mouse->getButtonReleased(button);
}

bool T2::Input::isKeyDown(SDL_Scancode key)
{
	return keyboard->getKeyDown(key);
}

bool T2::Input::isKeyDownOnce(SDL_Scancode key)
{
	return keyboard->getKeyDownOnce(key);
}

void T2::Input::handleEvent(SDL_Event& event)
{
	//std::cout << "Event handler in Input called" << std::endl;
	switch (event.type)
	{
	case SDL_KEYDOWN: keyboard->setKey(event.key.keysym.scancode, true); break;
	case SDL_KEYUP: keyboard->setKey(event.key.keysym.scancode, false); break;
	case SDL_MOUSEBUTTONDOWN: mouse->setButton(event.button.button, true); break;
	case SDL_MOUSEBUTTONUP: mouse->setButton(event.button.button, false); break;
	case SDL_MOUSEMOTION: mouse->setMoition(event.motion); break;
	}
}

void T2::Input::Update()
{
	//std::cout << "UPDATING: Input Manager" << std::endl;
	mouse->Update();
	keyboard->Update();
}
