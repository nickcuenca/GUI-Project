//
// Created by Nicolas Cuenca on 4/5/2021.
//
#ifndef PROJECT_STACK_CPP
#define PROJECT_STACK_CPP
#include "Stack.h"

template <class T>
void Stack<T>::push(T item) {
    list.insertFront(item);
}

template <class T>
void Stack<T>::pop() {
    list.removeHead();
}

template <class T>
T Stack<T>::top() {
    return list.getHead();
}

////finish this one
//template<class T>
//Stack<T> &Stack<T>::operator=(const Stack<T> &list) {
//
//}

template <class T>
bool Stack<T>::empty() {
    return list.getHead() == NULL;
}

template<class T>
int Stack<T>::size() {
    list.checkSize();
}

template<class T>
Stack<T>::Stack() {
    list = LinkedList<T> ();
}

//template<class T>
//Stack<T>::Stack(const Stack &aStack) : Stack() {
//
//}


//check if this is right
//template<class T>
//Stack<T>::~Stack() {
//    while (list.getFront() != nullptr)
//    {
//        pop();
//    }
//}

//template<class T>
//T Stack<T>::seek(int index) {
//    int count = 0;
//    Node<T> *walker = list.getHead();
//
//    while (walker != nullptr && count != index)
//    {
//        count++;
//        walker = walker->next;
//    }
//    if (count == index){
//        return walker->data;
//    }
//
//    return list.getHead()->data;
//}



#include "Stack.cpp"
#endif