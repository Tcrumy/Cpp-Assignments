#pragma once

//***********************************************************************
// ICommand will serve as an interface that will use the command pattern*
// to give all derived classes access to the execute method. It is an   *
// abstract base class.                                                 *
//***********************************************************************
class ICommand
{
public:

    //*****************************************************************
    // The execute() method will be implemented in the AddEquation,   *
    // SubtractEquation, MultiplyEquation, and DivideEquation classes *
    //*****************************************************************
    virtual void execute() = 0;

    //**********************************************
    // As a class that is meant to be derived from,*
    // the destructor should be virtual            *
    //**********************************************
    virtual ~ICommand() {}
};

