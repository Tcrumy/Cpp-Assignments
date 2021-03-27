#include "CounterTest.h"

//*********************
// testCase1() method *
//*********************
bool CounterTest::testCase1()
{
	// Arrange
	Counter::instance().setCount(0);

	Counter& counter = Counter::instance();

	// Act
	counter.incCount();

	// Assert
	if (counter.get() == 1)
	{
		return true;
	}

	std::cout << "Test case 1 has failed: Exiting" << std::endl;
	return false;
}

//*********************
// testCase2() method *
//*********************
bool CounterTest::testCase2()
{
	// Arrange
	Counter &instance1 = Counter::instance();
	Counter &instance2 = Counter::instance();
	Counter &instance3 = Counter::instance();

	// Act
	instance1.incCount();
	instance2.incCount();

	// Assert
	if (instance3.get() == 3)
	{
		return true;
	}

	std::cout << "Test case 2 has failed: Exiting" << std::endl;
	return false;
}

//*********************
// testCase3() method *
//*********************
bool CounterTest::testCase3()
{
	// Arrange
	int current_count = Counter::instance().get();
	Counter& counter = Counter::instance();
	Test3Observer observer(&counter);

	// Act
	counter.incCount();

	//Assert
	if (observer.getWasCalled())
	{
		return true;
	}

	std::cout << "Test case 3 has failed: Exiting" << std::endl;
	return false;
}

//*********************
// testCase4() method *
//*********************
bool CounterTest::testCase4()
{
	// Arrange
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
	return false;

}
