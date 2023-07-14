#include<iostream>
#include "stack.hpp"

int main(int argc, char* argv[]) {
    Stack stack(10);
    if (stack.isEmpty()) {
        std::cout << "Empty.\n";
    }
    for (int i = 0; i <= 10; i++) {
        stack.push(i);
        stack.printStack();
    }
    if (stack.isFull()) {
        std::cout << "Full.\n";
    }
    std::cout << "Size: " << stack.getSize() << std::endl;
    for (int i = 0; i <= 10; i++) {
        std::cout << "Removing " << stack.pop() << std::endl;
    }
    return 0;
}