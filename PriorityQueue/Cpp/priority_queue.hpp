#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP
#include <iostream>

class PriorityQueue {
private:
    class Node {
    private:
        int key;
        char value;
    public:
        Node(int k, char v) : key(k), value(v) {}
        
        int getKey(void);

        void setKey(int k);
        
        char getValue(void);

        void setValue(char v);
    };
    Node* p_queue[10000];
    int front = {0};
    int size = {0};
    void nodeSwitch(Node* a, Node* b);
public:
    PriorityQueue(void) {
        for(int i = 0; i < 10000; i++) {
            p_queue[i] = nullptr;
        }
    } 

    int getSize(void);

    bool isEmpty(void);

    char min(void);

    void insert(int key, char value);

    char removeMin(void);

    void printPriorityQueue(void);
};

#endif