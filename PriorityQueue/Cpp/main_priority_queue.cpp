#include "priority_queue.hpp"

int main(int argc, char* argv[]) {
    PriorityQueue p_queue;
    p_queue.insert(5, 'a');
    p_queue.printPriorityQueue();
    p_queue.insert(11, 'b');
    p_queue.printPriorityQueue();
    p_queue.insert(7, 'c');
    p_queue.printPriorityQueue();
    p_queue.insert(2, 'd');
    p_queue.printPriorityQueue();
    p_queue.removeMin();
    p_queue.printPriorityQueue();
}
