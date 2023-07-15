#include "queue.hpp"
#include <iostream>

int Queue::getSize(void) { return current_size; }

bool Queue::isEmpty(void) { return current_size == 0; }

bool Queue::isFull(void) { return current_size == max_size; }

int Queue::top(void) {
    if (isEmpty()) {
        return 0;
    }
    return queue[front];
}

void Queue::enqueue(int key) {
    if (isFull()) {
        std::cout << "Full. Ignored.\n";
        return;
    }
    int location = (front + current_size) % max_size;
    queue[location] = key;
    current_size++;
}

int Queue::dequeue(void) {
    if (isEmpty()) {
        std::cout << "Empty. Ignored.\n";
        return 0;
    }
    int key = queue[front];
    queue[front] = 0;
    front = (front + 1) % max_size;
    current_size--;
    return key;
}

void Queue::printQueue(void) {
    if(isEmpty()) {
        std::cout << "Empty.\n";
        return;
    }
    int i = front;
    int back = (front + current_size) % max_size;
    do {
        std::cout << queue[i] << " ";
        i = (i + 1) % max_size;
    } while (i != back);
    std::cout << std::endl;
}
