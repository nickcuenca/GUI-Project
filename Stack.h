//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_STACK_H
#define PROJECT_STACK_H
#include "LinkedList.h"

template <class T>

class Stack {
private:
    LinkedList<T> list;
public:
    Stack(); //Initializes the object to an empty stack.
//    Stack(const Stack &aStack); //Copy constructor.
//    ~Stack(); //Destroys the s

    void pop(); //removes an item form the stack
    void push(T item); //adds an item to the stack
//    Stack& operator=(const Stack& list);
    bool empty(); //returns true if there are no items in the stack
    int size(); //returns the number of items in the stack
    T top(); //returns the item on the top of the stack, without removing it
    T seek(int index); //
};

#include "Stack.cpp"
#endif //PROJECT_STACK_H
