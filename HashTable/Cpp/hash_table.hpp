#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP
#include <iostream>
#include <utility>
#include <vector>

class HashTable {
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
    Node* hash_table[1000];
    int size = {0};
public:
    HashTable(void) {
        for (int i = 0; i < 1000; i++) {
            hash_table[i] = nullptr;
        }
    }

    int getSize(void);

    bool isEmpty(void);
    
    char get(int key);

    void put(int key, char value);

    char remove(int key);

    std::vector<std::pair<int, char> > entrySet(void);

    std::vector<int> keySet(void);

    std::vector<char> values(void);

    void printHashTable(void);
};

#endif