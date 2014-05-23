#pragma once

#include <vector>
using std::vector;

template<typename T>
class Event
{
protected:
	typedef void (*fptr)(T);
	typename vector<fptr> listeners;

public:
	Event& add(fptr _func)
	{
		for(typename vector<fptr>::iterator it = listeners.begin(); it != listeners.end(); ++it)
		{
			if(*it == _func)
			{
				return *this;
			}
		}

		listeners.push_back(_func);
		return *this;
	}
};