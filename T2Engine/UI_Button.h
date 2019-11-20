#pragma once

#include "IDrawable.h"

#include <functional>
#include <string>
#include <SDL.h>

namespace T2
{
	class Input;
	class TextManager;

	class UI_Button : public IDrawable
	{
	public:
		std::string buttonText = "";
		SDL_Rect Obj_rect = { 0,0,0,0 };

		Input* inputManager = nullptr;
		TextManager* textManager = nullptr;

		UI_Button();
		UI_Button(SDL_Rect rect, std::string buttonTxT);
		UI_Button(SDL_Rect rect, std::string buttonTxT, const char* graphic);
		~UI_Button();

		void Update(float dTime);
		void pairFunction(std::function<void()> func);

		std::function<void()> onClick;
		virtual void Draw() override;
	};
}