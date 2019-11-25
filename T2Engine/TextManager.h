#pragma once

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>

namespace T2
{

	class DrawManager;

	class TextManager
	{
	private:

	public:
		SDL_Texture* texture = nullptr;
		SDL_Surface* surface = nullptr;

		TextManager();
		~TextManager();

		void Update(float dTime, std::string message, SDL_Rect rect, SDL_Color textColor);
		void Draw(SDL_Rect rect);
		void configText(int fSize, SDL_Color fColor, const char* fFile);

	protected:

		DrawManager* drawManager = nullptr;

		std::string text;

		TTF_Font* font = nullptr;

	};
}