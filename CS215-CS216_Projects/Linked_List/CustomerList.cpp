#include "CustomerList.h"
#include "CustomerNode.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Set all pointers to null pointers
CustomerList::CustomerList()
{
	head = nullptr;
	last_node = nullptr;
}



//***************************************************************************
// The insertNode function will accept 2 string arguments, one for name and *
// one for the service needed. It will also accept 5 integer arguments that *
// will state the month, day, year, hour, and minute respectivly. These     *
// Arguments will be assigned to the data members of a CustomerNode struct  *
// and the node will be inserted into a linked list							*
//***************************************************************************
void CustomerList::insertNode(string customer_name, string service_needed,
	int month_arrived, int day_arrived, int year_arrived,
	int hour_arrived, int minute_arrived)
{
	// declare two node pointers one for a new node, 
	// the other as a node to store information temporarily
	CustomerNode* new_node;
	CustomerNode* temp;

	// Dynamically allocate memory for a new customer node
	new_node = new CustomerNode;

	// Assign argument values to appropriate newNode data members
	new_node->name = customer_name;
	new_node->service_required = service_needed;
	new_node->month = month_arrived;
	new_node->day = day_arrived;
	new_node->year = year_arrived;
	new_node->hour = hour_arrived;
	new_node->minute = minute_arrived;
	new_node->next_node = nullptr;

	// If there are no nodes in the list
	// make newNode the fist and last node
	// and set sequence_number to 1
	if (!head)
	{
		head = new_node;
		last_node = new_node;
		new_node->sequence_number = 1;
	}

	//Otherwise insert newNode at the head
	else
	{
		// When inserting a new node, the current head must be 
		// assigned to a temporary variable so that the new head
		// can point to the old head
		temp = head;
		head = new_node;
		new_node->next_node = temp;

		// Assign a sequence number to the new node, this should
		// be the old heads sequence number + 1
		new_node->sequence_number = temp->sequence_number + 1;
	}
}

//************************************************************************
// The deleteNode member function will accept a string argument for name *
// This name will be searched for in the linked list and will be deleted *
// if the linked list contains it                                        *
//************************************************************************
void CustomerList::deleteNode(string name)
{
	CustomerNode* node_ptr = nullptr;
	CustomerNode* current_node = head;
	CustomerNode* previous_node = head;

	// If head is a null pointer, the list is empty
	if (!head)
		cout << "The list is empty.\n";

	// Otherwise the list is not empty and must be searched
	else
	{
		// Assign node_ptr to the pointer returned from the searchNode member function
		node_ptr = searchNode(name, current_node);

		// Use a while loop to search through the list until current_node points
		// to the node with the name being searched for, and previous_node points
		// to the node just before current node. This is needed to ensure the
		// linked list is not broken
		while (current_node->name != name && current_node->next_node != nullptr)
		{
			previous_node = current_node;
			current_node = previous_node->next_node;
		}

		// If node_ptr points to the head node pointer, assign head to it's
		// next_node data member, and delete the node_ptr
		if (node_ptr == head)
		{
			head = head->next_node;
			delete node_ptr;
		}
		
		// If node_ptr does not point to a null pointer and isn't the last node
		// assign the node before node_ptr to node_ptr next_node data member and delete node_ptr
		else if (node_ptr != nullptr && node_ptr != last_node)
		{
			previous_node->next_node = node_ptr->next_node;
			delete node_ptr;
		}

		// If node_ptr is the last node, assign the previous nodes next_node 
		// data member to nullptr, last_node to previous_node, and delete node_ptr
		else if (node_ptr == last_node)
		{
			previous_node->next_node = nullptr;
			last_node = previous_node;
			delete node_ptr;
		}
	}

}

//**********************************************************************************
// The searchNode member function will accept a string argument for name, and      *
// a CustomerNode pointer for the current node. It will recursively search the     *
// linked list for the name, and return it's pointer if found, or a nullptr if not *
//**********************************************************************************
CustomerNode *CustomerList::searchNode(string name, CustomerNode* current_node)
{

	// If the name is found, return a pointer the the node
	if (current_node->name == name)
	{
		return current_node;
	}

	// If the end of the linked list is reached without locating the name
	// return a null pointer
	if (current_node->next_node == nullptr)
		return nullptr;

	// Otherwise, continue to search the linked list
	else
	{
		return searchNode(name,current_node->next_node);
	}
}

//************************************************************************
// The serveCustomer member function accepts no arguments. This function *
// Will locate the node at the end of the linked list, display that they *
// have been served, and delete the customer from the linked list        *
//************************************************************************
void CustomerList::serveCustomer()
{
	
	// If the list is empty, notify the user
	if (!head)
	{
		cout << "There are no customers left to serve.\n";
		return;
	}

	// If there is only one node in the list, display that the 
	// customer has been served, delete the node, and reassign
	// head and last_node to nullptr
	if (head == last_node)
	{
		cout << "Customer number " << last_node->sequence_number << " has been served.\n";
		delete head;
		head = nullptr;
		last_node = nullptr;
	}

	// If the head is not a null pointer and is not the only node, 
	// search for the customer at the end of the linked list
	if (head)
	{
		// Define two pointers to customer node.
		// One pointer will follow another through the linked list
		CustomerNode* current_node = head;
		CustomerNode* previous_node = head;

		// Use a while loop to search for the customer at the end of the 
		// linked list, and continually reassign previous_node and
		// current_node such that previous_node points to the node before current_node
		while (current_node->sequence_number != last_node->sequence_number)
		{
			previous_node = current_node;
			current_node = previous_node->next_node;
		}

		// reassign nodes
		previous_node->next_node = nullptr;
		last_node = previous_node;

		// Display which customer has been served
		cout << "Customer number " << current_node->sequence_number << " has been served.\n";

		delete current_node;
	}

}

//*************************************************************************************
// The listAll member function will accept an argument for a CustomerNode pointer	  *
// The linked list will be proccessed recursively until the last node is reached, and *
// will then display all customers currently in the linked list                       *
//*************************************************************************************
void CustomerList::listAll(CustomerNode* node_ptr)
{

	// Base case
	// If the node pointer is a null pointer, return nothing
	if (!node_ptr)
	{
		return;
	}

	// Otherwise, call listAll again
	listAll(node_ptr->next_node);

	// Display Customer data with a zero added before minute to ensure proper digital clock display
	if (node_ptr->minute >= 0 && node_ptr->minute <= 9)
	{
		cout << node_ptr->sequence_number << setw(30) << node_ptr->name << setw(7) << node_ptr->month << "/" << node_ptr->day << "/";
		cout << node_ptr->year << setw(5) << node_ptr->hour << ":0" << node_ptr->minute << setw(20) << node_ptr->service_required << endl;
	}
	
	// Display Customer data without a zero added before minute
	else
	{
		cout << node_ptr->sequence_number << setw(30) << node_ptr->name << setw(7) << node_ptr->month << "/" << node_ptr->day << "/";
		cout << node_ptr->year << setw(5) << node_ptr->hour << ":" << node_ptr->minute << setw(20) << node_ptr->service_required << endl;
	}
}

CustomerList::~CustomerList()
{
	// If head is nullptr, return nothing
	if (!head)
	{
		return;
	}

	
	// Initialize two  pointers to customer node
	CustomerNode* temp = head->next_node;
	CustomerNode* current_node = head;

	// Use while loop to iterate through the linked list untill the end is reached
	while (current_node != nullptr)
	{
		// delete the current node, and reassign current_node the node following current_node
		// and temp to the node that follows temp
		delete current_node;
		current_node = temp;
		temp = temp->next_node;
	}

}

