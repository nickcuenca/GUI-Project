//
// Created by Nicolas Cuenca on 4/5/2021.
//
#ifndef PROJECT_LINKEDLIST_CPP
#define PROJECT_LINKEDLIST_CPP
#include <iostream>
#include "LinkedList.h"
template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    Node<T>* walker = list.head;
    head = createNode(list.head->data);
    Node<T>* tempPtr = head;
    walker = walker->next;
    Node<T>* newNode;
    while (walker != nullptr)
    {
        newNode = createNode(walker->data);
        newNode->prev = tempPtr;
        tempPtr->next = newNode;
        walker = walker->next;
        tempPtr = newNode;
    }
}
template <class T>
LinkedList<T>::~LinkedList() {
//    std::cout << "Clearing list!\n";
    clearList();
}

template <class T>
std::ostream &operator<<(std::ostream &out, const LinkedList<T>& list) {
    Node<T>* walker = list.head;
    std::cout << "Now displaying the full list:\n";
    while (walker != nullptr){
        out << walker->data;
        out.width(5); //can take out if needed
        walker = walker->next;
    }
    std::cout << std::endl;
    return out;
}

template <class T>
Node<T> *LinkedList<T>::createNode(T item) {
    Node<T>* temp = new Node<T>;
    temp->data = item;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

template <class T>
void LinkedList<T>::insertTail(T item) {
    Node<T>* temp = createNode(item); //creates a temp node with the data provided by user
    if (head == nullptr) //case where there is no nodes yet
    {
        head = temp;
        tail = temp;
    } else
    {
        //step 3
        temp->next = head;
        //step 4
        head->prev = temp;
        //step 5
        head = temp;
    }
}

template <class T>
void LinkedList<T>::insertFront(T item) {
    Node<T>* temp = createNode(item);
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    } else{
        temp->next = head;
        temp->prev = temp;
        head = temp;
    }
}


template <class T>
Node<T> *LinkedList<T>::search(T item) {
    Node<T>* walker = head;
    while (walker != nullptr && walker->data != item){
        walker = walker->next;
    }
    return walker;
}

template <class T>
void LinkedList<T>::remove(T item) {
    Node<T>* temp = search(item);
    if (temp != nullptr)
        remove(temp);
}

template <class T>
void LinkedList<T>::remove(Node<T> *node) {
    if (node == nullptr)
        return;
    //if the list is empty
    if (head == nullptr)
        return;

    if (head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    } else if (node == head) //case where there is only one node. deletes the one node
    {
        Node<T>* temp = new Node<T>;
        temp = head;
        head = head->next;
        delete temp;
        head->prev = nullptr;
    } else if (node == tail) //case where the node is equal to the tail. sets tail to become tail-> prev.
    {
        Node<T>* temp = new Node<T>;
        temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    } else //case where the node is not in the tail or the head, in between somewhere.
    {

        Node<T>* tempPrevious = new Node<T>;
        Node<T>* tempNext =  new Node<T>;
        tempPrevious = node->prev;
        tempNext = node->next;
        node->next = nullptr;
        node->prev = nullptr;
//        std::cout << "MONKEY DEBUGGER: ORANGUTAN CODE 1" << std::endl;
        tempPrevious->next = tempNext;
        tempNext->prev = tempPrevious;
        delete node;
    }
}

template <class T>
void LinkedList<T>::insertBefore(T thisValue, T thatValue) {
    Node<T>* temp = new Node<T>;
    temp = search(thatValue);
    if (temp != nullptr)
        insertBefore(thisValue, temp);
}

template <class T>
void LinkedList<T>::insertBefore(T thisValue, Node<T> *thatNode) {
    Node<T>* temp = createNode(thisValue);
    if (thatNode == head) //case where the node we want to insert before is the head.
    {
        temp->next = thatNode;
        thatNode->prev = temp;
        head = temp;
    } else //case where the node we want to insert is anywhere but the head.
    {
        Node<T>* walker = head;
        while (walker->next != nullptr ){
            if (walker->next == thatNode)
            {
                walker->next = temp;
                temp->prev = walker;
                temp-> next = thatNode;
                thatNode->prev = temp;
                break;
            }
            walker = walker->next;
        }
    }
}

template <class T>
void LinkedList<T>::insertAfter(T thisValue, T thatValue) {
    Node<T>* temp = new Node<T>;
    temp = head;

    if (temp == nullptr) // list is empty
    {
        head = createNode(thisValue);
        return;
    } else{
        Node<T>* walker = head;
        while (walker != nullptr)
        {

            if (walker->data == thatValue){
                Node<T>* newNode = createNode(thisValue);
                if (walker->next == nullptr)// case where walker is at the last node of the list
                {
                    walker->next->prev = newNode;
                }
                walker->next = newNode;
                newNode->prev = walker;
                break;
            }
            walker = walker->next;
        }
    }
}

template <class T>
void LinkedList<T>::operator+=(T item) {
    insertTail(item);
}

template <class T>
int LinkedList<T>::checkSize() {
    Node<T>* walker = head;
    int counter = 0;
    while (walker != nullptr){
        walker = walker->next;
        counter++;
    }
    return counter;
}

template <class T>
void LinkedList<T>::clearList() {
    Node<T>* walker = head;
    Node<T>* tempPtr;
    while (walker != nullptr)
    {

        tempPtr = walker->next;
        if (tempPtr != nullptr)
            tempPtr->prev = nullptr;
        walker->next = nullptr;
        delete walker;
        walker = tempPtr;
    }
    head = nullptr;
}

template <class T>
bool LinkedList<T>::checkIfEmpty() {
    return head == nullptr;
}

template <class T>
bool LinkedList<T>::findItem(T item) {
    Node<T>* walker = head;
    Node<T>* tempPtr;
    while (walker != nullptr) {
        if (walker->data == item)
            return true;
        walker = walker->next;
    }
    return false;
}

template <class T>
T LinkedList<T>::getHead() {
    if (head != nullptr)
        return head->data;
    return NULL;
}

template <class T>
void LinkedList<T>::removeHead() {
   head = head->next;
}

#include "LinkedList.cpp"
#endif