#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>

enum class requestType 
    { Repair, Training, Purchase, Other};

// This class holds information about the customer such as
// 1. Arrival date
// 2. Sequence/Customer Number
// 3. Type of service requested
// 4. The Customers name
class Customer
{

private:
	
    // The tm* now will be used in the overloaded << operator
    // function to make it easier to display the time
	std::time_t timeStamp;	
    std::tm* now = localtime(&timeStamp);
    
    // uniqueSequenceNumber will assign a value to sequenceNumber and will 
    // be incremented by one every time the Customer constructor is called 
    static int uniqueSequenceNumber;
	int sequenceNumber;

	requestType customerRequest;
	
	std::string customerName;

public:
	Customer(std::string, requestType);

    //**************************************************
    // The getTimeStamp method will return the value of*
    // timeStamp which is of typw time_t               *
    //**************************************************
    std::time_t getTimeStamp() const;
    
    //**************************************************
    // The getSequenceNumber method will return an int *
    // sequence number of the Customer object          *
    //**************************************************
    int getSequenceNumber() const;
    
    //***********************************************
    // The getRequestType will return the customers *
    // request, which is of type requestType        * 
    //***********************************************
    requestType getRequestType() const;
    
    //***********************************************
    // The getName method will return the customers *
    // name as a string                             *
    //***********************************************
    std::string getName() const;
    
    //**********************************************
    // The getTimeNow method will return the tm*   *
    // instance variable now                       *
    //**********************************************
    std::tm* getTimeNow() const;
    
    //***********************************************
    // The overloaded == operator will check to see *
    // if the customer data members name, request,  *
    // and sequence number are the same and return  *
    // true if so, false otherwise                  *
    //***********************************************
    bool operator==(const Customer&) const;
    
    friend class Customers;
    friend std::ostream & operator<<(std::ostream& , const Customer&);
};

