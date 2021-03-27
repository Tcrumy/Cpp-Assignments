// program6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "EquationFactory.h"
#include "EquationTest.h"
#include "json_3_7_2.hpp"

//******************************************************
// The run_unit_test() functions accepts no arguements *
// An EquationTest object will be created, and all     *
// test cases in the EquationTest class will be ran. if*
// any test case fails, the program will be exited. The*
// run_unit_test() function retruns nothing            *
//******************************************************
void run_unit_test();

//*******************************************************
// The print_equations() function will accept a list of *
// std::unique_ptr<IEquation> references. The list will *
// be ireteated through and each IEquation in the list  *
// will be displated to the console. Nothing is returned*
//*******************************************************
void print_equations(std::list<std::unique_ptr<IEquation>>& equations);

// This is a tag for data that will be looked for
// in the json file. It is a label for the author
// of the json file
const std::string AUTHOR_TAG = "author";

int main()
{
    // If the unit test fails, the program will be exited.
    run_unit_test();
    
    // simpleData.json contains a list of equations
    // and the authors name.
    std::string fileName = "simpleData.json";
    std::ifstream inputStream(fileName, std::ios::in);

    // Ensure that simpleData.json opened correctly 
    // Notify the user and terminate program if not
    if (inputStream.fail())
    {
        std::cout << "Error opening File \"" << fileName << "\" Exiting Program" << std::endl;
        exit(EXIT_FAILURE);
    }

    // The equation factory will parse the json
    // data and return a list of std::unique_ptr<IEquation>
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(inputStream);

    // The input stream needs to be reset so 
    // that the author of the json data can be
    // looked for
    inputStream.clear();
    inputStream.seekg(0, std::ios::beg);

    // This parser will be used to look for AUTHOR_TAG
    // which is "author"
    nlohmann::json parser;
    inputStream >> parser;

    // Store the authors name
    std::string author_name = parser[AUTHOR_TAG].get<std::string>();

    // Iterate through list of std::unique_ptr<IEquation> and call execute()
    // This will perform the equation operation that was pulled from simpleData.json.
    for (auto& eq : equations)
    {  
        eq->execute();
    }

    // Display equations to the console
    print_equations(equations);

    std::cout << "simpleData.json Authored by: " << author_name << std::endl;

    inputStream.close();
    
    return 0;
}


//**************************
// run_unit_test() function*
//**************************
void run_unit_test()
{
    std::cout << "Unit Test Starting........" << std::endl;

    // Create an instance of EquationTest and run all test cases.
    // If any fail, end program execution.
    EquationTest unit_tester;

    if (!unit_tester.requiredTest1())
    {
        std::cout << "Test Case 1 has failed: Exiting Program" << std::endl;
        exit(EXIT_FAILURE);
    }

    else if (!unit_tester.requiredTest2())
    {
        std::cout << "Test Case 2 has failed: Exiting Program" << std::endl;
        exit(EXIT_FAILURE);
    }

    unit_tester.addTest1();

    unit_tester.addTest2();
    
    unit_tester.subtractTest1();
    
    unit_tester.subtractTest2();
    
    unit_tester.subtractTest3();
    
    unit_tester.multiplyTest1();
    
    unit_tester.multiplyTest2();
    
    unit_tester.multiplyTest3();
    
    unit_tester.divideTest1();
    
    unit_tester.divideTest2();
    
    unit_tester.divideTest3();
    
    unit_tester.divideTest4();

    std::cout << "Unit Test Complete.........\n" << std::endl;

}

//****************************
// print_equation() function *
//****************************
void print_equations(std::list<std::unique_ptr<IEquation>>& equations)
{
    // Itereate throug list of std::unique_ptr<IEquation> 
    // and display to console
    for (auto &eq : equations)
    {   
        std::cout << eq;
    }
}

