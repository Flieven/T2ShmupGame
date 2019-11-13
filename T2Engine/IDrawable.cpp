#include "IDrawable.h"

#include "ServiceLocator.h"

T2::IDrawable::IDrawable()
{
	drawManager = ServiceLocator<DrawManager>::getService();
}

T2::IDrawable::~IDrawable()
{
	sprite = nullptr;
	drawManager = nullptr;
}
