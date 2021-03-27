#include "EquationBase.h"
#include <iostream>

//********************************************************
// These tags are the names of the data being looked for *
// in the json file/string                               *
//********************************************************
const std::string EquationBase:: OP_TAG = "operand";
const std::string EquationBase::LEFT_NUMBER_TAG = "leftNumber";
const std::string EquationBase::RIGHT_NUMBER_TAG = "rightNumber";

const std::string EquationBase::ADDITION_TAG = "+";
const std::string EquationBase::SUBTRACTION_TAG = "-";
const std::string EquationBase::MULTIPLY_TAG = "*";
const std::string EquationBase::DIVIDE_TAG = "/";

//**********************
// getOperand() method *
//**********************
Operand EquationBase::getOperand() const
{
    return _op;
}

//*************************
// getLeftNumber() method *
//*************************
float EquationBase::getLeftNumber() const
{
    return _leftNum;
}

//*************************
// getRightNumber() method*
//*************************
float EquationBase::getRightNumber() const
{
    return _rightNum;
}

//*********************
// getAnswer() method *
//*********************
float EquationBase::getAnswer() const
{
    return _answer;
}

//**********************************
// getAnswerIfDivideByZero() method*
//**********************************
std::string EquationBase::getAnswerIfDivideByZero() const
{
    return _answerIfDivideByZero;
}

//*********************
// setAnswer() method *
//*********************
void EquationBase::setAnswer(float answer)
{
    _answer = answer;
}

//**********************************
// setAnswerIfDivideByZero() method*
//**********************************
void EquationBase::setAnswerIfDivideByZero()
{
    _answerIfDivideByZero = "Undefined";
}

//*****************
// setOp() method *
//*****************
void EquationBase::setOp(Operand op)
{
    _op = op;
}

//************************
// setLeftNumber() method*
//************************
void EquationBase::setLeftNumber(float leftNum)
{
    _leftNum = leftNum;
}

//**************************
// setRightNumber() method *
//**************************
void EquationBase::setRightNumber(float rightNum)
{
    _rightNum = rightNum;
}

