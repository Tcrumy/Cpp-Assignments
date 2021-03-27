#include <iostream>
#include <thread>
#include "Counter.h"
#include "IncCounter.h"
#include "CounterTest.h"
#include "CounterObserver.h"



//*********************************************************
// The inc_counter function will accept no arguments. It  *
// will call the Counter classes .incCount() method 50    *
// times. The function will return nothing.               *
//*********************************************************
void inc_counter();

//*********************************************************
// The run_unit_test function will create a CounterTest   *
// object, and call its four testCase methods. If any test*
// fails during the unit test, the program will be exited.*
// This function accepts no arguments and returns nothing *
//*********************************************************
void run_unit_test();

int main()
{
	
	// Perform unit test
	run_unit_test();

	// Create a counter reference and reset count 
	// to zero after the unit tests
	Counter &counter = Counter::instance();
	counter.setCount(0);

	// Create and observer for counter
	// and attach it to counter list of observers
	CounterObserver countObserver(&counter);

	// The goal of each thread is to call increment on the
	// the Counter class' _count data member 50 times
	std::thread thread1(inc_counter);
	std::thread thread2(&IncCounter::execute, 50);

	thread1.join();
	thread2.join();

	std::cout << "Count is now: " << Counter::instance().get() << std::endl;

	return 0;
}

//*************************
// inc_counter() function *
//*************************
void inc_counter()
{
	// Call the Counter class incCount() method 50 times
	for (int count = 0; count < 50; count++)
	{
		Counter::instance().incCount();
	}
}

//**************************
// run_unit_test function  *
//**************************
void run_unit_test()
{
	CounterTest tester;

	if (!tester.testCase1())
		exit(EXIT_FAILURE);
	if (!tester.testCase2())
		exit(EXIT_FAILURE);
	if (!tester.testCase3())
		exit(EXIT_FAILURE);
	if (!tester.testCase4())
		exit(EXIT_FAILURE);
}