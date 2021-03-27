#ifndef AUTODEALER_H
#define AUTODEALER_H
#include"Car.h"
#include <string>


// Define an AutoDealer class
class AutoDealer
{
private:

	// Create an array of 20 car structures and declare carCount
	Car carStock[20];
	int carCount{ };

public:

	// Use constructor to set car inventory (carCount) to zero
	AutoDealer()
	{
		carCount = 0;
	};

	// Declare all public member functions
	void readCarFile();
	void inputCarInfo();
	int searchCar();
	void displayCars();
	void writeCarsFile();
};

#endif // AUTODEALER_H
