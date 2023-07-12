#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP
#include <iostream>

class SinglyLinkedList {
private:
    class Node {
    private:
        int key;
        Node* next;
    public:
        Node(int k) : key(k), next(nullptr) {}

        int getKey(void);

        Node* getNext(void);

        void setNext(Node* n);
    };
    Node* head;
    Node* tail;
    int size;
public:
    SinglyLinkedList(void) : head(nullptr), tail(nullptr), size(0) {}

    //~SinglyLinkedList(void);

    int getSize(void);

    bool isEmpty(void);

    int first(void);

    int last(void);

    bool foundKey(int key);

    void insertFirst(int key);

    void insertLast(int key);

    void insertAtPosition(int position, int key);

    int removeFirst(void);

    /*int removeLast(void);

    int removeAtPosition(int position);*/

    void printLinkedList(void);
};

#endif