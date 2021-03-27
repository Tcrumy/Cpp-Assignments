#include "SubtractEquation.h"

//*******************
// execute() method *
//*******************
void SubtractEquation::execute()
{
    float answer = getLeftNumber() - getRightNumber();
    setAnswer(answer);
}

//******************
// output() method *
//******************
void SubtractEquation::output(std::ostream& os)
{
    os << getLeftNumber() << " - "
        << getRightNumber() << " = " << getAnswer() << std::endl;
}
