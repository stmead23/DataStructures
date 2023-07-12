#include "SinglyLinkedList.hpp"

int SinglyLinkedList::Node::getKey() { return key; }

SinglyLinkedList::Node* SinglyLinkedList::Node::getNext(void) { return next; }

void SinglyLinkedList::Node::setNext(SinglyLinkedList::Node* n) { next = n; }

int SinglyLinkedList::getSize(void) { return size; }

bool SinglyLinkedList::isEmpty(void) { return size == 0; }

int SinglyLinkedList::first(void) {
    if(isEmpty()) {
        return 0;
    }
    return head->getKey();
}

int SinglyLinkedList::last(void) {
    if(isEmpty()) {
        return 0;
    }
    return tail->getKey();
}

bool SinglyLinkedList::foundKey(int key) {
    Node* current = head;
    while(current != nullptr) {
        if(current->getKey() == key) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

void SinglyLinkedList::insertFirst(int key) {
    Node* new_node = new Node(key);
    if(head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->setNext(head);
        head = new_node;
    }
    size++;
}