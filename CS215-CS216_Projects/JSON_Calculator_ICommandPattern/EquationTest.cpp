#include "EquationTest.h"

//*************************
// requiredTest1() method *
//*************************
bool EquationTest::requiredTest1()
{
    //Arrange
	std::string fileName = "simpleData.json";
	std::ifstream inputStream(fileName, std::ios::in);
    bool test_result = "false";

    // Exit program if the file did not open
	if (!inputStream.is_open())
	{
		std::cout << "Error opening File: Exiting Program" << std::endl;
		exit(EXIT_FAILURE);
	}

    EquationFactory   eqFactory;
    auto equations = eqFactory.make(inputStream);
    
    
    {
        // test_result can only be set to true if this scope executes properly
        for (auto& eq : equations)
        {
            // Act
            eq->execute();
           
            // Assert
            std::cout << eq;
        }

        test_result = true;
    }

    inputStream.close();

    return test_result;
}

//*************************
// requiredTest2() method *
//*************************
bool EquationTest::requiredTest2()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 10.0,
                    "rightNumber" : 2.2,
                    "operand" : "+"
                },
                {
                    "leftNumber": 3.0,
                    "rightNumber" : 2,
                    "operand" : "+"
                },
                {
                    "leftNumber": 3.0,
                    "rightNumber" : 2,
                    "operand" : "-"
                },
                {
                    "leftNumber": 3.3,
                    "rightNumber" : 10,
                    "operand" : "*"
                },
                {
                    "leftNumber": 3.0,
                    "rightNumber" : 0,
                    "operand" : "/"
                },
                {
                    "leftNumber": 5,
                    "rightNumber" : 2,
                    "operand" : "/"
                    }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    bool test_result = "false";



    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);

    {
        // test_result can only be set to true if this scope executes properly
        for (auto& eq : equations)
        {
            // Act
            eq->execute();
           
            // Assert
            std::cout << eq;
        }

        test_result = true;
    }
    
    return test_result;
}

//********************
// addTest1() method *
//********************
bool EquationTest::addTest1()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 10.0,
                    "rightNumber" : 15,
                    "operand" : "+"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    double answer = 25;
    auto& eq = equations.front();
   
    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Add Test 1 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

//********************
// addTest2() method *
//********************
bool EquationTest::addTest2()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 15,
                    "rightNumber" : -20.3,
                    "operand" : "+"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    
    double answer = -5.3;
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Add Test 2 has failed: Exiting Program " << std::endl;
    exit(EXIT_FAILURE);
}


//*************************
// subtractTest1() method *
//*************************
bool EquationTest::subtractTest1()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 25.5,
                    "rightNumber" : 5,
                    "operand" : "-"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    double answer = 20.5;
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Subtract Test 1 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

//*************************
// subtractTest2() method *
//*************************
bool EquationTest::subtractTest2()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 20.0,
                    "rightNumber" : -5,
                    "operand" : "-"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    double answer = 25;
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Subtract Test 2 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

//*************************
// subtractTest3() method *
//*************************
bool EquationTest::subtractTest3()
{// Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 10.2,
                    "rightNumber" : 15.2,
                    "operand" : "-"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    double answer = -5.0;
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Subtract Test 3 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

//*************************
// multiplyTest1() method *
//*************************
bool EquationTest::multiplyTest1()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 10.7,
                    "rightNumber" : 10,
                    "operand" : "*"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    double answer = 107.0;
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Multiply Test 1 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

//*************************
// multiplyTest2() method *
//*************************
bool EquationTest::multiplyTest2()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 5,
                    "rightNumber" : -2,
                    "operand" : "*"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    double answer = -10.0;
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Multiply Test 2 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

//*************************
// multiplyTest3() method *
//*************************
bool EquationTest::multiplyTest3()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": -5,
                    "rightNumber" : -2,
                    "operand" : "*"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    double answer = 10;
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Multiply Test 3 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

//***********************
// divideTest1() method *
//***********************
bool EquationTest::divideTest1()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 2,
                    "rightNumber" : 4,
                    "operand" : "/"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    double answer = 0.5;
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Divide Test 1 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

//***********************
// divideTest2() method *
//***********************
bool EquationTest::divideTest2()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 2,
                    "rightNumber" : -4,
                    "operand" : "/"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    double answer = -0.5;
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Divide Test 2 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

//***********************
// divideTest3() method *
//***********************
bool EquationTest::divideTest3()
{
    // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": -20,
                    "rightNumber" : -5,
                    "operand" : "/"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    double answer = 4;
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    if (EqualTo2DecimalPlaces(eq->getAnswer(), answer))
    {
        return true;
    }

    std::cout << "Divide Test 3 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

//***********************
// divideTest4() method *
//***********************
bool EquationTest::divideTest4()
{
   // Arrange
    std::string testData(R"({
                "equations": [
                {
                    "leftNumber": 3,
                    "rightNumber" : 0,
                    "operand" : "/"
                }
                ]})");

    std::istringstream JSONData;
    JSONData.str(testData);
    EquationFactory   eqFactory;
    auto equations = eqFactory.make(JSONData);
    std::string answer = "Undefined";
    auto& eq = equations.front();

    // Act
    eq->execute();

    // Assert
    // We should check that getRightNumber() 
    // is actually 0 before continuing otherwise
    // this is not a divide by zero case
    if (eq->getRightNumber() == 0)
    {   
        if (eq->getAnswerIfDivideByZero() == answer)
        {
            return true;
        }
    }
    

    std::cout << "Divide Test 4 has failed: Exiting Program" << std::endl;
    exit(EXIT_FAILURE);
}

bool EquationTest::EqualTo2DecimalPlaces(float aNum, float bNum)

{

    int tmpA = static_cast<int>(round(aNum * 100));

    int tmpB = static_cast<int>(round(bNum * 100));

    if (tmpA == tmpB)

        return true;

    return false;
}
