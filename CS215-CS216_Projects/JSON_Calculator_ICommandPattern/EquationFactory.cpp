
#include <fstream>
#include <iostream>

#include "json_3_7_2.hpp" 

#include "EquationFactory.h"
#include "AddEquation.h"
#include "SubtractEquation.h"
#include "MultiplyEquation.h"
#include "DivideEquation.h"

//*********************************************
// This using statement is so we don't need   *
// to type nlohmann::json everytime we need it*
//*********************************************
using json = nlohmann::json;

//***************************************
// The json object array we are looking *
// for will be labled with "equations"  *
//***************************************
const std::string EquationFactory::EQUATIONS_TAG = "equations";


std::list<std::unique_ptr<IEquation>> EquationFactory::make(std::istream& inputStream)
{
 
    json parser;


    std::list<std::unique_ptr<IEquation>> equations;

    
    // set up the json parser w/ an input stream.
    inputStream >> parser;


    // 0) pull the array of json object from the parser
    auto jsonEquations = parser[EQUATIONS_TAG];

    // 1) go throught the array of json objects
    // 2) find out the type of the current oject
    // 3) make the object of that type and set it to the values in the current jason object
    // 4) put the object into the list
    for (auto eq : jsonEquations)
    {
        auto eqOp = eq[EquationBase::OP_TAG].get<std::string>();

        // 2)
        if (eqOp == EquationBase::ADDITION_TAG)
        {
            // 3)
            auto tmp = std::make_unique<AddEquation>();
            tmp->setOp(Operand::Addition);
            tmp->setLeftNumber(eq[EquationBase::LEFT_NUMBER_TAG].get<float>());
            tmp->setRightNumber(eq[EquationBase::RIGHT_NUMBER_TAG].get<float>());

            // 4)
            equations.push_back(std::move(tmp));
        }

        else if (eqOp == EquationBase::SUBTRACTION_TAG)
        {
            // 3)
            auto tmp = std::make_unique<SubtractEquation>();
            tmp->setOp(Operand::Subtraction);
            tmp->setLeftNumber(eq[EquationBase::LEFT_NUMBER_TAG].get<float>());
            tmp->setRightNumber(eq[EquationBase::RIGHT_NUMBER_TAG].get<float>());

            // 4)
            equations.push_back(std::move(tmp));
        }

        else if (eqOp == EquationBase::MULTIPLY_TAG)
        {
            // 3)
            auto tmp = std::make_unique<MultiplyEquation>();
            tmp->setOp(Operand::Multiplication);
            tmp->setLeftNumber(eq[EquationBase::LEFT_NUMBER_TAG].get<float>());
            tmp->setRightNumber(eq[EquationBase::RIGHT_NUMBER_TAG].get<float>());

            // 4)
            equations.push_back(std::move(tmp));
        }

        else if (eqOp == EquationBase::DIVIDE_TAG)
        {
            // 3)
            auto tmp = std::make_unique<DivideEquation>();
            tmp->setOp(Operand::Division);
            tmp->setLeftNumber(eq[EquationBase::LEFT_NUMBER_TAG].get<float>());
            tmp->setRightNumber(eq[EquationBase::RIGHT_NUMBER_TAG].get<float>());

            // 4)
            equations.push_back(std::move(tmp));        
        }
    }

    //***************************************
    // recall that equations is an stl list *
    // of std::unique_ptr<IEquation>        *
    //***************************************
    return equations;
}
