#pragma once
#include "Observer.h"
#include "Counter.h"

//****************************************************
// Test3Observer will be an observer for the Counter *
// class.                                            *
//****************************************************
class Test4Observer : public Observer
{
private:
	Counter* _counter;
	static int counterCount;

public:
	//*************************************************************
	// The Test4Observer() constructor will accept a Counter      *
	// pointer as an argument. Test4Observers _counter data       *
	// member will be set to the value passed into the constructor*
	//, then the _counter will attach Test3Observers to it's list *
	// of observers.                                              *
	//*************************************************************
	Test4Observer(Counter*);

	//*************************************************************
	// The Test4Observer() destructor will detach the previously  *
	// attached observer from the Subject being observed.         *
	//*************************************************************
	virtual ~Test4Observer();

	//*********************************************************
	// The update() method will accept a pointer of type      *
	// Subject. A counter pointer will be created and cast    *
	// from Subject. Test4Observer's counterCount will be set *
	// to the counters current value. Nothing will be returned*
	//*********************************************************
	virtual void update(Subject*) override;

	//**********************************************************
	// The getCounterCount method will accept no arguments. It *
	// will return the value of the counterCount data member.  *
	//**********************************************************
	virtual int getCounterCount() const;
};

