#pragma once
#include "Observer.h"
#include "Counter.h"

//****************************************************************
// The CounterObserver class will serve as an observer to counter*
// and will recieve and update every time Counters' _count data  *
// member is incremented.                                        *
//****************************************************************
class CounterObserver : public Observer
{
private:
	// This will be the counter pointer that the observer 
	// attaches itself to in the it's constructor
	Counter* _counter;

public:

	// (*this) will attach to the Counter* in the constructor
	CounterObserver(Counter*);
	virtual ~CounterObserver() override;

	//************************************************************
	// The update method will accept a pointer to a Subject      *
	// The subject will be dynamically cast to a Counter* and    *
	// checked for nullptr. If the counter* is a nullptr, update *
	// will return to the calling function, otherwise, update    *
	// will display a message stating that it has been updated   *
	// and the Counter* _count data member will be displayed.    *
	//************************************************************
	virtual void update(Subject*) override;

};

