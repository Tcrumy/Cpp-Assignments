#include "DivideEquation.h"

//******************
// execute() method*
//******************
void DivideEquation::execute()
{
    // If the right number is 0, this will 
    // create a divide by zero error. This
    // if statement will handle such a case
    if (getRightNumber() == 0)
    {
        // This method sets the _answerIfDivideByZero
        // data member to "Undefined".
        setAnswerIfDivideByZero();

        // This setAnswer() call is just to
        // ensure that we will know what will be
        // returned if  the _getAnswer() method is 
        // called on this equation. The actual answer
        // is undefined.
        setAnswer(-1);

        return;
    }

    float answer = getLeftNumber() / getRightNumber();
    setAnswer(answer);
}

//******************
// output() method *
//******************
void DivideEquation::output(std::ostream& os)
{
    // This will be the formatted output in a divide by zero case
    if (getRightNumber() == 0)
    {
        os << getLeftNumber() << " / "
            << getRightNumber() << " = " << getAnswerIfDivideByZero() << std::endl;
    }

    // This will be the formatted output in any other case
    else
    {
        os << getLeftNumber() << " / "
            << getRightNumber() << " = " << getAnswer() << std::endl;
    }
}


