#include "UI_Button.h"
#include "ServiceLocator.h"

#include "DrawManager.h"
#include "InputManager.h"
#include "TextManager.h"

#include <iostream>

T2::UI_Button::UI_Button()
{
}

T2::UI_Button::UI_Button(SDL_Rect rect, std::string buttonTxT)
{
	Obj_rect = rect;
	buttonText = buttonTxT;
	drawManager = ServiceLocator<DrawManager>::getService();
	inputManager = ServiceLocator<T2::Input>::getService();
	textManager = ServiceLocator<T2::TextManager>::getService();
}

T2::UI_Button::~UI_Button()
{
}

void T2::UI_Button::Update(float dTime)
{
	if( (inputManager->getMousePosition().x >= Obj_rect.x &&
		inputManager->getMousePosition().x <= Obj_rect.x + Obj_rect.w &&
		inputManager->getMousePosition().y >= Obj_rect.y &&
		inputManager->getMousePosition().y <= Obj_rect.y + Obj_rect.h) && 
		inputManager->isMouseButtonPressed(SDL_BUTTON_LEFT -1))
	{
		onClick();
	}
	Draw();
	textManager->Update(dTime, buttonText, Obj_rect);
}

void T2::UI_Button::pairFunction(std::function<void()> func)
{
	this->onClick = func;
}

void T2::UI_Button::Draw()
{
	drawManager->DebugRender(Obj_rect);
}
