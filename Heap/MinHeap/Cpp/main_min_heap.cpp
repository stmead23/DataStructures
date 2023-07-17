#include "min_heap.hpp"

int main(int argc, char* argv[]) {
    MinHeap heap;
    heap.printHeap();
    heap.insert(10, 'j');
    heap.printHeap();
    heap.insert(9, 'i');
    heap.printHeap();
    heap.insert(8, 'h');
    heap.printHeap();
    heap.insert(7, 'g');
    heap.printHeap();
    heap.insert(6, 'f');
    heap.printHeap();
    heap.insert(5, 'e');
    heap.printHeap();
    heap.insert(4, 'd');
    heap.printHeap();
    heap.insert(3, 'c');
    heap.printHeap();
    heap.insert(2, 'b');
    heap.printHeap();
    heap.insert(1, 'a');
    heap.printHeap();
    heap.removeMin();
    heap.printHeap();

    return 0;
}
