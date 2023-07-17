#include "priority_queue.hpp"
#include <__config>

int PriorityQueue::Node::getKey(void) { return key; }

void PriorityQueue::Node::setKey(int k) { key = k; }

char PriorityQueue::Node::getValue(void) { return value; }

void PriorityQueue::Node::setValue(char v) { value = v; }

void PriorityQueue::nodeSwitch(Node* a, Node* b) {
    int temp1 = a->getKey();
    char temp2 = a->getValue();
    a->setKey(b->getKey());
    a->setValue(b->getValue());
    b->setKey(temp1);
    b->setValue(temp2);
}

int PriorityQueue::getSize(void) { return size; }

bool PriorityQueue::isEmpty(void) { return size == 0; }

char PriorityQueue::min(void) {
    if (isEmpty()) {
        return '\0';
    }
    return p_queue[front]->getValue();
}

void PriorityQueue::insert(int key, char value) {
    if (size >= 10000) {
        std::cout << "Full. Can't add.\n";
        return;
    }
    int location = (front + size) % 10000;
    p_queue[location] = new Node(key, value);
    int i = location;
    size++;
    if(size == 1) {
        return;
    }
    do {
        if (p_queue[i-1]->getKey() <= p_queue[i]->getKey()) {
            break;
        }
        nodeSwitch(p_queue[i], p_queue[i-1]);
        i = (i-1) % 10000;
    } while (i != front);
}

char PriorityQueue::removeMin(void) {
    if(isEmpty()) {
        std::cout << "Empty. Ignored.\n";
        return '\0';
    }
    char value = min();
    delete p_queue[front];
    front = (front + 1) % 10000;
    size--;
    return value;
}

void PriorityQueue::printPriorityQueue(void) {
    if(isEmpty()) {
        std::cout << "Empty\n";
        return;
    }
    int i = front;
    int last = (front + size) % 10000;
    do {
        std::cout << p_queue[i]->getKey() << " ";
        i = (i + 1) % 10000;
    } while (i != last);
    std::cout << std::endl;
}