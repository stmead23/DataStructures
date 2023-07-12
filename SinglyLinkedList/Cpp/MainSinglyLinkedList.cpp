#include "SinglyLinkedList.hpp"

int main(int argc, char * argv[]) {
    SinglyLinkedList list;
    if(list.isEmpty()) {
        std::cout << "Empty.\n";
    }
    list.insertFirst(5);
    list.insertFirst(4);
    list.insertFirst(3);
    list.insertFirst(2);
    list.insertFirst(1);
    std::cout << "First element: " << list.first() << std::endl;
    std::cout << "Last element: " << list.last() << std::endl;
    std::cout << "Is 3 in the list? ";
    if(list.foundKey(3)) {
        std::cout << "Yes!\n";
    } else {
        std::cout << "No!\n";
    }
    return 0;
}