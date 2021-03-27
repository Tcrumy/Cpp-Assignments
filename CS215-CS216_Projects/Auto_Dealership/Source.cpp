#include <iostream>
#include <fstream>
#include <string>
#include "AutoDealer.h"
#include "Car.h"

using namespace std;

// Initialize all constants that represent menu choice items
const int INPUT_CAR = 1;
const int SEARCH_FOR_CAR = 2;
const int DISPLAY_CARS = 3;
const int QUIT = 4;

void get_user_choice(int&);


int main()
{
	// Variable to represent the users menu choice
	int user_choice{};

	// Instatiate an AutoDealer class named cars 
	AutoDealer cars;

	// Call the readCarFile member function
	cars.readCarFile();

	// Initalize a position variable that will hold the inventory
	// position of a vehicle if the searchCar member function
	// is called
	int position{};

	// Do while loop begins here
	do
	{
		// Call the get_user_choice function and assign value to user_choice
		get_user_choice(user_choice);

		// Use a switch statement to handle menu option selected by user
		switch (user_choice) {

			// If the user selected to enter a new vehicle,
			// call the inputCarInfo member function on the cars object
			case(INPUT_CAR):
				cars.inputCarInfo();
				break;
			
			// If the user selected to search for a vehicle, call 
			// the searchCar member function on the cars object
			case(SEARCH_FOR_CAR):

				// Assign vehicle inventory position to position
				position = cars.searchCar();

				// If a vehicle was found, display its location in inventory
				if (position != -1)
					cout << "\nVehicle is in bay " << position << endl << endl;

				// Otherwise, let user know the vehicle was not in inventory
				else
					cout << "Vehicle is not in inventory.\n\n";
				break;

			// If the user selects the display current inventory option, call
			// the displayCars member function on the cars object
			case(DISPLAY_CARS):
				cars.displayCars();
				break;
			
			// If the user selects the exit program option, 
			// call the writeCarsFile member function on the cars object
			case(QUIT):
				cars.writeCarsFile();
				break;
		}

	} while (user_choice != QUIT);
	// Do while loop ends here


	cout << "Thanks for using the program!\n";

	return 0;
}


//****************************************************************************
// This function accepts an integer reference parameter for users choice. The* 
// function Will prompt the user with a menu and ask them to select an option*
// , if the option is not on the menu, the user will be reprompted until a	 *
// valid selection is made. The validated value will be assigned to the		 *
// variable that was passed into the function                                *
//****************************************************************************
void get_user_choice(int& choice)
{
	// Display a menu to the user, and prompt them to make a selection
	cout << "Please select from the following menu\n";
	cout << "-------------------------------------\n";
	cout << "1. Enter a new vehicle\n";
	cout << "2. Search for a vehicle\n";
	cout << "3. Display current inventory\n";
	cout << "4. Exit Program\n";
	cout << "Your choice is: ";
	cin >> choice;

	// Use a while loop to validate the menu selection made by the user
	while (choice < 1 || choice > 4)
	{
		// Reprompt the user with a message letting them know that there 
		// menu selection was invalid, and they must enter a valid selection
		cout << "\nYour choice was invalid, try again\n\n";

		cout << "Please select from the following menu\n";
		cout << "-------------------------------------\n";
		cout << "1. Enter a new vehicle\n";
		cout << "2. Search for a vehicle\n";
		cout << "3. Display current inventory\n";
		cout << "4. Exit Program\n";
		cout << "Your choice is: ";
		cin >> choice;
	}

	cout << endl;
}