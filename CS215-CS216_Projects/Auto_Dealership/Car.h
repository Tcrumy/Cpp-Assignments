#ifndef CAR_H
#define CAR_H
#include <string>



// Define a structure that represents a vehicle
struct Car
{
	std::string makeAndModel{};
	int year{};
	std::string color{};
	std::string Class{};
	std::string fuelType{};
	double price{};
};
#endif // CAR_H