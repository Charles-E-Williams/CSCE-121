#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include <string>
#include "Node.h"

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	// Default constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Copy constructor
	LinkedList(const LinkedList& other);

	// Copy assignment
	LinkedList& operator=(const LinkedList& other);

	// Insert a record to the linked list
	void insert(std::string location, int year, int month, double temperature);

	// Clear the content of this linked list
	void clear();

	// The functions below are written already. Do not modify them.
	std::string print() const;

	//used for unit testing
	Node* getHead() const {return head;}

	//student function: removes redundant code in copy constructor and copy assignment operator
	void copyList(const LinkedList& other);

	//Student function: get average based on id and year range
	double getAVG(std::string id, int start_year, int end_year);

	//student function: get mode based on id and year range
	int getMode(std::string id, int start_year, int end_year);

	//count the number of equal temperature values based on location and year range
	int countEqual(std::string id, int year1, int year2);

	//student function: get size of linked list based on id,range and temperature value 
	//used to find instances in which there is no data
	int getSize(std::string id, int startYear, int endYear);
	

	// //student function: insert in order as shown in the file: EDIT NOT NEEDED
	// void push_back(std::string id, int year, int month, double temperature);
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
#endif