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

void T2::ObjectPool::addNewPool(const int& tag)
{
	auto it = pool.find(tag);
	if (it == pool.end())
	{
		pool.insert({ tag, std::vector<Object*>() });
	}
	else { std::cout << "WARNING: Pool already exists!" << std::endl; }
}

void T2::ObjectPool::deletePool(const int& tag)
{
	auto it = pool.find(tag);
	if (it == pool.end()) { std::cout << "No Pool to delete." << std::endl; }
	else
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			delete it->second[i];
		}
		it->second.clear();
		pool.erase(tag);
	}
}

void T2::ObjectPool::clearPools()
{
	for (auto& it : pool)
	{
		for (int i = 0; i < it.second.size(); i++)
		{
			delete it.second[i];
		}
		it.second.clear();
		pool.erase(it.first);
	}
}

T2::Object* T2::ObjectPool::getObject(const int& tag)
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
			break;
		}
	}

	if (returnVal == nullptr)
	{
		it->second.push_back(factoryManager->useFactory(tag));
		//std::cout << "Pool size: " << it->second.size() << std::endl;
		returnVal = it->second[it->second.size()-1];
	}

	return returnVal;
}

T2::Object* T2::ObjectPool::getRandomObject(const int& tag)
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
				break;
			}
		}
	}

	if (returnVal == nullptr)
	{
		it->second.push_back(factoryManager->useFactory(tag));
		returnVal = it->second[it->second.size() - 1];
		returnVal->active = true;
	}

	return returnVal;
}

T2::Object* T2::ObjectPool::getSpecificObject(const int& tag, int index)
{
	auto it = pool.find(tag);
	if (it == pool.end()) { std::cout << "No pool for the tag: " << tag << " found!" << std::endl; }
	else
	{
		if(it->second[index])
		{
			return it->second[index];
		}
		else { std::cout << "No index: " << index << " found in pool " << tag << std::endl; }
	}
}

void T2::ObjectPool::addObjectToPool(T2::Object* obj, const int& tag)
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

//IT LOOKS WEIRD BUT IT WORKS AND I KNOW HOW OK!?
void T2::ObjectPool::checkCollisions()
{
	for (auto& firstList : pool)
	{
		for (auto& firstIt : firstList.second)
		{
			if (firstIt->active)
			{
				for (auto& secondList : pool)
				{
					for (auto& secondIt : secondList.second)
					{
						if (firstIt != secondIt && secondIt->active)
						{
							colManager->checkCollision(firstIt, secondIt);
						}
					}
				}
			}
		}
	}
}

void T2::ObjectPool::checkCollisions(const int& tag, const int& othertag)
{
	auto firstList = pool.find(tag);
	if (firstList == pool.end()) { std::cout << "No list of tag: " << tag << std::endl; }
	else
	{
		auto secondList = pool.find(othertag);
		if(secondList == pool.end()) { std::cout << "No list of tag: " << othertag << std::endl; }
		else
		{
			for (auto& it : firstList->second)
			{
				if (it->active)
				{
					for (auto& otherit : secondList->second)
					{
						colManager->checkCollision(it, otherit);
					}
				}
			}
		}
	}
}

void T2::ObjectPool::checkCollisions(T2::Object* col, const int& tag)
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
