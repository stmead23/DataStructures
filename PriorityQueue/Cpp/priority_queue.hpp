#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP
#include <iostream>

class PriorityQueue {
private:
    class Node {
    private:
        int key;
        char value;
        Node* next = {nullptr};
    public:
        Node(int k, char v) : key(k), value(v) {}
        
        int getKey(void);
        
        char getValue(void);
        
        Node* getNext(void);
        
        void setNext(Node* n);
    };
    Node* head = {nullptr};
    int size = {0};
public:
    int getSize(void);

    bool isEmpty(void);

    char min(void);

    void insert(int key, char value);

    char removeMin(void);

    void printPriorityQueue(void);
};

#endif