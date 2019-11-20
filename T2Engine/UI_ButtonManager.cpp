#include "UI_ButtonManager.h"

#include "ServiceLocator.h"
#include "UI_Button.h"

#include <iostream>

T2::UI_ButtonManager::UI_ButtonManager()
{
}

T2::UI_ButtonManager::~UI_ButtonManager()
{
}

void T2::UI_ButtonManager::addButton(SDL_Rect buttonRect, const std::string& buttonTxt)
{
	auto it = buttons.find(buttonTxt);
	if (it == buttons.end()) { buttons.insert({ buttonTxt, new UI_Button(buttonRect, buttonTxt) }); }
	else { std::cout << "Button already exists with text: " << buttonTxt << std::endl; }
}

T2::UI_Button* T2::UI_ButtonManager::getButton(const std::string& buttonTxt)
{
	auto it = buttons.find(buttonTxt);
	if (it == buttons.end()) { std::cout << "NO button with text: " << buttonTxt << std::endl; return nullptr; }
	else { return it->second; }
}

void T2::UI_ButtonManager::Update(float dTime)
{
	for (auto const& it : buttons)
	{
		it.second->Update(dTime);
	}
}

void T2::UI_ButtonManager::removeButton(const std::string& buttonTxt)
{
	auto it = buttons.find(buttonTxt);
	if (it == buttons.end()) { std::cout << "No button found to delete!" << std::endl; }
	else
	{
	}
}

void T2::UI_ButtonManager::clearButtons()
{
	buttons.clear();
}
