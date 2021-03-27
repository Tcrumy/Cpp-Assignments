#include "MultiplyEquation.h"

//********************
// execute() methood *
//********************
void MultiplyEquation::execute()
{
    float answer = getLeftNumber() * getRightNumber();
    setAnswer(answer);
}

//******************
// output() method *
//******************
void MultiplyEquation::output(std::ostream& os)
{
    os << getLeftNumber() << " * "
        << getRightNumber() << " = " << getAnswer() << std::endl;
}

