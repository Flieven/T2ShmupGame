#pragma once

#include <cassert>

template <typename T>
class ServiceLocator
{
public:
	static void setService(T* service) { myService = service; }
	static T* getService()
	{
		assert(myService != nullptr);
		return myService;
	}
private:
	static T* myService;
};

template <typename T>
T* ServiceLocator<T>::myService = nullptr;
