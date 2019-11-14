#pragma once

#include <map>
#include <list>
#include <string>

/*
List of Unique Factories (Based on Abstract Factories) with a string search term that is the tag uset to create them.
Result: std::list<std::string, AFactory*>> Factories;

(*) A Way to add new factories to list ( addFactory(std::string, AFactory* factory) ) <--- CHECK NO DUPLICATE FACTORIES.
(*) Make factories accessable and return the Object* they create ( createObject(std::string tag) ) <--- ALL FACTORIES WORK WITH SOME CHILD OF OBJECT.h!
(*) Remove factories from list? ( removeFactory(std::string tag) ) <--- OVERLOAD FOR DECONSTRUCTION OF MANAGER TOO!

NOTES:
		What the actual fuck am I doing with my life?
*/

namespace T2
{
	class AFactory;
	class Object;

	class FactoryManager
	{
	private:

		std::map <std::string, AFactory*> factoryList;

	public:
		FactoryManager();
		~FactoryManager();

		void addFactory(const std::string& tag, AFactory* factory);
		
		T2::Object* useFactory(const std::string& tag);

		void removeFactory(const std::string& tag);

	};
}