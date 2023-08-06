// #ifndef LINKEDLIST_H
// #define LINKEDLIST_H

typedef struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
}; Node;

class LinkedList {
    private:
        Node* head;
        
    public:
        LinkedList();
        ~LinkedList();

        void insertFront(int val);
        void insertBack(int val);
        void removeFront();
        void removeBack();
        bool isEmpty() const;
        void printList() const;
        int length() const;
};

//#endif // LINKEDLIST_H
