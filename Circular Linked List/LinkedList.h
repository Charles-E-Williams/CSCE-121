#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
#include <sstream>
#include <vector>
using std::endl;
using std::cout;
using std::runtime_error;


template <class T>
class LinkedList {


    public:
        LinkedList();
        ~LinkedList();
        void clear();
        void insertValue(const T& val);
        bool isempty();
        Node<T>* getHead() const{return head;}
        Node<T>* getTail() const{return tail;}
        void pop(const unsigned int&);
        unsigned size() {return sz;}

    private:
        Node<T>* head;
        Node<T>* tail;
        unsigned sz;

};
 
template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), sz(0){}

template <class T>
LinkedList<T>::~LinkedList() { this->clear();}

template <class T>
void LinkedList<T>::clear() {

    if (head) {
        Node<T>* curr = tail;

        while (curr != head) {
            curr->next = head->next;
            delete head;
            head = curr->next;
        }

        if (curr == head) 
            delete head;
        
        head = tail = nullptr;
        this->sz = 0;

    }
}

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll)
{



    if (ll.getHead() != nullptr && ll.getTail() != nullptr) {
  
        Node<T>* currPtr = ll.getHead();
        os << "(" << currPtr->val << ") -> ";
        currPtr = currPtr->next;
        while (currPtr != ll.getHead())
        {
            os << "(" << currPtr->val << ") -> ";
            currPtr = currPtr->next;
        } os << "[back to head] : (" << ll.getHead()->val << ") " << endl;
    }

    else os << "<Empty>" << endl;

    return os;
}


template <class T>
bool LinkedList<T>::isempty() {return head == nullptr && tail == nullptr;}


template <class T>
void LinkedList<T>::insertValue(const T& val) {

    if (isempty()) {
        head = tail = new Node<T>(val);
        tail->next = head;
        sz++;
        return;
    }

    else
    {
        Node<T>* newNode = new Node<T>(val);
        if (newNode->val < head->val){ //insert at front
            newNode->next = head;
            head = newNode;
            tail->next = head;
            sz++;     
            return;
        }

        else
        {
            Node<T>*curr = head->next;
            Node<T>*prev = head;
            while (curr != head) {
                if (newNode->val < curr->val)
                {
                    prev->next = newNode;
                    newNode->next = curr;
                    sz++;
                    return;
                }
                
                prev = curr;
                curr = curr->next;
            }

            if (prev == tail) { //insert at end
                prev->next = newNode;
                tail = newNode;
                tail->next = head;
                sz++;
                return;
            }
        }   
    }
}

template <class T>
void LinkedList<T>::pop(const unsigned int& index)
{
    if (isempty()) return;

    else if (index >= sz) throw runtime_error("Invalid Size");

    if (sz == 1)
    {
        delete head;
        head = tail = nullptr;
        sz--;
    }

    else if (index == 0 && sz > 1)
    {
        Node<T>* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;     
        sz--;
        return;
    }

    else if (index == sz - 1)
    {
        Node<T>* curr = head;
        Node<T>* prev = head;
        while(curr->next != head)
        {
            prev = curr;
            curr = curr->next;
        }

        delete curr;
        prev->next = head;
        tail = prev;
        sz--;
        return;
    }

    else
    {
        Node<T>* curr = head->next;
        Node<T>* prev = head;
        unsigned int j = 0;
        while (curr != head)
        {
            if (j == index - 1) break;

            else {
                prev = curr;
                curr = curr->next;
                j++;
            }
        }

        prev->next = curr->next;
        delete curr;
        sz--;
        return;
    }
    

  


}



#endif