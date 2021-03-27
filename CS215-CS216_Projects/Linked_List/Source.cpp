#include <iostream>
#include <string>
#include "CustomerList.h"
#include "CustomerNode.h"

using namespace std;

// Global Constants For Menu Choices
const int NEW_CUSTOMER_ARRIVAL = 1;
const int SERVE_CUSTOMER = 2;
const int CUSTOMER_LEFT = 3;
const int LIST_ALL_CUSTOMERS = 4;
const int QUIT_CHOICE = 5;

int get_user_choice(int);
void get_information(string&, string&, int&, int&, int&, int&, int&);

int main()
{
	// Instatiate CustomerList object here
	CustomerList customers;
	
	// Will hold value for users choice
	int user_choice{};
	
	// Variables for inserting/deleting nodes
	string name{}, service_needed{};
	int month{}, day{}, year{}, hour{}, minute{};

	// Create do while loop menu
	do
	{

		
		user_choice = get_user_choice(user_choice);

		// User switch to handle member function selection
		// for CustomerList object
		switch (user_choice)
		{
			// If user selects new customer arrival option, get all reqired infomation
			// from user, and pass information to the insertNode member function
			case(NEW_CUSTOMER_ARRIVAL):
				get_information(name, service_needed, month, day, year, hour, minute);
				customers.insertNode(name, service_needed, month, day, year, hour, minute);
				break;

			// If user selects serve customer option, call serveCustomer member
			// function to delete the customer at the end of the linked list
			case(SERVE_CUSTOMER):
				customers.serveCustomer();
				break;

			// If user selects customer left option, prompt user to enter the leaving customers
			// name, pass the name to the deleteNode member function and remove the 
			// customer from the linked list
			case(CUSTOMER_LEFT):
				cin.ignore();
				cout << "Enter name: ";
				getline(cin, name);
				customers.deleteNode(name);
				break;

			// If the user selects list all customer option, assign a pointer to the head of the linked list,
			// pass the head to the listAll member function, and display and itemized list of all customers
			// still in the linked list
			case(LIST_ALL_CUSTOMERS):
				CustomerNode* head;
				head = customers.getHead();
				cout << "Sequence            Name              Date      Time         Service\n";
				cout << "---------------------------------------------------------------------------\n";
				customers.listAll(head);			
				break;

			// If the user selects quit choice, exit the program
			case(QUIT_CHOICE):
				break;
		}

	} while (user_choice != QUIT_CHOICE);
	// End do-while loop when the user selects the quit choice option

	return 0;
}

//**************************************************
// This function will accept a parameter           *
// for for the users choice and will assign a      *
// valid choice to  the argument from user prompt  *
//**************************************************
int get_user_choice(int choice)
{
	cout << endl;
	// Prompt user to choose from menu and assign choice to user_choice
	cout << "Please select from the following options\n";
	cout << "----------------------------------------\n";
	cout << "1. New Customer Arrival\n";
	cout << "2. Serve Customer\n";
	cout << "3. Remove Customer From Waiting List\n";
	cout << "4. List All Current Customers\n";
	cout << "5. Quit Program\n";
	cout << "Your choice is: ";
	cin >> choice;
	cout << endl;

	// Validate that user_choice is in range
	while (choice < 1 || choice > 5)
	{
		// reprompt user if choice was invalid
		cout << "Choice was invalid\n";
		cout << "Please select from the following options\n";
		cout << "----------------------------------------\n";
		cout << "1. New Customer Arrival\n";
		cout << "2. Serve Customer\n";
		cout << "3. Remove Customer From Waiting List\n";
		cout << "4. List All Current Customers\n";
		cout << "5. Quit Program\n";
		cout << "Your choice is: ";
		cin >> choice;
		cout << endl;
	}

	cout << endl;
	return choice;
}

//*************************************************************************************************
// This function will accept 2 string reference parameters and 5 integer reference parameters     *
// The user will be prompted to enter their name, the service required, the month, day, and year  *
// the hour and the minute. The users answers will be assigned to the appropirate variables       *
// Answers that require some form of range validation will be validated                           *
//*************************************************************************************************
void get_information(string& name, string& service, int& month, int& day, int& year, int& hour, int& minute)
{

	// Clear keyboard buffer
	cin.ignore();

	// Prompt user to enter name, and assign to name
	cout << "Enter your name: ";
	getline(cin, name);

	// Prompt user to enter the service needed and assign to service
	cout << "Enter the service you require: ";
	getline(cin, service);

	// Prompt user to enter month number and assign to month
	cout << "Enter two digit month as integer: ";
	cin >> month;

	// Validate that month is in correct range
	while (month < 1 || month > 12)
	{
		// Reprompt user if month is out of range and assign to month
		cout << "Month must be between 1 and 12, enter again: ";
		cin >> month;
	}

	// Prompt user to enter the day of the month and assign to day
	cout << "Enter day of month as integer: ";
	cin >> day;

	// The months of January, March, May, July, August, October, and December have 31 days
	// validate the day number entered to ensure that it the day variable is within range
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		while (day < 1 || day > 31)
		{
			// Reprompt user if day is out of range and assign to day
			cout << "Day must be between 1 and 31, enter again: ";
			cin >> day;
		}
	}

	// The months if April, June, September, and November have 30 days
	// Validate the day number entered to ensure the day variable is within range
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		while (day < 1 || day > 30)
		{
			// Reprompt user if day is out of range and assign to day
			cout << "Day must be between 1 and 30, enter again: ";
			cin >> day;
		}
	}

	// The month of Febuary has 28 days, except on leap years, this program
	// will not check for leap years. Validate that day number is in range
	else
	{
		while (day < 1 || day > 28)
		{
			// Reprompt user if day is out of range and assign to day
			cout << "Day must be between 1 and 28, enter again: ";
			cin >> day;
		}
	}

	// prompt user to enter two digit year and assign to year
	cout << "Enter two digit year as integer: ";
	cin >> year;

	// prompt user to enter hour and assign to hour
	cout << "Enter hour as integer: ";
	cin >> hour;

	// Validate that the hour variable is within range
	while (hour < 0 || hour > 12)
	{
		// Reprompt user if hour is out of range and assign to hour
		cout << "Hour must be between 0 and 12, enter again: ";
		cin >> hour;
	}

	// Prompt user to enter two digit minute and assign to minute
	cout << "Enter two digit minute as integer: ";
	cin >> minute;

	// Validate that minute is in range
	while (minute < 0 || minute > 59)
	{
		// Reprompt user if minute is out of range and assign to minute
		cout << "Minute must be between 0 and 59, enter again: ";
		cin >> minute;
	}
	
	cout << endl;
}