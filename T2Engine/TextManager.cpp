#include "TextManager.h"
#include "ServiceLocator.h"
#include "DrawManager.h"
T2::TextManager::TextManager()
{
	font = TTF_OpenFont( "../Assets/Font/zerovelo.ttf", 24);

	drawManager = ServiceLocator<DrawManager>::getService();

	SDL_assert(font != nullptr);

	surface = TTF_RenderText_Solid(font, text.c_str(), {255, 255, 255, 255 } );
	texture = SDL_CreateTextureFromSurface(drawManager->getRenderer(), surface);
}

T2::TextManager::~TextManager()
{
}

void T2::TextManager::Update(float dTime, std::string message, SDL_Rect rect)
{
	SDL_FreeSurface(surface);
	text = message;
	surface = TTF_RenderText_Solid(font, text.c_str(), { 255, 255, 255, 255 });
	if (texture != nullptr) { SDL_DestroyTexture(texture); }
	texture = SDL_CreateTextureFromSurface(drawManager->getRenderer(), surface);
	Draw(rect);
}

void T2::TextManager::Draw(SDL_Rect rect)
{
	SDL_RenderCopy(drawManager->getRenderer(), texture, nullptr, &rect);
}
