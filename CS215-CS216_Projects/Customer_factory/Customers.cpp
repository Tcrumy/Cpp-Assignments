#include "Customers.h"


//*****************
// The add method *
//*****************
void Customers::add(const std::string &name, const requestType &request)
{
    // Add customer to the CustomerList
    CustomerList.push_back(CustomerFactory::NewCustomer(name, request));
}

//****************
// remove method *
//****************
void Customers::remove(const std::string &name)
{
    // Iterate through the entire CustomerList to search for the 
    // Customer object with the name passed into the method
    for(std::list <Customer>::iterator it = CustomerList.begin(); it != CustomerList.end(); it++)
    {
        // Remove the Customer object from CustomerList if found
        if(it->customerName == name)
        {
            CustomerList.erase(it);
            return;
        }
    }
}

//****************
// search method *
//****************
Customer &Customers::search(const std::string &name)
{
    // Iterate through the entire CustomerList to search for the 
    // Customer object with the name passed into the method
    for(std::list <Customer>::iterator it = CustomerList.begin(); it != CustomerList.end(); it++)
    {
        // Return the Customer object if it is found in the CustomerList
        if(it->customerName == name)
        {
            return *it;
        }
    }
    
    // emptyCustomer has no name, and a requestType of 
    // Other. It can be thought of a a default customer
    // in a case where the customer being searched for 
    // is not found
    return emptyCustomer;
}

//*************************
// overloaded << operator *
//*************************
std::ostream  &operator<<(std::ostream &out, const Customers &rhs)
{
    // Create a copy of the CustomerList
    std::list <Customer> customers_list = rhs.CustomerList;
    
    // Itereate through the entire list, and give each customer
    // dereferenced object to the "out" reference variable
    for(std::list <Customer>::iterator it = customers_list.begin(); it != customers_list.end(); it++)
    {
        out << *it << std::endl;
    }
    
    return out;
}
