#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP
#include <iostream>

class MaxHeap {
private:
    class Node {
    private:
        int key;
        char value;
    public:
        Node(int k, char v) : key(k), value(v) {};
        
        int getKey(void);

        void setKey(int k);

        char getValue(void);

        void setValue(char v);
    };
    int size = {0};
    Node* heap[10000];
    void swap(int a, int b);
public:
    int getSize(void);

    bool isEmpty(void);

    char max(void);

    void insert(int key, char value);

    char removeMax(void);

    void printHeap(void);
};

#endif