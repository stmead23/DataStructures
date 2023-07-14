#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP
#include <iostream>
//Create a singly linked list that stores a key and a pointer to the next value

class SinglyLinkedList {
private:
    class Node {
    private:
        int key;
        Node* next;
    public:
        //Set the key when a new node is created, and set next to nullptr
        Node(int k) : key(k), next(nullptr) {} 
        //Return the key
        int getKey(void);
        //Return the next value. Used for iterating the list
        Node* getNext(void);
        //Set the next value. Used when inserting or deleting a node
        void setNext(Node* n);
    };
    //Uses a head for the beginning of the list, and a tail for constant insertion and access
    Node* head;
    Node* tail;
    //Keep track of the size to have constant time size checking
    int size;
public:
    //Initialize the empty list
    SinglyLinkedList(void) : head(nullptr), tail(nullptr), size(0) {}
    //Delete the entire list
    ~SinglyLinkedList(void);
    //Return the current size of the list
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
    //Combine two lists into a new third list
    SinglyLinkedList operator+(SinglyLinkedList &list) {
        SinglyLinkedList new_list;
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
    //Print the list
    void printLinkedList(void);
};

#endif
