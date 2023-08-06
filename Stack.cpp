#include "Stack.h"
#include <iostream>

Stack::Stack():top(nullptr) {}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    // Checking if the stack is empty with isEmpty
    if (isEmpty()) {
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
}

int Stack::peek() {
    // Checking if the stack isn't empty with !isEmpty
    if (isEmpty()) {
        return -1;
    }

    return top->data; 
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::display() {
    Node* current = top;
    // Traverse through the linked list using current
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Stack::~Stack() {
    Node* current = top;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

