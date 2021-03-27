#include "CustomerFactory.h"
#include <string>

Customer CustomerFactory::NewCustomer(const std::string &name, const requestType &request)
{
	return Customer(name, request);
}
