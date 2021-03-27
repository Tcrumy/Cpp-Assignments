#include "AssortedSorter.h"
#include <iostream>

using namespace std;


//****************************************************
// bubbleSort will accept parameters for an integer  *
// array, an integer for size of the array, a long   *
// int to count loops, and a long int to count swaps *
// The array that is passed to bubbleSort will be    *
// copied to the class_array and the class array will*
// be sorted.                                        *
//****************************************************
void AssortedSorter::bubbleSort(int array[], int size,
	long int& loop_count, long int& swap_count)
{
	// initialize loop and swap counters to zero
	loop_count = 0;
	swap_count = 0;

	// copy array to class_array
	setClassArray(array, size);

	// Initialize variables used in do while loop
	bool swap{ false };
	int temporary_num{};

	// Do while loop will continue until no more swaps are made
	do
	{
		swap = false;

		// Iterate through elements in the array and
		// sort them in accending order
		for (int index = 0; index < (size - 1); index++)
		{
			loop_count++;

			// Use if to check if neigboring elements need
			// to be swapped
			if (class_array[index] > class_array[index + 1])
			{
				swap_count++;

				// Swap neighboring elements
				temporary_num = class_array[index];
				class_array[index] = class_array[index + 1];
				class_array[index + 1] = temporary_num;
				swap = true;
			}
		}
	} while (swap);
	// Do while loop ends here. Array should be sorted
}

//******************************************************
// selectionSort will accept parameters for an integer *
// array, an integer for size of the array, a long     *
// int to count loops, and a long int to count swaps   *
// The array that is passed to selectionSort will be   *
// copied to the class_array and the class array will  *
// be sorted.                                          *
//******************************************************
void AssortedSorter::selectionSort(int array[], int size,
	long int& loop_count, long int& swap_count)
{
	// Initialize loop and swap counters to zero
	loop_count = 0;
	swap_count = 0;

	// copy array to class_array
	setClassArray(array, size);

	// Initialze variable to be used in for loop
	int start_scan{ 0 }, min_index{ 0 }, min_value{ 0 };

	// Use nested for loops to compare array elements
	for (start_scan = 0; start_scan < (size - 1); start_scan++)
	{
		// Initialize variables used in inner for loop
		min_index = start_scan;
		min_value = class_array[start_scan];

		// Use inner for loop to scan all elements after
		// the element at index start_scan and swap values
		// if nessecary       
		for (int index = start_scan + 1; index < size; index++)
		{
			loop_count++;

			// Use if statement to determine if values need
			// to be swapped
			if (class_array[index] < min_value)
			{
				// Set values to prepare the for swapping
				min_value = class_array[index];
				min_index = index;
			}
		}

		swap_count++;

		// Swap values into their correct positions
		class_array[min_index] = class_array[start_scan];
		class_array[start_scan] = min_value;
	}

}

//******************************************************
// shellSort will accept parameters for an integer     *
// array, a sequence array an integer for size of the  *
// array, a long int to count loops, and a long int to *
// count swaps. The array that is passed to shellSort  *
// will be copied to the class_array and the class     *
// array will be sorted.                               *
//******************************************************
void AssortedSorter::shellSort(int array[], int sequence[], int size,
	long int& loop_count, long int& swap_count)
{
	// Initialize loop and swap counters to zero
	loop_count = 0;
	swap_count = 0;

	// Copy array to class array
	setClassArray(array, size);

	// Declare an initialize variables used in loop
	int step{ 0 }, index{ 0 }, start{ 0 }, stop{ size - 1 };

	// Use nested loops to swap class_array values
	for (step = 0; sequence[step] >= 1; step++)
	{
		// Declare initialize inc variable
		int inc = sequence[step];

		// Use inner for loop to iterate through all elements
		// starting at inc until the end of the array is reached
		for (index = start + inc; index <= stop; index++)
		{
			// Declare and initialize variables that wil be used 
			// setup swap values
			int index_2 = index;
			int value = class_array[index];

			// Use while loop to check value against the value
			// at class_array[index_2 - inc] and swap if required
			while ((index_2 >= start + inc) && value < class_array[index_2 - inc])
			{
				loop_count++;

				// Reassign class_array[index-2]
				class_array[index_2] = class_array[index_2 - inc];
				index_2 -= inc;
			}

			swap_count++;
			// Swap remaining value
			class_array[index_2] = value;

		}
	}
}

