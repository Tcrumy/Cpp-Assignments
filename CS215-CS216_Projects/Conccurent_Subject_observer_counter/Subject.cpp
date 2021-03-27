#include "Subject.h"
#include <iostream>

Subject::Subject() {};
Subject::~Subject() {};

//******************
// attach() method *
//******************
void Subject::attach(Observer* new_observer)
{
	// Add observer to the list of observers
	_observers.push_front(new_observer);
}

//******************
// detach() method *
//******************
void Subject::detach(Observer* observer_to_remove)
{
	// Check to see if the observer to be removed is
	// currently in the list of observers
	for (auto* observer : _observers)
	{
		if (observer == observer_to_remove)
		{
			// Remover observer if present
			_observers.remove(observer);
			return;
		}
	}
}

//******************
// notify() method *
//******************
void Subject::notify()
{
	// Itereate through the list of observers
	// and call their update method
	for (auto observer : _observers)
	{
		observer->update(this);
	}

}