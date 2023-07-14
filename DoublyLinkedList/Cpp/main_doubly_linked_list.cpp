#include "doubly_linked_list.hpp"

int main(int argc, char* argv[]) {
    DoublyLinkedList list1;
    if (list1.isEmpty()) {
        std::cout << "Empty.\n";
    }

    list1.insertFirst(1);
    list1.printLinkedListForward();

    list1.insertLast(5);
    list1.printLinkedListForward();

    list1.insertAtPosition(1,2);
    list1.printLinkedListForward();

    list1.insertAtPosition(2,3);
    list1.printLinkedListForward();

    list1.insertAtPosition(3,4);
    list1.printLinkedListForward();
    list1.printLinkedListReverse();

    std::cout << "Size: " << list1.getSize() << std::endl;
    std::cout << "First:" << list1.first() << std::endl;
    std::cout << "Last:" << list1.last() << std::endl;

    std::cout << "Element removed: " << list1.removeFirst() << std::endl;
    std::cout << "Element removed: " << list1.removeLast() << std::endl;
    std::cout << "Element removed: " << list1.removeAtPosition(1) << std::endl;

    DoublyLinkedList list2;
    for (int i = 6; i < 11; i++) {
        list2.insertLast(i);
    }
    list2.removeByKey(7);
    list2.removeByKey(25);

    list1.insertAtPosition(1,3);
    list1.insertFirst(1);
    list1.insertLast(5);
    list2.insertAtPosition(1,7);

    std::cout << "List 1: ";
    list1.printLinkedListForward();
    std::cout << "List 2: ";
    list2.printLinkedListForward();
    DoublyLinkedList list3 = list1 + list2;
    std::cout << "List 3: ";
    list3.printLinkedListForward();
    
    return 0;
}
