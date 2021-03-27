#pragma once
#include "Customer.h"
#include <string>

// The Cusomer factory class will build a new customer
class CustomerFactory
{
public:

    //**********************************************************
    // The newCustomer method will accept a string for name    *
    // and a requestType for request. It will return a Customer*
    // object that has that name and request passed to it's    *
    // constructor                                             *
    //**********************************************************
	static Customer NewCustomer(const std::string&, const requestType&);
};

