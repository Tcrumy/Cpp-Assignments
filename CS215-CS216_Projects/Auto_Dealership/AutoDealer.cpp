#include "AutoDealer.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Car.h"
using namespace std;

//**********************************************************************
// This function will accept zero arguments. The readCarFile functions *
// purpose is to open a .txt finle containing vehicle data, and assign *
// that data to each element of the carStock array until the array is  *
// full, or the end of the file has been reached, whichever comes first*
// Nothing will be returned from this function						   *
//**********************************************************************
void AutoDealer::readCarFile()
{
	// Open in input file object containing vehicle data
	ifstream carFile{ "cars.txt" };
	
	// Initialize count to 0, this will be the index of carStock
	// that is being assigned vehicle data
	int count{0};

	// Use a while loop to assign data to the elements of the carStock array
	// until the array is full, or the end of the file is reached. Whichever
	// comes first
	while (carCount < 20 && !carFile.eof())
	{
		// Use getline to assign the make and model as this data will have 
		// spaces that won't be assigned if the insertion operatoe is used
		getline(carFile, carStock[count].makeAndModel);

		// Use the insertion operator to assign the rest of the data
		carFile >> carStock[count].year;
		carFile >> carStock[count].color;
		carFile >> carStock[count].Class;
		carFile >> carStock[count].fuelType;
		carFile >> carStock[count].price;

		// Ignore any control characters
		carFile.ignore();

		count++;

		// Add one to the car inventory
		carCount++;
	}

	// Decrement carCount by one. If this is not done, a empty trailing car 
	// structure will be assigned to the carStock array, and subsequently 
	// written to the file in the writeCarsFile member function when the 
	// program is exited
	carCount--;

	// Close the file object
	carFile.close();
}

//***********************************************************************
// This function will accept zero arguments. The inputCarInfo functions *
// purpose is to prompt the user for information on a new vehicle to be	*
// added to the inventory. The user will be asked how many vehicles they*
// want to enter, they will be reprompted if the is no space in the     *
// inventory. If there is space, the used will be prompted for each	    *
// car structure data member, and these will be assigned to elements of *
// the carStock array. Nothing will be returned from this function      *
//***********************************************************************
void AutoDealer::inputCarInfo()
{
	// Initialize a constant to represent the maximum number of
	// cars that can be in the carStock array, this will be the
	// same as the size of the carStock array
	const int MAX_NUM_OF_CARS{ 20 };

	// Use if statment to determine if the carStock array is full
	if (carCount >= MAX_NUM_OF_CARS)
	{
		// If the carStock array is full, notify the user, 
		// and exit the function
		cout << "\n\nThere is no more room in the stockroom. Cannot add";
		cout << " vehicles at this time.\n";
		return;
	}

	int qty_to_enter;

	// Prompt user for number of vehicles to enter, and assign to qty_to_enter
	cout << "\nHow many vehicles do you need to enter?: ";
	cin >> qty_to_enter;

	// Use while loop to continually prompt the user until a 
	// quantity that will fit in inventory is enters, or the
	// enters 0 to cancel request
	while ((carCount + qty_to_enter) >= MAX_NUM_OF_CARS)
	{
		// Notify the user that the quntity they entered is too high
		// and display the amount of space left in inventory.
		cout << "\nThe quantity you entered is to high\n";
		cout << "There are " << MAX_NUM_OF_CARS - carCount;
		cout << " spaces left in inventory\n";

		// Reprompt user to enter a small enough quantity or to 
		// enter 0 to cancel request
		cout << "Enter a number equal to or less than ";
		cout << MAX_NUM_OF_CARS - carCount << " to add to inventory\n";
		cout << "or enter 0 to cancel request: ";
		cin >> qty_to_enter;
	}

	// This count variable will be compared against the qty_to_enter 
	// variable to ensure that the user doesn't get prompted to enter
	// more vehcles than requested
	int count{ 0 };

	// Use a for loop to prompt the user until the user has entered all data
	for (int index = carCount; count < qty_to_enter; index++)
	{
		// Because getline is used to assign make and model
		// any control characters in the buffer must be ignored
		cin.ignore();
		cout << "\nEnter car make and model: ";
		getline(cin, carStock[index].makeAndModel);

		// Prompt user to enter year
		cout << "Enter Vehicle Year: ";
		cin >> carStock[index].year;

		// Prompt user to enter color
		cout << "Enter vehicle color: ";
		cin >> carStock[index].color;

		// Prompt user to enter class
		cout << "Enter vehicle class: ";
		cin >> carStock[index].Class;

		// Prompt user to enter fuel type
		cout << "Enter fuel type: ";
		cin >> carStock[index].fuelType;

		// Prompt user to enter price
		cout << "Enter Price: ";
		cin >> carStock[index].price;

		// Use a while loop to validate that price is not negative
		while (carStock[index].price < 0)
		{
			// Reprompt user to enter a non-negative price
			cout << "\nVehicle prices cannot be negative, try again.\n";
			cout << "Enter Price: ";
			cin >> carStock[index].price;
		}

		// Add one to car inventory
		carCount++;

		// Add one to the loop control variable
		count++;
	}

	cout << endl;
}

