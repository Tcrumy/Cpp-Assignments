#pragma once
#include <iostream>
#include "EquationBase.h"
#include "ICommand.h"

class DivideEquation final: public EquationBase
{
public:

    #pragma region ICommand interface
    // <summary> Execute the equation this object represents and store the answer.</summary>
    //*********************************************************
    // ICommand's execute() method is implemented here.       * 
    // It will accept no arguments. The left number will be   *
    // divided by the right number if the right number is not *
    // zero. If the right number is not zero, the float answer*
    // of the division will be stored, otherwise a string will*
    // be asigned to undefined to handle the division by zero *
    // case.
    //*********************************************************
    void execute() override;
    #pragma endregion

    #pragma region IEquation interface
    // <summary> Format and output Execute the equation this object represents and store the answer.</summary>
    //*****************************************************
    // The output() method accepts an ostream reference   *
    // argument. A formatted output will be inserted into *
    // the ostream. Nothing is returned from this method  *
    // There are two possible formats for this output, one*
    // is a case where the answer is a float, the other is*
    // a divide by zero case in which the answer will be a*
    // string "Undefined"                                 *
    //*****************************************************
    void output(std::ostream& outStream) override;
    #pragma endregion

    DivideEquation() = default;
    ~DivideEquation() = default;
};

