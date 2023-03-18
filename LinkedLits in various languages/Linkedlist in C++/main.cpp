#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList list;

    // add some nodes
    list.addFirst(10);
    list.addEnd(20);
    list.addRandom(15);

    // print the list
    list.print(); // should print: 10 15 20

    // delete a node
    list.deleteRandom(15);

    // print the list again
    list.print(); // should print: 10 20

    // peek at the first element
    cout << "First element: " << list.peek() << endl; // should print: First element: 10

    // delete the first and last elements
    list.deleteFirst();
    list.deleteEnd();

    // print the list again
    list.print(); // should print: empty list message
}