//*************************************************************************
// This function accepts zero arguments. The searchCar functions purpose  *
// is to ask the user for data on the vehicle being seached for. If the   *
// vehicle is found, the vehicle information will be displayed for the    *
// user, and it's position in inventory will be returned.                 *
//*************************************************************************
int AutoDealer::searchCar()
{
	// Declare variable for data the will be
	// searched for in the carStock array
	string make_and_model;
	string car_color;
	string car_class;

	// Initilize position in inventory to -1, 
	// this will represent no data found
	int position{ -1 };

	// Ignore any control characters and ask user for vehicle make and model
	cin.ignore();
	cout << "Enter vehicle make and model: ";
	getline(cin, make_and_model);

	// Prompt user for vehicle color
	cout << "Enter vehicle color: ";
	cin >> car_color;

	// Prompt user for vehicle class
	cout << "Enter vehicle class: ";
	cin >> car_class;

	// User for loop to process the list while being searched
	for (int index = 0; index < carCount; index++)
	{
		// Use if statement to search the list for a vehicle that 
		// matched the vehicle being searched for by the user
		if (carStock[index].makeAndModel == make_and_model && 
			carStock[index].color == car_color && 
			carStock[index].Class == car_class)
		{
			// If a vehicle match is fount, assign it's index 
			// to position and terminate the loop
			position = index;
			break;
		}
	}

	// If the vehicle is found, display vehicle information to the user
	if (position != -1)
	{
		cout << "\n   Make and Model     Year  Color     Class    Fuel          Price\n";
		cout << "-----------------------------------------------------------------------\n";

		cout << left << setw(22) << carStock[position].makeAndModel;
		cout << left << setw(6) << carStock[position].year;
		cout << left << setw(10) << carStock[position].color;
		cout << left << setw(9) << carStock[position].Class;
		cout << left << setw(10) << carStock[position].fuelType;
		cout << right << setw(9) << setprecision(2) << fixed;
		cout << carStock[position].price << endl;
	}

	return position;
}


//************************************************************************
// This function accepts zero arguments. The displayCars functions		 *
// purpose it to Display to the user all vehicles currently in the		 *
// carStock array that represents the inventory. If there are no vehicles*
// to display, the user will be notified accordingly, otherwise, all	 *
// vehicles will be displayed, along with the combined price of all		 *
// vehicles. Nothing will be returned from this funcion.				 *
//************************************************************************
void AutoDealer::displayCars()
{
	// Check to see if there are any vehicles in inventory
	if (carCount == 0)
	{
		// If there are no vehicles to display, prompt user accordingly
		// and exit the function
		cout << "There are no cars to display.\n";
		return;
	}

	// Initialize variable to contain the total 
	// price of all vehicles in inventory
	double total_of_prices{ 0 };

	// Use a for loop to do a running total of the 
	// price of all vehicles in inventory
	for (int index = 0; index < carCount; index++)
	{
		total_of_prices += carStock[index].price;
	}

	// Display a table head over vehicle data table
	cout << "                 LEXINGTON, KY AUTO DEALER CAR INVENTORY\n";
	cout << "   MAKE AND MODEL     YEAR  COLOR     CLASS     FUEL        PRICE\n";
	cout << "-----------------------------------------------------------------------\n";

	// Use a for loop to process carStock array until 
	// all available vehicles have been displayed
	for (int index = 0; index < carCount; index++)
	{
		// This series of statements will output vehicle data 
		// formatted in a table that matches the table head above
		cout << left << setw(22) << carStock[index].makeAndModel;
		cout << left << setw(6) << carStock[index].year;
		cout<< left << setw(10) << carStock[index].color;
		cout << left << setw(9) << carStock[index].Class;
		cout << left << setw(10) << carStock[index].fuelType;
		cout << right << setw(9) << setprecision(2) << fixed;
		cout << carStock[index].price << endl;
	}

	// Display the total price of all vehicles in inventory
	cout << "\nTotal of all vehicles: $" << total_of_prices << endl;
	cout << endl;
}

//****************************************************************************
// This function accepts zero arguments. The writeCarsFile functions purpose *
// is to process the carStock array and write all data to a file. The data   *
// should be formatted in the same manner as the one used in the readCarFile *
// function, as this will be used by the readCarFile function when the		 *
// program is reopened. If there are no vehicles to be written, the user will*
// be notified accordingly. This function will return nothing                *
//****************************************************************************
void AutoDealer::writeCarsFile()
{

	// Check to see if there are any vehicles in inventory
	if (carCount == 0)
	{
		// Notify the user if there are no vehicles
		// in inventory and exit the function
		cout << "There are no cars to write to cars.txt file.\n";
		return;
	}

	// Open an output file object to write data to from the carStock array
	ofstream carFile{ "cars.txt" };


	int index;

	// Use a for loop to process the carStock array until 
	// all carStock data has been written to the file
	for (index = 0; index < carCount; index++)
	{
		// First, the make and model must be written to the file
		carFile << carStock[index].makeAndModel << endl;

		// Format the remaining data as follows

		// Eight spaces followed by the year, color, class, 
		// fuel type, and price, all seperated by a single space
		// will be written to the file. After this, the new file 
		// will match the old file format, and any new
		// data in the carStock array will be saved to the 
		// new file as well
		carFile << "        " << carStock[index].year << " ";
		carFile << carStock[index].color << " " << carStock[index].Class;
		carFile << " " << carStock[index].fuelType << " "; 
		carFile << fixed << setprecision(2) << carStock[index].price << endl;
	}


	carFile.close();
}

