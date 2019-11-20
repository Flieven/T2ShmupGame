#include "gameObject.h"
//#include "TextureManager.h" // where dis? drawmanager har ju den.
#include "DrawManager.h"


T2::GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren)
{
	renderer = ren;
	objectTexture = DrawManager::LoadTexture(texturesheet, ren); // create an object
}

T2::GameObject::~GameObject()
{
}

void T2::GameObject::Update()
{
	xPos = 0;
	yPos = 0;

	sourceRect.h = 23;
	sourceRect.w = 87;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destinationRect.x = xPos;
	destinationRect.y = yPos;
	destinationRect.w = sourceRect.w * 3;
	destinationRect.h = sourceRect.h * 3;

}

void T2::GameObject::Render()
{
	SDL_RenderCopy(renderer, objectTexture, &sourceRect, &destinationRect); // draw texture
}
