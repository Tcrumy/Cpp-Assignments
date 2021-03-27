#pragma once
#include "Counter.h"

//*****************************************************
// The IncCounter class will be used as an incrementer*
// for the counter class.                             *
//*****************************************************
class IncCounter
{

public:

	//*******************************************************
	// The execute() method will accept an integer argument *
	// This argument will be the number of times the Counter*
	// class incCounter() method will be ran. The execute() *
	// method will return nothing.                          *
	//*******************************************************
	static void execute(int);
};

