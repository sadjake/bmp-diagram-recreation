#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

//
LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// insert a new node at the front of the list
void LinkedList::insertFront(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// insert a new node at the back of the list
void LinkedList::insertBack(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } 

    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// remove the front node from the list
void LinkedList::removeFront() {
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

//remove the last node from the list
void LinkedList::removeBack() {
    if (!head) {
        return;
    }

    if (!(head->next)) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

bool LinkedList::isEmpty() const 
{
    if (head == nullptr)
    {
        return true;
    }
    return false;
}

//print
void LinkedList::printList() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


int LinkedList::length() const {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// aug g