#include "ObjectPool.h"
#include "Object.h"
#include "ServiceLocator.h"
#include "FactoryManager.h"
#include "CollisionManager.h"

T2::ObjectPool::ObjectPool()
{
	factoryManager = ServiceLocator<FactoryManager>::getService();
	colManager = ServiceLocator<CollisionManager>::getService();
}

T2::ObjectPool::~ObjectPool()
{
}

void T2::ObjectPool::addNewPool(const std::string& tag)
{
	auto it = pool.find(tag);
	if (it == pool.end())
	{
		pool.insert({ tag, std::vector<Object*>() }); //THIS IS BAD DOING COPIES LIKE THIS AND SHOULD BE FIXED. IF ONLY I KNEW HOW...
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

T2::Object* T2::ObjectPool::getRandomObject(const std::string& tag)
{
	Object* returnVal = nullptr;
	auto it = pool.find(tag);
	if (it == pool.end()) { std::cout << "No pool for the tag: " << tag << " found!" << std::endl; }
	else
	{
		if(it->second.empty()) { it->second.push_back(factoryManager->useFactory(tag)); }
	}

	for (size_t i = 0; i < it->second.size(); i++)
	{
		if (!it->second[i]->active)
		{
			returnVal = it->second[i];
			int randomNum = rand() % 4;
			if (randomNum % 2 == 0)
			{
				returnVal->active = true;
				break;
			}
			else if (i == it->second.size())
			{
				returnVal->active = true;
				break;
			}
		}
		else if (i == it->second.size())
		{
			it->second.push_back(factoryManager->useFactory(tag));
		}
	}

	return returnVal;
}

void T2::ObjectPool::addObjectToPool(T2::Object* obj, const std::string& tag)
{
	auto it = pool.find(tag);
	if (it == pool.end()) { std::cout << "No pool for the tag: " << tag << " found!" << std::endl; }
	else
	{
		it->second.push_back(obj);
	}
}

void T2::ObjectPool::Update(float dTime)
{
	for (auto const& it : pool)
	{
		for (auto const& ent : it.second)
		{
			if(ent->active)
			{
				ent->Update(dTime);
			}
		}
	}
}

void T2::ObjectPool::checkCollisions(T2::Collision* col, const std::string& tag)
{
	auto it = pool.find(tag);
	if (it == pool.end()) { std::cout << "Tag: " << tag << " No such pool found!" << std::endl; }
	else
	{
		for (size_t i = 0; i < it->second.size(); i++)
		{
			if(it->second[i]->active)
			{
				colManager->checkCollision(col, it->second[i]);
			}
		}
	}

}
