#include "IncCounter.h"

//*******************
// execute() method *
//*******************
void IncCounter::execute(int increments)
{

	// Call the Counter classes incCount() method "increments"
	// number of times.
	for (int count = 0; count < increments; count++)
	{
		Counter::instance().incCount();
	}
}
