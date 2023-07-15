#include "priority_queue.hpp"
#include <__config>

int PriorityQueue::Node::getKey(void) { return key; }

char PriorityQueue::Node::getValue(void) { return value; }
        
PriorityQueue::Node* PriorityQueue::Node::getNext(void) { return next; }

void PriorityQueue::Node::setNext(PriorityQueue::Node* n) { next = n; }

int PriorityQueue::getSize(void) { return size; }

bool PriorityQueue::isEmpty(void) { return size == 0; }

char PriorityQueue::min(void) {
    if (isEmpty()) {
        return '\0';
    }
    return head->getValue();
}

void PriorityQueue::insert(int key, char value) {
    Node* new_node = new Node(key, value);
    size++;
    if (head == nullptr) {
        head = new_node;
        return;
    }
    if (key < head->getKey()) {
        new_node->setNext(head);
        head = new_node;
        return;
    }
    
    Node* current = head;
    while (current->getNext() != nullptr) {
        if (key < current->getNext()->getKey()) {
            break;
        }
        current = current->getNext();
    }
    if (current->getNext() != nullptr) {
        new_node->setNext(current->getNext());
    }
    current->setNext(new_node);
}

char PriorityQueue::removeMin(void) {
    if(isEmpty()) {
        std::cout << "Empty. Ignored.\n";
        return '\0';
    }
    char value = min();
    Node* temp = head;
    head = head->getNext();
    delete temp;
    return value;
}

void PriorityQueue::printPriorityQueue(void) {
    if(isEmpty()) {
        std::cout << "Empty\n";
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        std::cout << "(" << current->getKey() << ", " << current->getValue() << ")";
        if (current->getNext() != nullptr) {
            std::cout << " -> ";
        }
        current = current->getNext();
    }
    std::cout << std::endl;
}