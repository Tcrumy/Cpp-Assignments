#pragma once

// Foward declaration of Subject class
class Subject;

//***********************************************
// The Observer class is an abstract base class *
// whose methods will be implemented in the     *
// classes derived from it.                     *
//***********************************************
class Observer
{
protected:
	Observer();

public:
	virtual ~Observer();
	virtual void update(Subject* changed_subject) = 0;


};

