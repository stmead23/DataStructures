#include <iostream>
#include "queue.hpp"
#include "queue.hpp"

int main(int argc, char* argv[]) {
    Queue queue(10);
    if (queue.isEmpty()) {
        std::cout << "Empty.\n";
    }
    for (int i = 0; i <= 10; i++) {
        queue.enqueue(i);
        queue.printQueue();
    }
    if (queue.isFull()) {
        std::cout << "Full.\n";
    }
    std::cout << "Size: " << queue.getSize() << std::endl;
    for (int i = 0; i <= 10; i++) {
        std::cout << "Removing " << queue.dequeue() << std::endl;
    }
    queue.enqueue(5);
    queue.dequeue();
    queue.enqueue(2);
    queue.printQueue();
    return 0;
}
