#pragma once
#include <list>
#include <memory>
#include <istream>

#include "IEquation.h"

class EquationFactory
{

public:
    #pragma region Json strings
    //**************************************************
    // The EQUATIONS_TAG data member is the name of the*
    // array of json objects being looked for          *
    //**************************************************
    static const std::string EQUATIONS_TAG;
    #pragma endregion

    //****************************************************************************************
    // The make() method accepts an istream reference, given the data                        *
    // in the istream, a collection of IEquation unique pointers will be returned.           *
    // <parm input>An istream point to the json data to be converted into IEquations </parm> *
    //****************************************************************************************
    std::list<std::unique_ptr<IEquation>> make(std::istream& inputStream);

    EquationFactory() = default;
};

