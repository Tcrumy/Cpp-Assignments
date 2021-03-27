#pragma once
#include <list>
#include <string>
#include <ostream>
#include "Customer.h"
#include "CustomerFactory.h"

// The Customers class will create a list to hold Customer objects
// It will provide an interface to add, remove, or search for Customers
// in the list, which is of type std::list
class Customers
{
    
private:
    std::list<Customer> CustomerList;
    
    // This customer is what will be returned form the search 
    // function if the customer being searched for is not found
    Customer emptyCustomer = CustomerFactory::NewCustomer("", requestType::Other);
    
public:

    
    //********************************************************************
    // The add method will take a string name, and a requestType request *
    // as parameters. These values will be given to the CustomerFactory  *
    // newCustomer method, and a new customer with that name and request *
    // will be added to the list CustomerList nothing is returned        *
    //********************************************************************
    void add(const std::string&, const requestType&);
    
    //**********************************************************************
    // The remove method will accept the string name of a customer as a    *
    // parameter. The name will be searched for and if found, the customer *
    // object will be removed. Nothing will be returned                    *
    //**********************************************************************
    void remove(const std::string &);
    
    //*********************************************************************
    // The search method will accept a string name as a parameter. The    * 
    // CustomerList will be searched for a Customer object that has that  *
    // name. If found, that customer will be returned, otherwise, the     *
    // emptyCustomer data member will be returned containing the values of*
    // the default constructor for Customer objects                       *
    //*********************************************************************
    Customer &search(const std::string&);
    
    //*******************************************************************
    // The overloaded << operator will define output behavior for the  *
    // Customers object. An iterator will be created, and each element *
    // of the CustomerList will be added to the ostream reference. The *
    // ostream reference will be returned                              *
    //******************************************************************
    friend std::ostream & operator<<(std::ostream & , const Customers &);
    
  

};

