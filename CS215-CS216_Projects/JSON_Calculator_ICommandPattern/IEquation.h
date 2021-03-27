#pragma once
#include <string>
#include "ICommand.h"
#include <list>

enum class Operand
{
    Addition,
    Subtraction,
    Multiplication,
    Division
};

//*********************************************************
// IEquation is an abstract base class that all equation  *
// classes will be derived from Equation base wich derives*
// from IEquation                                         *
//*********************************************************
class IEquation:public ICommand
{
public:

    //************************************************************
    // These virtual methods will be implemented in EquationBase *
    //************************************************************
    virtual Operand getOperand() const = 0;
    virtual float getLeftNumber() const = 0;
    virtual float getRightNumber() const = 0;
    virtual float getAnswer() const = 0;

    //************************************************************************
    // This method needed to be added for my implemetation of DivideEquation *
    // due to the way that it handles a devide by zero error                 *
    //************************************************************************
    virtual std::string getAnswerIfDivideByZero() const = 0;
   
    // Method to allow dynamic overloading of this method which is used in operator overloading.
    virtual void output(std::ostream& os) = 0;

    // Note: IEquation.output is called to do the work, this method is just a wrapper.
    //       IEquation.output uses dynamic binding.
    friend std::ostream& operator<<(std::ostream& os, IEquation& eq)
    {
        eq.output(os);
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, IEquation* eq)
    {
        eq->output(os);
        return os;
    }


   //**********************************************
   // As a class that is meant to be derived from,*
   // the destructor should be virtual            *
   //**********************************************
    virtual ~IEquation() {};
};
