#include "max_heap.hpp"

int MaxHeap::Node::getKey(void) { return key; }

void MaxHeap::Node::setKey(int k) { key = k; }

char MaxHeap::Node::getValue(void) { return value; }

void MaxHeap::Node::setValue(char v) { value = v; }

void MaxHeap::swap(int a, int b) {
    int temp1 = heap[a]->getKey();
    char temp2 = heap[a]->getValue();
    heap[a]->setKey(heap[b]->getKey());
    heap[a]->setValue(heap[b]->getValue());
    heap[b]->setKey(temp1);
    heap[b]->setValue(temp2);
}

int MaxHeap::getSize(void) { return size; }

bool MaxHeap::isEmpty(void) { return size == 0; }

char MaxHeap::max(void) {
    if (isEmpty()) {
        return '\0';
    }
    return heap[0]->getValue();
}

void MaxHeap::insert(int key, char value) {
    if (isEmpty()) {
        heap[0] = new Node(key, value);
        size++;
        return;
    } else if (size == 10000) {
        std::cout << "Full. Ignored.\n";
        return;
    }
    heap[size] = new Node(key, value);
    bool upheap = true;
    int i = size;
    while (upheap) {
        int parent = (i-1) / 2;
        if ((heap[i]->getKey() <= heap[parent]->getKey()) || (i == 0)) {
            upheap = false;
        } else {
            swap(i, parent);
            i = parent;
        }
    }
    size++;
}

char MaxHeap::removeMax(void) {
    if (isEmpty()) {
        std::cout << "Empty. Ignored.\n";
        return '\0';
    }
    
    char return_value = heap[0]->getValue();
    swap(0, size-1);
    delete heap[size-1];
    size--;

    int i = 0;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    while (left < size) {
        int biggest = left;
        if (right < size) {
            if (heap[left]->getKey() < heap[right]->getKey()) {
                biggest = right;
            }
        }
        if (heap[biggest]->getKey() < heap[i]->getKey()) {
            break;
        }
        swap(i, biggest);
        i = biggest;
        left = i * 2 + 1;
        right = i * 2 + 2;
    }
    return return_value;
}

void MaxHeap::printHeap(void) {
    if (isEmpty()) {
        std::cout << "Empty.\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << "(" << heap[i]->getKey() << ", " << heap[i]->getValue() << ") ";
    }
    std::cout << std::endl;
}