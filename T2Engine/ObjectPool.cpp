#include "ObjectPool.h"
#include "Object.h"
#include "ServiceLocator.h"
#include "FactoryManager.h"

T2::ObjectPool::ObjectPool()
{
	factoryManager = ServiceLocator<FactoryManager>::getService();
}

T2::ObjectPool::~ObjectPool()
{
}

void T2::ObjectPool::addNewPool(const std::string& tag)
{
	auto it = pool.find(tag);
	if (it == pool.end())
	{
		pool.insert({ tag, std::vector<Object*>() });
	}
	else { std::cout << "WARNING: Pool already exists!" << std::endl; }
}

T2::Object* T2::ObjectPool::getObject(const std::string& tag)
{
	Object* returnVal = nullptr;
	auto it = pool.find(tag);
	if (it == pool.end())
	{
		addNewPool(tag);
		it = pool.find(tag);
	}

	if (it->second.empty())
	{
		it->second.push_back(factoryManager->useFactory(tag));
	}

	for (size_t i = 0; i < it->second.size(); i++)
	{
		if (!it->second[i]->active)
		{
			returnVal = it->second[i];
			returnVal->active = true;
			break;
		}
		else if (i == it->second.size())
		{
			it->second.push_back(factoryManager->useFactory(tag));
		}
	}

	return returnVal;
}
