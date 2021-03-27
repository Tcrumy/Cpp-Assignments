#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include <string>
#include "CustomerNode.h"
using namespace std;

class CustomerList
{
private:

	// Pointers to first and last node in the linked list
	CustomerNode* head;
	CustomerNode* last_node;

public:


	CustomerList();

	// Class member functions
	void insertNode(string, string, int, int, int, int, int);
	void deleteNode(string);
	CustomerNode* searchNode(string, CustomerNode*);
	void serveCustomer();
	void listAll(CustomerNode *);
	CustomerNode* getHead()
	{
		return head;
	}

	~CustomerList();


};

#endif // CUSTOMERLIST_H
