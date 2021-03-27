#include <iostream>
#include "CounterObserver.h"
#include "Counter.h"

//**************
// Constructor *
//**************
CounterObserver::CounterObserver(Counter* subject_counter)
{
	// Attach the (this) pointer to the 
	// subjects list of observers
	_counter = subject_counter;
	_counter->attach(this);
}

//************
// Destructor*
//************
CounterObserver::~CounterObserver()
{
	// Detach the (this) pointer from
	// subjects list of observers
	_counter->detach(this);
}

//*****************
// update() method*
//*****************
void CounterObserver::update(Subject* subject)
{
	Counter* subject_counter;

	// If the Counter* is a null pointer, there is no subject
	// to update and method should be returned from
	if ((subject_counter = dynamic_cast<Counter*>(subject)) == nullptr)
	{
		return;
	}

	// Display that the observer has been updated
	std::cout << "Observer Updated. _count is now:" << subject_counter->get() << std::endl;
}


