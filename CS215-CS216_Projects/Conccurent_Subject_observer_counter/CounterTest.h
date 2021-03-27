#pragma once
#include "Counter.h"
#include <iostream>
#include "Test3Observer.h"
#include "Test4Observer.h"

//***********************************************************
// The CounterTest class is a class for testing the Counter *
// class. It will have three test cases that will serve as  *
// the unit test. Each test method will set _count to 0     *
// before starting the test so the state of the class is    *
// known. Test will be done in Arrange/Act/Assert pattern   *
//***********************************************************
class CounterTest
{
public:

	//*****************************************************
	// The testCase1() method will accept no arguments. A *
	// Counter instance will be created, incremented once *
	// and the counter.get() method will be checked to    *
	// ensure that Counter _count is currently 1. If this *
	// is the case, true will be returned, otherwise a    *
	// message will be displayed stating test case 1      *
	// failed, and then false will be returned.           *
	//*****************************************************
	bool testCase1();

	//*****************************************************
	// The testCase2() method will accept no arguments.   *
	// Three Counter instances will be created, the first *
	// two will be incremented and the last one will call *
	// its .get() method and checked that it is 3. If this*
	// is the case, true will be returned, otherwise a    *
	// message will be displayed stating test case 2      *
	// failed, and then false will be returned.           *
	//*****************************************************
	bool testCase2();

	
	//*********************************************************
	// the testCase3() method will accept no arguments. The   *
	// counter class' .get() method will be called. A counter *
	// reference object will be created, and a Test3Observer  *
	// object will be created and attached to Subjects list   *
	// of observers. Counter will be incremented and the      *
	// observers update() method should be called. If it was  *
	// called, return true, otherwise return false            *
	//*********************************************************
	bool testCase3();

	/*// Arrange
	int current_count = Counter::instance().get();
	Counter& counter = Counter::instance();
	Test4Observer observer(&counter);

	// Act
	counter.incCount();
	counter.incCount();

	// Assert
	if (observer.getCounterCount() == current_count + 2)
	{
		return true;
	}

	std::cout << "Test Case 4 has failed: Exiting" << std::endl;
	return false;*/

	//**********************************************************
	// The testCase4() method accepts no arguments. The current*
	// value of the counter class' _count data member will be  *
	// given to a holding variable. A Counter reference object *
	// will be created and a Test4Observer will be created and *
	// added to Subjects list of observers. The Counter object *
	// will be incremented twice. The observers counterCount   *
	// data member will be checked to see that it is equal to  *
	// current_count + 2. current_count is the value of        *
	// Counter's _count data member before counter's incCount  *
	// method was called twice. If observers counterCount data *
	// member is (current_count + 2) return true, otherwise    *
	// return false.                                           *
 	//**********************************************************
	bool testCase4();
};

