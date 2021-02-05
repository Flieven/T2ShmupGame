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
	class CollisionManager;
	class Collision;

	class ObjectPool
	{
	private:

		std::map<int, std::vector<T2::Object*>> pool;

		FactoryManager* factoryManager;
		CollisionManager* colManager;

	public:
		ObjectPool();
		~ObjectPool();

		void addNewPool(const int& tag);
		void deletePool(const int& tag);
		void clearPools();

		T2::Object* getObject(const int& tag);
		T2::Object* getRandomObject(const int& tag);
		T2::Object* getSpecificObject(const int& tag, int index);
		void addObjectToPool(T2::Object* obj, const int& tag);

		void Update(float dTime);

		void checkCollisions();
		void checkCollisions(const int& tag, const int& othertag);
		void checkCollisions(T2::Object* col, const int& tag);

	};
}
