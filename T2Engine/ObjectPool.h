#pragma once
#include <vector>
#include <map>
#include <string>

/*
List A contains multiple instances of single object to use rather than creating/destroying at runtime.
List B contains a searchable term associated with list A to keep everything together.
Result: std::map< [SearchTerm] , std::list< [ObjectPointers] >> call it "pool" (Because it's the actual object Pool).

(*) Ability to create new unique list of objects. ( void AddNewPool(); ) <--- CHECK THAT NO DUPLICATE POOL IS CREATED.
(*) Ability to get object from pool ( Object* getObject(std::string type) ) <--- CHECK THAT POOL HAS OBJECT FREE ELSE CREATE NEW OBJECT AND ADD IT TO POOL. 
(*) Ability to clear pool if no longer in use ( void destroyPool(std::string type) ) <--- OVERLOAD WITH VERSION THAT KILLS ALL POOLS ON DECONSTRUCTION.

NOTES:
		This is essentially an Abstract Factory <--- GOOGLE IT, IT'S BEEN A WHILE SINCE WE USED IT!

		Idea 1:
		Best way to do this? Swtich that returns an Object* (each case being the constructor of specific object based on tag given?).
		Idea 2:
		Do proper Abstract Factory with Concrete Factories as well? Won't *really* need it though?
		Idea 456:
		Use GameConfig to access all available tags (they will be static) and then use that with a swtich and just pass the tag you need.
		Idea 666:
		Shoot yourself and don't have to worry about it anymore....
		Should the tags be unique strings for each object in GameConfig, or a global enum?
		Global enum seems best, let's do that...
		But then we can't use the GameConfig because it sits in the Game not the Engine... \o/

		NEW PROBABLY BETTER IDEA:
		Create FactoryManager and Abstract Factory.

		Game creates Unique Factories based on Abstract Factory and then pass that into the Factory Manager that has a list<std::string, AFactory*>.
		When Object pool needs to create new object for pool -> access FactoryManager, request unique Factory using same tag as object needed.
		Which should activate that unique factory, create the object, and return it to the pool list that needs it.
*/

namespace T2
{
	class Object;
	class FactoryManager;

	class ObjectPool
	{
	private:

		std::map<std::string, std::vector<Object*>> pool;

		FactoryManager* factoryManager;

	public:
		ObjectPool();
		~ObjectPool();

		void addNewPool(const std::string& tag);

		T2::Object* getObject(const std::string& tag);

	};
}