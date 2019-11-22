#pragma once
#include <string>

namespace T2
{
	class IObject
	{
	protected:
		std::string type;

	public:
		IObject();
		virtual ~IObject();
		virtual void Update(float dTime) = 0;
		const std::string getType();
	};
}