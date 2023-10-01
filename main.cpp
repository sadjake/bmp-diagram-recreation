#include "LinkedList.h"
#include "Stack.h"
#include <iostream>

int main() {
    // Test LinkedList class
    LinkedList list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertFront(5);
    list.printList();
    list.removeBack();
    list.removeFront();
    list.printList();

    // Test Stack class
    Stack stack;
    stack.push(15);
    stack.push(30);
    stack.push(45);
    stack.display();
    stack.pop();
    std::cout << "Top element: " << stack.peek() << std::endl;
    stack.display();

    return 0;
}
