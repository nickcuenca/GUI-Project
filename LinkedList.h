//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H
#include "Node.h"
#include <ostream>
template <class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

    Node<T>* createNode(T item); //creates a node, user does not use this function
    void remove(Node<T>* node); //removes a node from the list of nodes
    Node<T>* search(T item); //finds the value in the list. for example search(1) will find the node where the 1 is located at;
    void insertBefore(T thisValue, Node<T>* thatNode);
public:
    LinkedList(); //constructor ready for the default linked list;
    LinkedList(const LinkedList& list); //copy constructor neeeded to finish
    ~LinkedList(); //destructor needed to finish

    void insertTail(T item); //inserts a value at the tail of the list
    void insertFront(T item); //inserts a value in the front of the list
    void remove(T item); //removes the first value of that occurrence from the list
    void insertBefore(T thisValue, T thatValue); // allows a value to be added before another value in the list
    void insertAfter(T thisValue, T thatValue); // allows a value to be added before another value in the list
    void operator +=(T item); //operator function overloads the += operator (can now do list1.operator+=(int number);
    int checkSize(); //function returns the size of how many nodes/nodes that contain data are in the list
    void clearList(); //function clears the list, gets rid of every node and data inside the nodes.
    bool checkIfEmpty(); //checks if list is empty or not
    bool findItem(T item); //function returns true if a value was found in the linked list
    void removeHead();
    T getHead();


    template<class S>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list); //can now cout the list

};

#include "LinkedList.cpp"
#endif //PROJECT_LINKEDLIST_H
