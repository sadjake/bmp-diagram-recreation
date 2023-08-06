#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() 
{
    Node* current = head;
    while (current != nullptr) 
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// 
void LinkedList::insertFront(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

//
void LinkedList::insertBack(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } 

    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
//
void LinkedList::removeFront() {
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

//
void LinkedList::removeBack() {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
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
    if (head == nullptr) {
        return true;
    }
    
    return false;
}

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
