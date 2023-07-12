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

void SinglyLinkedList::insertLast(int key) {
    Node* new_node = new Node(key);
    if(tail == nullptr) {
        tail = new_node;
        head = new_node;
    } else {
        tail->setNext(new_node);
        tail = new_node;
    }
    size++;
}

void SinglyLinkedList::insertAtPosition(int position, int key) {
    if(isEmpty() || position == 0) {
        insertFirst(key);
        return;
    } else if(position >= size) {
        insertLast(key);
        return;
    }
    Node* new_node = new Node(key);
    Node* current = head;
    for(int i = 0; i < position-1; i++) {
        current = current->getNext();
    }
    new_node->setNext(current->getNext());
    current->setNext(new_node);
    size++;
}

void SinglyLinkedList::printLinkedList(void) {
    if(isEmpty()) {
        std::cout << "Empty.\n";
        return;
    }
    Node* current = head;
    while(current != nullptr) {
        std::cout << current->getKey();
        if(current->getNext() != nullptr) {
            std::cout << " -> ";
        }
        current = current->getNext();
    }
    std::cout << std::endl;
}