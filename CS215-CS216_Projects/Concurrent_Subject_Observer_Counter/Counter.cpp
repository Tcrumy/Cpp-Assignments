#include "Counter.h"
#include <thread>
#include <chrono>

//**********************
// Counter Constructor *
//**********************
Counter::Counter()
{
	_count = 0;
}

//********************
// instance() method *
//********************
Counter& Counter::instance()
{
	//****************************************
	// instance is a static counter to ensure*
	// that Counter remains a singleton      *
	//****************************************
	static Counter instance;

	return instance;
}

//********************
// incCount() method *
//********************
void Counter::incCount()
{
	std::lock_guard<std::mutex> scope_lock(_lock);
	_count ++;
	notify();
}

//********************
// setCount() method *
//********************
void Counter::setCount(int number)
{
	_count = number;
}

//***************
// get() method *
//***************
int Counter::get() const
{
	return _count;
}
