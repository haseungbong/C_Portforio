#include "Singleton.h"


template <class T>
T& Singleton<T>::instance()
{
	static T instance;
	return instance;
}
