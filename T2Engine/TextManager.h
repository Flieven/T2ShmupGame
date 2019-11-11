#pragma once

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>

namespace T2
{

	class TextManager
	{
	private:

	public:

		SDL_Texture* texture = nullptr;
		SDL_Surface* surface = nullptr;
		SDL_Rect display;

		TextManager(std::string message);
		~TextManager();

		void setDisplay(int x, int y, int w, int h);
		void Update(float dTime, std::string message);
		void Draw();

	protected:

		/*Needed: DrawManagerRef*/

		std::string text;

		TTF_Font* font = nullptr;

	};
}