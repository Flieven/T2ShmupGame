#include "FactoryManager.h"
#include "AFactory.h"
#include <iostream>

T2::FactoryManager::FactoryManager()
{
}

T2::FactoryManager::~FactoryManager()
{
	//std::map<std::string, AFactory*>::iterator it;
	//for (it = factoryList.begin(); it != factoryList.end(); it++)
	//{
	//	delete it->second;
	//	it->second = nullptr;
	//}

	factoryList.clear();
}

void T2::FactoryManager::addFactory(const int tag, AFactory* factory)
{
	auto it = factoryList.find(tag);
	if (it == factoryList.end()) { factoryList.insert(std::pair<int, AFactory*>(tag, factory)); }
	else { std::cout << "WARNING: There is already a factory that uses the tag: " << tag << std::endl; }
}

T2::Object* T2::FactoryManager::useFactory(const int tag)
{
	//std::cout << "creating new Object with tag: " << tag << std::endl;
	auto it = factoryList.find(tag);
	if (it == factoryList.end()) { std::cout << "WARNING: There is no factory that uses the tag: " << tag << std::endl; return nullptr; }
	else
	{
		AFactory* factory = it->second;
		Object* returnVal = factory->createObject();
		return returnVal;
	}
}

void T2::FactoryManager::removeFactory(const int tag)
{
	auto it = factoryList.find(tag);
	if (it == factoryList.end()) { std::cout << "WARNING: There is no factory to remove that uses the tag: " << tag << std::endl; }
	else 
	{
		delete it->second;
		it->second = nullptr;
		factoryList.erase(tag);
	}
}
