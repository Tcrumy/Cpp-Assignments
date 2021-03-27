#ifndef ASSORTEDSORTER_H
#define ASSORTEDSORTER_H

// Declare Class
// Class member functions will be camel case to 
// distinguish them from functions outside of 
// class.
class AssortedSorter
{
private:
	int class_array[20001]{};
	int counter{}; 

public:
	void bubbleSort(int[], int, long int&, long int&);
	void selectionSort(int[], int, long int&, long int&);
	void shellSort(int[], int[], int, long int&, long int&);
	void quickSort(int[], int, int, int, long int&, long int&);
	int partition(int[], int, int, long int&, long int&);
	void swap(int&, int&);
	void displayClassArray();
	void setClassArray(int array[], int size);
};

#endif // ASSORTEDSORTER_H
