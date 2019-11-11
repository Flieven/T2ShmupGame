#include "TextManager.h"

T2::TextManager::TextManager(std::string message)
{
	text = message;
	//font = TTF_OpenFont( /*FontPath*/, 24);

	SDL_assert(font != nullptr);

	//surface = TTF_RenderText_Solid(font, text.c_str(), /*color*/);
	//texture = SDL_CreateTextureFromSurface( /*renderAccess*/ , surface);
}

T2::TextManager::~TextManager()
{
}

void T2::TextManager::setDisplay(int x, int y, int w, int h)
{
	display.x = x;
	display.y = y;
	display.w = w;
	display.h = h;
}

void T2::TextManager::Update(float dTime, std::string message)
{
	SDL_FreeSurface(surface);
	text = message;
	//surface = TTF_RenderText_Solid(font, text.c_str(), /*textColor*/);
	if (texture != nullptr) { SDL_DestroyTexture(texture); }
	//texture = SDL_CreateTextureFromSurface(/*drawManagerRef*/, surface);
}

void T2::TextManager::Draw()
{
	//SDL_RenderCopy(/*drawManagerREF*/, texture, nullptr, &display);
}
