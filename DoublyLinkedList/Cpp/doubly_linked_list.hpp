#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP
#include <iostream>

class DoublyLinkedList {
private:
    class Node {
    private:
        int key;
        Node* next = {nullptr};
        Node* prev = {nullptr};
    public:
        Node(int k) : key(k) {}
        int getKey();
        Node* getNext();
        void setNext(Node* n);
        Node* getPrev();
        void setPrev(Node* p);
    };
    Node* head = {nullptr};
    Node* tail = {nullptr};
    int size = {0};
public:
    ~DoublyLinkedList(void);
    int getSize(void);
    //Return true if the list is empty
    bool isEmpty(void);
    //Return the key of the first node
    int first(void);
    //Return the key of the last node
    int last(void);
    //Search for key in the list. Return true if found.
    bool foundKey(int key);
    //Insert the key value at the front of the list
    void insertFirst(int key);
    //Insert the key value at the end of the list
    void insertLast(int key);
    //Insert the key value at a specific position in the list
    void insertAtPosition(int position, int key);
    //Remove the first key in the list, and return it
    int removeFirst(void);
    //Remove the last key in the list, and return it
    int removeLast(void);
    //Remove the key at a specific position in the list, and return it
    int removeAtPosition(int position);
    //Remove a specific key from the list
    void removeByKey(int key);
    DoublyLinkedList operator+(DoublyLinkedList &list) {
        DoublyLinkedList new_list;
        Node* current = this->head;
        //Iterate through the first list, adding each element to the new one
        while(current != nullptr) {
            new_list.insertLast(current->getKey());
            current = current->getNext();
        }
        current = list.head;
        //Iterate through the second list, adding each element to the new one
        while(current != nullptr) {
            new_list.insertLast(current->getKey());
            current = current->getNext();
        }
        //Return the new list
        return new_list;
    }
    void printLinkedListForward(void);
    void printLinkedListReverse(void);
};

#endif