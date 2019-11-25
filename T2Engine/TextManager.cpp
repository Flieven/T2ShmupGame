#include "TextManager.h"
#include "ServiceLocator.h"
#include "DrawManager.h"

T2::TextManager::TextManager()
{
	drawManager = ServiceLocator<DrawManager>::getService();
}

T2::TextManager::~TextManager()
{
}

void T2::TextManager::Update(float dTime, std::string message, SDL_Rect rect, SDL_Color textColor)
{
	SDL_FreeSurface(surface);
	text = message;
	surface = TTF_RenderText_Solid(font, text.c_str(), textColor);
	if (texture != nullptr) { SDL_DestroyTexture(texture); }
	texture = SDL_CreateTextureFromSurface(drawManager->getRenderer(), surface);
	Draw(rect);
}

void T2::TextManager::Draw(SDL_Rect rect)
{
	SDL_RenderCopy(drawManager->getRenderer(), texture, nullptr, &rect);
}

void T2::TextManager::configText(int fSize, SDL_Color fColor, const char* fFile)
{
	font = TTF_OpenFont(fFile, fSize);
	SDL_assert(font != nullptr);
	surface = TTF_RenderText_Solid(font, text.c_str(),fColor);
	texture = SDL_CreateTextureFromSurface(drawManager->getRenderer(), surface);
}
