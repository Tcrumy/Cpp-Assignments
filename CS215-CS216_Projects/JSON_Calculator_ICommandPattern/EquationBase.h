#pragma once
#include "IEquation.h"
#include <string>
#include <cmath>


// Implement the ABC IEquation but not ICommand. 
// ICommands execute() method will be implemented in
// classes that are dirived from EquationBase

// Fowart Declaration
class EquationFactory;

// Equation base serves as a parent class to all
// four equation classes in this program.
class EquationBase: public IEquation
{
private:
    Operand     _op;
    float       _leftNum = 0.0;
    float       _rightNum = 0.0;
    float       _answer = 0.0;

    // This data member is what will be returned in a divide by
    // zero case. It will be set to "Undefined" in such a case
    std::string _answerIfDivideByZero = "";

public:

    // These strings will be used to hold the tags being looked
    // for in the json files
    #pragma region Json strings
    static const std::string OP_TAG;
    static const std::string LEFT_NUMBER_TAG;
    static const std::string RIGHT_NUMBER_TAG;

    static const std::string ADDITION_TAG;
    static const std::string SUBTRACTION_TAG;
    static const std::string MULTIPLY_TAG;
    static const std::string DIVIDE_TAG;
    #pragma endregion


    #pragma region IEquation interface
    
    //***********************************************
    // The getOperand() method accepts no arguments *
    // It will return an Operand from the enum class*
    // Operand                                      *
    //***********************************************
    Operand getOperand() const override;

    //**************************************************
    // The getLeftNumber() method accepts no arguments *
    // It will return the float _leftNumber data member*
    //**************************************************
    float getLeftNumber() const override;

    //***************************************************
    // The getRightNumber() method accepts no arguments *
    // It will return the float _rightNumber data member*
    //***************************************************
    float getRightNumber() const override;

    //****************************************************
    // The getAnswer() method accepts no arguments. It   *
    // calculates the result of the _operand data member *
    // performed on the _rightNumber from the _leftNumber*
    // data member                                       *
    //****************************************************
    float getAnswer() const override;

    //***********************************************************
    // The getAnswerIfDivideByZero() method accepts no arguments*
    // It will return "Undefined" in a divide by zero case      *
    //***********************************************************
    std::string getAnswerIfDivideByZero() const override;
    #pragma endregion

    //***********************************************************
    // Making equation factory a frind makes it easier to create*
    // the list of unique_pointers to IEquations that the the   *
    // EquationFactory class creates                            *
    //***********************************************************
    friend EquationFactory;

    //**********************************************************
    // Since EquationBase is meant to be a parent class to the *
    // individual equation classes, ensure that the destructor *
    // is virtual so that it is called after the destructor of *
    // the derived classes                                     *
    //**********************************************************
    virtual ~EquationBase() {}

protected:
    //******************************************************
    // The setAnswer() method will accept a float argument *
    // The _answer data member will be set to the float    *
    // that is passed to the method                        *
    //******************************************************
    void setAnswer(float answer);

    //***********************************************************
    // The setAnswerIfDivideByZero() method accepts no arguments*
    // The _answerIfDivideByZero data member will be set to     *
    // "Undefined" in a divide by zero case                     *
    //***********************************************************
    void setAnswerIfDivideByZero();
 

private:

    //*************************************************************
    // The setOp() method will accept an Operand argument from the*
    // enum class Operand. The _op data member will be set to the *
    // operand that is passed to the method                       *
    //*************************************************************
    void setOp(Operand op);

    //**********************************************************
    // The setLeftNumber() method will accept a float argument *
    // The _leftNumber data member will be set the to argument *
    // passed into the method                                  *
    //**********************************************************
    void setLeftNumber(float lnum);

    //***********************************************************
    // The setRightOperand() method will accept a float argument*
    // The _rightNumber will be set to the argument passed into *
    // the method                                               *
    //***********************************************************
    void setRightNumber(float rnum);

};
