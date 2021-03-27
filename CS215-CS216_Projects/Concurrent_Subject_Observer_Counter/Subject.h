#pragma once
#include<list>
#include "Observer.h"


//*****************************************************
// Subject is to be used as a base class. It will have*
// a list of observers, which will be notified when   *
// Subject being observed is changed                  *
//*****************************************************
class Subject
{
private:

	//*****************************************
	// This is the list of observers that will*
	// be notified when the Subject being     *
	// observed is changed                    *
	//*****************************************
	std::list<Observer*> _observers;

protected:
	Subject();

public:
	virtual ~Subject();

	//********************************************************
	// The attach method will accept a pointer to an observer*
	// to be attatched to subjects list of observers. It will*
	// return nothing.                                       *
	//********************************************************
	virtual void attach(Observer*);

	//********************************************************
	// The detach method will accept  a pointer to an oberver*
	// to be removed from subjects list of observers. It will*
	// return nothing                                        *
	//********************************************************
	virtual void detach(Observer*);

	//********************************************************
	// The notify method will iterate through the list of    *
	// observers, calling each of their update methods,      *
	// passing the (this) pointer. The notify method accepts *
	// no arguments and returns nothing.                     *
	//********************************************************
	virtual void notify();

};

