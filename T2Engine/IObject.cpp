#include "IObject.h"

T2::IObject::IObject() : type("")
{
}

T2::IObject::~IObject()
{
}

const std::string T2::IObject::getType()
{
	return type;
}
