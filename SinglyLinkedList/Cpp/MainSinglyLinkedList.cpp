#include "SinglyLinkedList.hpp"

int main(int argc, char * argv[]) {
    SinglyLinkedList list;
    if(list.isEmpty()) {
        std::cout << "Empty.\n";
    }
    list.insertFirst(5);
    list.printLinkedList();
    
    list.insertFirst(3);
    list.printLinkedList();
    
    list.insertFirst(1);
    list.printLinkedList();

    list.insertAtPosition(0, 0);
    list.printLinkedList();

    list.insertAtPosition(2, 2);
    list.printLinkedList();

    list.insertAtPosition(4, 4);
    list.printLinkedList();

    list.insertAtPosition(6, 6);
    list.printLinkedList();

    std::cout << "First element: " << list.first() << std::endl;
    std::cout << "Last element: " << list.last() << std::endl;

    std::cout << "Removed key: " << list.removeLast() << std::endl;
    std::cout << "Removed key: " << list.removeAtPosition(2) << std::endl;
    list.printLinkedList();
    list.removeByKey(3);
    list.printLinkedList();
    list.removeByKey(10);
    list.printLinkedList();
    std::cout << "Removed key: " << list.removeLast() << std::endl;
    std::cout << "Removed key: " << list.removeLast() << std::endl;
    std::cout << "Removed key: " << list.removeLast() << std::endl;
    std::cout << "Removed key: " << list.removeLast() << std::endl;
    std::cout << "Removed key: " << list.removeLast() << std::endl;

    return 0;
}