#include "AddEquation.h"

//*******************
// execute() method *
//*******************
void AddEquation::execute()
{
    float answer = getLeftNumber() + getRightNumber();
    setAnswer(answer);
}

//******************
// output() method *
//******************
void AddEquation::output(std::ostream& os)
{
   os << getLeftNumber() << " + "
      << getRightNumber() << " = " << getAnswer() << std::endl;
}
