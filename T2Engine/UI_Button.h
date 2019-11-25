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
		int fontSize = 12;
		SDL_Color fontColor = { 255,255,255,255 };
		const char* fontFile = "";

		Input* inputManager = nullptr;
		TextManager* textManager = nullptr;

		UI_Button();
		UI_Button(SDL_Rect rect, std::string buttonTxT, int size);
		UI_Button(SDL_Rect rect, std::string buttonTxT, const char* graphic, int size);
		~UI_Button();

		void Update(float dTime);

		void pairFunction(std::function<void()> func);
		void config(int fSize, SDL_Color fColor, const char* fFile);

		std::function<void()> onClick;
		virtual void Draw() override;
	};
}