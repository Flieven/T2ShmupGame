#pragma once

#include <vector>
#include <map>
#include <string>
#include <SDL.h>

namespace T2
{
	class UI_Button;

	class UI_ButtonManager
	{
	private:
		std::map<std::string, UI_Button*> buttons;

	public:
		UI_ButtonManager();
		~UI_ButtonManager();


		void addButton(SDL_Rect buttonRect, const std::string& buttonTxt);
		T2::UI_Button* getButton(const std::string& buttonTxt);
		void Update(float dTime);
		void removeButton(const std::string& buttonTxt);
		void clearButtons();
	};
}