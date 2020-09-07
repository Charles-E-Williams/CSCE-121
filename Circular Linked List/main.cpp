#include <iostream>
#include "LinkedList.h"

using std::cout; using std::endl;

int main()
{

    LinkedList<int> ll;
    ll.insertValue(3);
    ll.pop(0);
    cout << ll;
    ll.insertValue(2);
    cout << ll;
    ll.insertValue(0);
    ll.insertValue(-3);
    ll.insertValue(1);
    ll.insertValue(4);
    ll.insertValue(-2);
    ll.insertValue(-1);
    ll.insertValue(5);
    ll.insertValue(6);
    ll.insertValue(3);
    ll.insertValue(2);
    ll.insertValue(-10);
    cout << ll;

    ll.pop(0);
    ll.pop(10);
    ll.pop(0);
    ll.pop(3);
    ll.pop(4);
    ll.pop(4);
    ll.insertValue(1);
    ll.insertValue(3);
    ll.pop(0); ll.pop(0); 



    cout << ll;
}