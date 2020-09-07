#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

/*I was submitting part one homework files the entire time LOL 
  I spent so long trying to optimize the speed of my code when
  in reality I wasn't even turning in the right files.
  Here's to hoping the timeout isn't actually as strict 
  as I originally believed it to be. This assignemt has not been 
  kind to me AT ALL ಠ╭╮ಠ but that's my fault D: 
*/
LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {this->clear();}//destructor


LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr) { copyList(source);}//copy constructor

LinkedList& LinkedList::operator=(const LinkedList& source) { //overload assignment operator

	if (this == &source) return *this;
	
	else {
		this->clear(); //clear existing LL (LHS)
		this->copyList(source);
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {

	/* NOTE: The prompt asks for 
	the LL to be in ascending order
	*/

	Node* newNode = new Node(location,year,month,temperature);
	if (head == nullptr && tail == nullptr) 
	{
		head = newNode; tail = newNode;
	}//create list if empty ^^ 
	 
	else {

		if (*newNode < *head) //prepend node, special case
		{
			newNode->next = head; head = newNode;
		}

		else 
		{	
			Node* temp = nullptr;
			Node* currPtr = head->next;
			Node* prevPtr = head;

			while (currPtr != nullptr)
			{
				if (*newNode < *currPtr) 
				{
					temp = currPtr;
					currPtr = nullptr; //exit condition
				}

				else 
				{	
					prevPtr = prevPtr->next; 
					currPtr = currPtr->next;
				}	
			}		
			
			newNode->next = temp; prevPtr->next = newNode; //link newNode between currPtr(temp) and prevPtr, wherever that may be
			if(temp == tail) 
				tail = newNode;
		}	
	}
}

void LinkedList::clear() {
	//DONE
    Node* temp = nullptr;
    while (head != nullptr) {
        temp = head->next;
        delete head;
        head = temp;
    }
    head = tail = nullptr; //avoid dangling pointers
}


string LinkedList::print() const { //DONE
	string outputString;
	stringstream os;

	Node* currPtr = head;
	while(currPtr != nullptr)
	{
		os << currPtr->data.id << " " << currPtr->data.year << " ";
		os << currPtr->data.month << " " << currPtr->data.temperature << endl;
		currPtr = currPtr->next;
	}

	outputString = os.str();
	return outputString;
}

void LinkedList::copyList(const LinkedList& ll)
{
	//create a deep copy 
	Node* currPtr = ll.head;
	while (currPtr != nullptr)
	{
		insert(currPtr->data.id,currPtr->data.year,currPtr->data.month,currPtr->data.temperature);
		currPtr = currPtr->next;
	}
}

double LinkedList::getAVG(string id, int startYear, int endYear) 
{
	double sum = 0.0;
	int c = 0;
	Node* currPtr = head;
	while (currPtr != nullptr) {
		if (currPtr->data.id == id && currPtr->data.year >= startYear && currPtr->data.year <= endYear)
		{	
			sum = currPtr->data.temperature + sum;
			++c;
		}

		currPtr = currPtr->next;
		}

	if (c == 0) return -1.0;

	else return (sum/c);
}


//can you believe I got mode mixed up with median at first... (ノಠ益ಠ)ノ彡┻━┻
//pay attention in class, kids. don't be like me
int LinkedList::getMode(string id, int startYear, int endYear) { 

	Node* currPtr = head;
	double mode = -1.0; 
	if (getSize(id,startYear,endYear) == 0) return -1; 

	//cout << countEqual(id,startYear,endYear) << endl;
	if (countEqual(id,startYear,endYear) == 0) //unique
	{
		double max = round(currPtr->data.temperature);
		while (currPtr != nullptr)
		{
			//cout << currPtr->data.temperature << endl;
			if (currPtr->data.id == id && currPtr->data.year >= startYear && currPtr->data.year <= endYear)
			{
				if (round(currPtr->data.temperature) > max)
				{
					max = round(currPtr->data.temperature);
				}
			}
			currPtr = currPtr->next;
		}
		mode = max;
	}

	else if (countEqual(id,startYear,endYear) == 1) //one instance of dupe
	{
		bool stop = false;
		while(currPtr != nullptr)
		{
			Node* nextPtr = currPtr->next;
			while (nextPtr != nullptr)
			{
				if (currPtr->data.id == id && currPtr->data.year >= startYear && currPtr->data.year <= endYear)
					if(round(currPtr->data.temperature) == round(nextPtr->data.temperature))
					{	
						mode = round(currPtr->data.temperature); 
						stop = true;
						break;
					}	

				nextPtr = nextPtr->next;
			}

			if (stop) break;
			currPtr = currPtr->next;
		}

	}

	else if (countEqual(id,startYear,endYear) > 1) {
		double A[121][121] {0}; //initialize a 2d array of size 121x121 with 0's
		int idx; //index
		Node* currPtr = head;
		while (currPtr != nullptr)
		{
			if (currPtr->data.id == id && currPtr->data.year >= startYear && currPtr->data.year <= endYear)
			{
					int data = round(currPtr->data.temperature);
					A[data][data] += 1;//store the number of times the data appears and the data
					//note: I was wanting to store the number of times the data appears along with the index in a way, but 
					//it would likely be more efficient if I just used a 1-d array. it does work

			}
			currPtr = currPtr->next;
		}

		idx = A[0][0];
		for (int i = 0; i < 121; ++i) //might be inefficient in terms of compile time?
		{
			for (int j = 0; j < 121; ++j)
			{
				if (idx <= A[i][j])
				{
					idx = A[i][j];
					mode = j;
				}
			}
		}
	}
	
	return static_cast<int>(mode);
}


int LinkedList::getSize(string id, int startYear, int endYear)
{
	int counter = 0;
	Node* currPtr = head;

	while (currPtr != nullptr)
	{
		if (currPtr->data.id == id && currPtr->data.year >= startYear && currPtr->data.year <= endYear)
				++counter;
		
		currPtr = currPtr->next;
	}

	return counter;
}


int LinkedList::countEqual(string id, int startYear, int endYear)
{

	Node* currPtr = head;
	int c = 0;
	while (currPtr != nullptr)
	{
		Node* nextPtr = currPtr->next;
		while(nextPtr != nullptr){
			if (currPtr->data.id == id && currPtr->data.year >= startYear && currPtr->data.year <= endYear) {
				if (round(currPtr->data.temperature) == round(nextPtr->data.temperature))
					++c;	
				
			}			
			nextPtr = nextPtr->next;	
		}
		currPtr = currPtr->next;
	}

	return c;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}