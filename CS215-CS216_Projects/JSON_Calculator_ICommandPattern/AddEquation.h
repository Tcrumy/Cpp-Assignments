#pragma once
#include <iostream>
#include "EquationBase.h"
#include "ICommand.h"

// This class implements addition
class AddEquation final: public EquationBase
{
public:
    #pragma region ICommand interface
    // <summary> Execute the equation this object represents and store the answer.</summary>
    //**************************************************
    // ICommand's execute() method is implemented here.* 
    // It will accept no arguments. The left and right *
    // numbers will be added together and the answer   *
    // will be stored                                  *       
    //**************************************************
    void execute() override;
    #pragma endregion

    #pragma region IEquation interface
    // <summary> Format and output Execute the equation this object represents and store the answer.</summary>
    //*****************************************************
    // The output() method accepts an ostream reference   *
    // argument. A formatted output will be inserted into *
    // the ostream. Nothing is returned from this method  *
    //*****************************************************
    void output(std::ostream& outStream) override;
    #pragma endregion

    AddEquation() = default;
    ~AddEquation() = default;
};

