#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "AssortedSorter.h"

using namespace std;

// non_class functions will be underscored
// to distingush them from class member functions
int get_num_of_numbers();
void assign_numbers_to_array(int[], int);
void display_data(int, int, int, int, int, int, int, int);


int main()
{
	// Declare and initialize variables
	int num_array[20001]{}, user_num_of_numbers{};
	int sequence[]{ 364, 121,40,13,4,1,0 };

	// Assign an array size to user_num_of_numbers
	user_num_of_numbers = get_num_of_numbers();


	// If user selects - 1 in the get_num_of_numbers() function
	// a default value of 10000 will be used as array size
	// and 10000 random values will be assigned to array
	if (user_num_of_numbers == -1)
	{
		user_num_of_numbers = 10000;
		assign_numbers_to_array(num_array, user_num_of_numbers);
	}

	// User has selected between 10 - 20000 random numbers to be assigned
	// to num_array
	else
	{
		assign_numbers_to_array(num_array, user_num_of_numbers);
	}

	// Create an instance of AssortedSorter called sorter
	AssortedSorter sorter;


	// Declare and initialize variables to count loops and swaps
	// in bubbleSort
	long int bubble_loop{}, bubble_swap{};
	sorter.bubbleSort(num_array, user_num_of_numbers, bubble_loop, bubble_swap);
	

	// Declare and initialize variables to count loops and swaps
	// in selectionSort
	long int selection_loop{}, selection_swap{};
	sorter.selectionSort(num_array, user_num_of_numbers, selection_loop, selection_swap);
	

	// Declare and initialize variables to count loops and swaps
	// in shellSort
	long int shell_loop{}, shell_swap{};
	sorter.shellSort(num_array, sequence, user_num_of_numbers, shell_loop, shell_swap);
	

	// Declare and initialize variables to count loops and swaps
	// in quickSort
	long int quick_loop{}, quick_swap{};
	sorter.quickSort(num_array, user_num_of_numbers, 0, user_num_of_numbers - 1, quick_loop, quick_swap);
	

	cout << endl;

	// Display to console the algorithmic efficiency of each sort
	display_data(bubble_loop, bubble_swap, selection_loop, selection_swap, shell_loop,
		shell_swap, quick_loop, quick_swap);

	cout << endl;

	return 0;
}

//*************************************************
// This function will accept no parameters        *
// The user will be prompted to enter a number    *
// of numbers to be generated. This value will be *
// validated then returned                        *
//*************************************************
int get_num_of_numbers()
{
	int user_choice{ 0 };

	// Prompt user to enter a number and assign to user_choice
	cout << "How many numbers should be generated\n";
	cout << "Please enter a value between 10 and 20000\n";
	cout << "or enter -1 for the program to choose for you: ";
	cin >> user_choice;

	// Validate that user_choice is within range and reprompt user accordingly
	while ((user_choice > 20000 || user_choice < 10) && user_choice != -1)
	{
		// user_choice was out of range, reprompt the user
		cout << "That was not a valid choice, try again\n";
		cout << "Please enter a value between 10 and 20000\n";
		cout << "or enter -1 for the program to choose for you: ";
		cin >> user_choice;
	}

	return user_choice;
}

//****************************************************
// This function will accept an integer array and    *
// an integer for array size, and assign size        *
// number of random  integers to the array           *
//****************************************************
void assign_numbers_to_array(int array[], int size)
{
	// Seed srand to generate random numbers
	srand(time(0));

	// Use for loop to assign random numbers
	// to array
	for (int index{ 0 }; index < size; index++)
	{
		array[index] = rand() % 1000000 + 1;
	}
}


//********************************************************************
// This function will accept parameters for all loop and swap counts *
// it will then display an itemized list showing the algorithm run   *
// efficiency                                                        *
//********************************************************************
void display_data(int bubble_loops, int bubble_swaps, int slection_loops, int selection_swaps,
	int shell_loops, int shell_swaps, int quick_loops, int quick_swaps)
{
	// Display itemized algorithm efficiency to the console
	cout << "SORT ALGORITHM RUN EFFICIENCY\n\n";
	cout << "ALGORITHM\t\t LOOPCOUNT \t DATA MOVEMENT\n";
	cout << "Bubble   \t\t" << setw(10) << bubble_loops << " \t " << setw(13) << bubble_swaps << endl;
	cout << "Selection\t\t" << setw(10) << slection_loops << " \t " << setw(13) << selection_swaps << endl;
	cout << "Shell    \t\t" << setw(10) << shell_loops << " \t " << setw(13) << shell_swaps << endl;
	cout << "Quick    \t\t" << setw(10) << quick_loops << " \t " << setw(13) << quick_swaps << endl;
}