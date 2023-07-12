#include "SinglyLinkedList.hpp"

int main(int argc, char * argv[]) {
    SinglyLinkedList list;
    if(list.isEmpty()) {
        std::cout << "Empty.\n";
    }
    list.insertLast(5);
    list.printLinkedList();
    list.insertFirst(4);
    list.printLinkedList();
    list.insertFirst(3);
    list.printLinkedList();
    list.insertFirst(2);
    list.printLinkedList();
    list.insertFirst(1);
    list.printLinkedList();
    list.insertLast(6);
    list.printLinkedList();
    std::cout << "First element: " << list.first() << std::endl;
    std::cout << "Last element: " << list.last() << std::endl;
    return 0;
}