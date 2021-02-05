#pragma once

/*
THIS IS AN ABSTRACT FACTORY CLASS!
*/

namespace T2
{
	class Object;

	class AFactory
	{
	public:
		AFactory();
		virtual ~AFactory();

		virtual T2::Object* createObject();

	};
}
