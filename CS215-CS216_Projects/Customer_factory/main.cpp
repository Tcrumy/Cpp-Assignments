#include <iostream>
#include "Customer.h"
#include "CustomerFactory.h"
#include "Customers.h"
#include <string>
#include <vector>


void assert(const bool, const std::string&);

int main() {
    
    std::vector <std::string> names = {"Customer1", "Customer2", "Customer3", "Customer4", "Customer5", "Customer6"};
    std::vector <requestType> requests = 
    {requestType::Training, requestType::Repair, requestType::Training, requestType::Purchase, requestType::Other};
    
    // These variables will be passed to assert in order to properly display which
    // unit test failed
    std::string test1{"Test 1"}, test2{"Test 2"}, test3{"Test 3"}, test4{"Test 4"};
    
    // Unit test, TEST CASE 1
    {
        // Arrange
        Customers customers_1;
        for(int name_index = 0; name_index < 3; name_index++)
        {
            customers_1.add(names[name_index], requests[name_index]);
        }
        
        // Act
        Customer cus_2 = customers_1.search(names[1]);
        Customer cus_1 = customers_1.search(names[0]);
        Customer cus_3 = customers_1.search(names[2]);
        Customer cus_4 = customers_1.search(names[4]);
        
        // Assert
        assert(cus_2.getName() == names[1], test1);
        assert(cus_1.getName() == names[0], test1);
        assert(cus_3.getName() == names[2], test1);
        assert(cus_4.getName() == "", test1);
    }
    
    // Unit test, TEST CASE 2
    {
        // Arrange
        Customers customers_2;
        for(int name_index = 0; name_index < 3; name_index++)
        {
            customers_2.add(names[name_index], requests[name_index]);
        }
        
        // Act
        customers_2.remove(names[2]);
        Customer cus_2 = customers_2.search(names[1]);
        customers_2.remove(names[0]);        
        Customer cus_1 = customers_2.search(names[0]);
        cus_2 = customers_2.search(names[1]);       
        
        // Assert
        assert(cus_2.getName() == names[1], test2);
        assert(cus_1.getName() == "", test2);
    }
    
    // Unit test, TEST CASE 3
    {
        // Arrange
        Customers customers_3;
        for(int name_index = 0; name_index < 5; name_index++)
        {
            customers_3.add(names[name_index], requests[name_index]);
        }
        
        bool outputResult{false};
        
        //Act
        {
            std::cout << customers_3;
            outputResult = true;
        }
        
        // Assert
        if(!outputResult)
        {
            std::cout << "Unit " << test3 << " Failed: Exiting Program\n";
            exit(1);
        }
    }
    
    //Unit Test, TEST CASE 4
    {
        // Arrange
        Customers customers_4;
        for(int name_index = 0; name_index < 3; name_index++)
        {
            customers_4.add(names[name_index], requests[name_index]);
        }
   
        // Act
        Customer customer_1 = customers_4.search(names[0]);
        Customer customer_2 = customers_4.search(names[1]);
        Customer customer_3 = customers_4.search(names[2]);
        Customer customer_4 = customers_4.search(names[3]);
        Customer customer_5 = customer_1;
        
        //Assert
        assert(!(customer_1 == customer_2), test4);
        assert(!(customer_1 == customer_3), test4);
        assert(!(customer_2 == customer_3), test4);
        assert(customer_4.getName() == "", test4);
        assert(customer_1 == customer_5, test4);
    }

    
	return 0;
}

//***********************************************************
// The assert function will accept a bool and std:string as *
// parameters. If the bool is false, a message will display *
// which unit test failed, and the program will be exited   *
// assert returns nothing.                                  *
//***********************************************************
void assert(const bool customer_check, const std::string &test_number)
{
    if(!customer_check)
    {
        std::cout << "Unit " << test_number << " Failed: Exiting Program\n";
        std::exit(EXIT_FAILURE);
    }
    
}

