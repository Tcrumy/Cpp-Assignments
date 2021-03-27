#include <iostream>
#include "Test4Observer.h"
#include "Counter.h"


int Test4Observer::counterCount = 0;

//****************************
// Test4Observer constructor *
//****************************
Test4Observer::Test4Observer(Counter* subject_counter)
{
	_counter = subject_counter;
	_counter->attach(this);
}

//*****************************
// Test4Observer() destructor *
//*****************************
Test4Observer::~Test4Observer()
{
	_counter->detach(this);
}

//******************
// update() method *
//******************
void Test4Observer::update(Subject* subject)
{
	Counter* subject_counter;

	subject_counter = dynamic_cast<Counter*>(subject);

	// Exit if subject_counter is a nullptr
	if (subject_counter == nullptr)
	{
		return;
	}
	
	counterCount = subject_counter->get();
}

//***************************
// getCounterCount() method *
//***************************
int Test4Observer::getCounterCount() const
{
	return counterCount;
}



