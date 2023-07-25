#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include <vector>
#include <algorithm>

class AVLTree {
private:
    class Node {
    private:
        int key;
        Node* left = {nullptr};
        Node* right = {nullptr};
    public:
        Node(int k) : key(k) {}
        
        int getKey(void);

        void setKey(int k);

        Node* getLeft(void);

        void setLeft(Node* l);

        Node* getRight(void);

        void setRight(Node* r);
    };
    Node* root = {nullptr};

    int getDepth(Node* current);

    int getBalance(Node* current);

    Node* leftRotate(Node* last_root);

    Node* rightRotate(Node* last_root);

    Node* rebalance(Node* current);

    void swapNodes(Node* last_root, Node* new_root);

    Node* insert(Node* current, int key);

    Node* deleteNode(Node* current, int key);

    void printInOrder(Node* current);

    void printLevelOrder(Node* current);
public:
    void insert(int key);

    void deleteNode(int key);

    void printTree(void);    
};

#endif