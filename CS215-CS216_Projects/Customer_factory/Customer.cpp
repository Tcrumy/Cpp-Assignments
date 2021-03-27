#include "Customer.h"


int Customer::uniqueSequenceNumber = 1;


//*****************************************************
// Builds customer with user defined name and request *
//*****************************************************
Customer::Customer(std::string name, requestType request)
{
	timeStamp = std::time(0);
	sequenceNumber = uniqueSequenceNumber;
	customerRequest = request;
	customerName = name;
	uniqueSequenceNumber++;
}

//**********************
// getTimeStamp method *
//**********************
std::time_t Customer::getTimeStamp() const
{
    return timeStamp;
}

//***************************
// getSequenceNumber method *
//***************************
int Customer::getSequenceNumber() const
{
    return sequenceNumber;
}

//************************
// getRequestTypr method *
//************************
requestType Customer::getRequestType() const
{
    return customerRequest;
}

//*****************
// getName method *
//*****************
std::string Customer::getName() const
{
    return customerName;
}

//********************
// getTimeNow Method *
//********************
std::tm* Customer::getTimeNow() const
{
    return now;
}

//*********************************************************
// Overloaded << operator to define outpur behavior for a *
// customer object                                        *
//*********************************************************
std::ostream &operator<<(std::ostream &out , const Customer &rhs)
{
    // Create a tm* so to make displaying date/time easier
    std::tm* currentTime = rhs.getTimeNow();
    
    // minute prefix will be used to properly display a digital clock
    std::string minute_prefix = "";
    
    if(currentTime->tm_min < 10)
    {
        minute_prefix = "0";
    }
    
    requestType request = rhs.getRequestType();
    std::string requestAsString{};
    
    // Use a switch case to determine a proper string
    // representation for the customers request
    switch(request)
    {
        case requestType::Repair:
            requestAsString = "Repair";
            break;
        case requestType::Training:
            requestAsString = "Training";
            break;
        case requestType::Purchase:
            requestAsString = "Purchase";
            break;
        case requestType::Other:
            requestAsString = "Other";
            break;
        default:
            requestAsString = "Default";
            break;
    }
    
    
    out << std::setw(2) << rhs.getSequenceNumber() << std::setw(15)<< rhs.getName() << std::setw(5) 
    << (currentTime->tm_mon + 1) << "\\" << currentTime->tm_mday << "\\" << (currentTime->tm_year + 1900)
    << std::setw(4) << currentTime->tm_hour << ":" << minute_prefix << currentTime->tm_min <<  std::setw(10)
    << requestAsString << std::endl; 
    
    return out;
}

//*******************************
// overladed == operator method *
//*******************************
bool Customer::operator==(const Customer &rhs) const
{
    // The customers name, request, and sequence number
    // will be what defines a customer as equal to 
    // another customer
    return(rhs.getName() == customerName &&
           rhs.getRequestType() == customerRequest &&
           rhs.getSequenceNumber() == sequenceNumber);
    
}

