#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

class Stack {
    private:
        Node* top;
        
    public:
        Stack() : top(nullptr) {}

        // Push an element onto the stack
        void push(int value);

        // Pop the top element from the stack
        void pop();

        // Get the value of the top element without removing it
        int peek();

        // Check if the stack is empty
        bool isEmpty();

        // Display the stack elements
        void display();

        // Destructor to free memory
        ~Stack();
};

#endif // STACK_H
