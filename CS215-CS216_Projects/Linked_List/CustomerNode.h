#ifndef CUSTOMERNODE_H
#define CUSTOMERNODE_H
#include <string>
using namespace std;

// structure to represent customer as a node
struct CustomerNode
{
	unsigned int sequence_number{};
	string name{}, service_required{};
	int month{}, day{}, year{}, hour{}, minute{};
	struct CustomerNode* next_node{ nullptr };
};

#endif // CUSTOMERLIST_H
