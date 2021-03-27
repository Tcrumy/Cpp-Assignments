#pragma once
#include "Observer.h"
#include "Counter.h"

//****************************************************
// Test3Observer will be an observer for the Counter *
// class.                                            *
//****************************************************
class Test3Observer : public Observer
{
private:
	Counter* _counter;

	// wasCalled will be used in the update() 
	// method. It will be set to true if the
	// class notifing the observer calls the 
	// update method properly
	static bool wasCalled;

public:

	//*************************************************************
	// The Test3Observer() constructor will accept a Counter      *
	// pointer as an argument. Test3Observers _counter data       *
	// member will be set to the value passed into the constructor*
	//, then the _counter will attach Test3Observers to it's list *
	// of observers.                                              *
	//*************************************************************
	Test3Observer(Counter*);

	//*************************************************************
	// The Test3Observer() destructor will detach the previously  *
	// attached observer from the Subject being observed.         *
	//*************************************************************
	virtual ~Test3Observer();

	//********************************************************
	// The update() method will accept a pointer of type     *
	// Subject. If the method is called, wasCalled will     *
	// be set to ture. update() will return nothing          *
	//********************************************************
	virtual void update(Subject*) override;

	//*****************************************************
	// getWasCalled() accepts no argument. It returns the *
	// current value of wasCalled.                        *
	//*****************************************************
	virtual bool getWasCalled() const;
};