//********************************************************
// quickSort will accept parameters for an integer       *
// array, an integer for size of the and integer for     *
// start, an integer for stop, a long int to count loops,* 
// and a long int to count swaps. The array that is      *
// passed to shellSort will be copied to the             *
// class_array and the class array will be sorted.       *
//********************************************************
void AssortedSorter::quickSort(int array[], int size, int start, int stop,
	long int& loop_count, long int& swap_count)
{
	// Initialize loop and swap counters to zero
	loop_count = 0;
	swap_count = 0;

	// Copy array to class_array
	setClassArray(array, size);

	// Initialize values that will control loops 
	int index{ 0 }, stack_increment{ 0 }, stack[20001]{};

	// Assign values to the stack array
	stack[stack_increment++] = start;
	stack[stack_increment++] = stop;

	while (stack_increment > 0)
	{
		// Assign values from stack array to start
		// to create a left reference and stop to 
		// create a pivot
		stop = stack[--stack_increment];
		start = stack[--stack_increment];

		// If start is larger that stop, go to the beginning 
		// of the while loop and reassign values to start and stop 
		if (start >= stop)
		{
			continue;
		}

		// Use partition to assign value to index
		index = partition(class_array, start, stop, loop_count, swap_count);

		// Use if else decision structure to
		// determine how pivot values must be 
		// reassigned
		if (index - start > stop - index)
		{
			// reassign pivot values
			stack[stack_increment++] = start;
			stack[stack_increment++] = index - 1;
			stack[stack_increment++] = index + 1;
			stack[stack_increment++] = stop;
		}

		else
		{
			// reassign pivot values
			stack[stack_increment++] = index + 1;
			stack[stack_increment++] = stop;
			stack[stack_increment++] = start;
			stack[stack_increment++] = index - 1;
		}
	}
}

//*************************************************************
// The partition function will accept parameters for an       *
// integer array, an integer start value, an integer stop     *
// value, a long int reference to count loops, and a long int *
// reference to count swaps. Partition loop through and sort  *
// the array that is passed into it.                          *
//*************************************************************
int AssortedSorter::partition(int array[], int start, int stop,
	long int& loop_count, long int& swap_count)
{
	// Declare and assign swap control variables
	int up{ start }, down{ stop - 1 }, part{ array[stop] };

	// If this condition is met
	// values will be reassigned in
	// quickSort function
	if (stop <= start)
	{
		return start;
	}

	// Continue looping until the entire array has been
	// itereated through
	while (true)
	{
		// Continue looping from left side of the array
		// until an array value is found that is equal or
		// greater than part. up will be used as a index
		// value for swapping
		while (array[up] < part)
		{
			loop_count++;
			up++;
		}

		// Continue looping from right side of array
		// until a value is found that is less than
		// part, or up is >= down. down will be used
		// as an index value for swapping
		while ((part < array[down]) && (up < down))
		{
			loop_count++;
			down--;
		}

		// If up and down are equal, or up is larger
		// than down, they will not be swapped
		if (up >= down)
		{
			break;
		}

		swap_count++;

		// Swap array values
		swap(array[up], array[down]);
		up++;
		down--;
	}

	swap_count++;

	// Swap array values
	swap(array[up], array[stop]);

	return up;
}

//****************************************************
// The sawp function will accept 2 integer reference *
// values, and swap them with each other             *
//****************************************************
void AssortedSorter::swap(int& val1, int& val2)
{
	// Declare temp to be used as temporary value
	int temp{ 0 };

	// swap val1 and val 2
	temp = val1;
	val1 = val2;
	val2 = temp;
}

//*****************************************************************
// The setClassArray function will accept parameters for an       *
// integer array, and an integer size for that array. The values  *
// in the array will be copied to the class_array member variable *
//*****************************************************************

void AssortedSorter::setClassArray(int array[], int size)
{
	// Use a for loop to assign array to class_array
	// one element at a time
	for (int index = 0; index < size; index++)
	{
		class_array[index] = array[index];
	}

	// set counter member variable to size of the array
	counter = size;

}


//***********************************************
// This function accepts no parameters			*
// It will display class array to the console.  *
// It serves the purpose of debugging to ensure *
// that class_array contains the correct values *
// in the correct order							*
//***********************************************
void AssortedSorter::displayClassArray()
{

	for (int index = 0; index < counter; index++)
	{
		cout << class_array[index] << " ";
	}
}





