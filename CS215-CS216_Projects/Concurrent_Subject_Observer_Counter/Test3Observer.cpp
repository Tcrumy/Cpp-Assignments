#include <iostream>
#include "Test3Observer.h"
#include "Counter.h"

// was called will be used as a flag in the update
// method to ensure it was called properly by subjects
// notify() method
bool Test3Observer::wasCalled = false;

//******************************
// Test3Observer() constructor *
//******************************
Test3Observer::Test3Observer(Counter* subject_counter)
{
	_counter = subject_counter;
	_counter->attach(this);
}

//******************************
// Test3Observer() destructor  *
//******************************
Test3Observer::~Test3Observer()
{
	_counter->detach(this);
}

//******************
// update() method *
//******************
void Test3Observer::update(Subject* subject)
{
	// Set flag to true
	wasCalled = true;
}

//***************************
// getCounterCount() method *
//***************************
bool Test3Observer::getWasCalled() const
{
	return wasCalled;
}


