#include "stack.hpp"
#include <iostream>
#include <stdlib.h>

int Stack::getSize(void) { return current_size; }

bool Stack::isEmpty(void) { return current_size == 0; }

bool Stack::isFull(void) { return current_size == max_size; }

int Stack::top(void) {
    if (isEmpty()) {
        return 0;
    }
    return stack[current_size-1];
}

void Stack::push(int key) {
    if (isFull()) {
        std::cout << "Full. Ignored.\n";
        return;
    }
    stack[current_size++] = key;
}

int Stack::pop(void) {
    if (isEmpty()) {
        std::cout << "Empty. Ignored.\n";
        return 0;
    }
    int key = top();
    stack[current_size-1] = 0;
    current_size--;
    return key;
}

void Stack::printStack(void) {
    if (isEmpty()) {
        std::cout << "Empty.\n";
        return;
    }
    for(int i = 0; i < current_size; i++) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}