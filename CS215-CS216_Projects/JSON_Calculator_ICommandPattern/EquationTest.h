#pragma once
#include "EquationFactory.h"
#include "AddEquation.h"
#include "SubtractEquation.h"
#include "MultiplyEquation.h"
#include "DivideEquation.h"
#include <iostream>
#include <fstream>
#include <sstream>


class EquationTest
{
public:

	//***************************************************************
	// The requiredTest1() method accepts no arguments. The method  *
	// will open a json file, ensure that it opened correctly, pass *
	// the istream to the EquationFactory instance which will create*
	// a std::list of std::unique_ptr<IEquation>. The execute method*
	// will be called on each IEquation in the list, and the results*
	// will be output to the console. If the scope in which the     *
	// output is done is completed, test_result will be set to true *
	// otherwise, test_result is false. test_result will be returned*
	//***************************************************************
	bool requiredTest1();

	//***************************************************************
	// The requiredTest2() method accepts no arguments. A string of *
	// JSON data will be created and converted to an istringstream, *
	// the istringtream  will be passed to the EquationFactory      *
	// instance which will create a std::list of                    *
	// std::unique_ptr<IEquation>. The execute method will be called*
	// on each IEquation in the list, and the results will be output*
	// to the console. If the scope in which the output is done is  *
	// completed, test_result will be set to true otherwise,        *
	// test_result is false. test_result will be returned           *
	//***************************************************************
	bool requiredTest2();

	//******************************************************************
	// The addTest2() method accepts no arguments. A string of         *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to 25. If the answer is     *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool addTest1();

	//******************************************************************
	// The addTest2() method accepts no arguments. A string of         *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to -5.3. If the answer is   *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool addTest2();

	//******************************************************************
	// The subtractTest1() method accepts no arguments. A string of    *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to 20.5. If the answer is   *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool subtractTest1();

	//******************************************************************
	// The subtractTest2() method accepts no arguments. A string of    *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to 25. If the answer is     *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool subtractTest2();

	//******************************************************************
	// The subtractTest3() method accepts no arguments. A string of    *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to -5.0. If the answer is   *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool subtractTest3();

	//******************************************************************
	// The multiplyTest1() method accepts no arguments. A string of    *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to 107.0. If the answer is  *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool multiplyTest1();

	//******************************************************************
	// The multiplyTest2() method accepts no arguments. A string of    *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to -10.0. If the answer is  *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool multiplyTest2();
	//******************************************************************
	// The multiplyTest3() method accepts no arguments. A string of    *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to 10.0. If the answer is   *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool multiplyTest3();

	//******************************************************************
	// The divideTest1() method accepts no arguments. A string of      *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to 0.5. If the answer is    *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool divideTest1();

	//******************************************************************
	// The divideTest2() method accepts no arguments. A string of      *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to -0.5. If the answer is   *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool divideTest2();

	//******************************************************************
	// The divideTest3() method accepts no arguments. A string of      *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. The answer that is retruned     *
	// from eq->getAnswer will be compared to 4. If the answer is      *
	// correct, true will be returned, otherwise a message will display*
	// stating that the test failed, and the program will be exited    *
	//******************************************************************
	bool divideTest3();

	//******************************************************************
	// The divideTest4() method accepts no arguments. A string of      *
	// JSON data will be created and converted to an istringstream,    *
	// the istringtream  will be passed to the EquationFactory         *
	// instance which will create a std::list of                       *
	// std::unique_ptr<IEquation>. The execute method will be called   *
	// the only IEquation in the list. This test will create divide by *
	// zero case. Fist eq->getRightNumber() will be checked for 0 to   *
	// ensure that this is a divide by zerp case, then                 *
	// eq->getAnswerIfDivideByZero() will be compared to "Undefined"   *
	// If both of these are true, true will be returned, otherwise a   *
	// message will display stating that the test failed, and the      *
	// program will be exited                                          *
	//******************************************************************
	bool divideTest4();

	//*********************************************************************
	// The EqualTo2DecimalPlaces() method will accept two float arguments *
	// Two integer variables will be given the rounded float arguments    *
	// after they are multiplied by 100. The two integers will be compared*
	// and true will be returned if they are equal, otherwise false will  *
	// be returned                                                        *
	//*********************************************************************
	bool EqualTo2DecimalPlaces(float , float);
	
	EquationTest() = default;
	~EquationTest() = default;

};

