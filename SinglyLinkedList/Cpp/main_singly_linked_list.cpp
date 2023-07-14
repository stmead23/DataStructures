#include "SinglyLinkedList.hpp"

int main(int argc, char * argv[]) {
    SinglyLinkedList list1;
    SinglyLinkedList list2;
    for(int i = 0; i < 6; i++) {
        list1.insertLast(i);
    }
    for(int i = 6; i < 11; i++) {
        list2.insertLast(i);
    }
    std::cout << "List1: ";
    list1.printLinkedList();
    std::cout << "List2: ";
    list2.printLinkedList();
    SinglyLinkedList list3 = list1 + list2;
    std::cout << "List3: ";
    list3.printLinkedList();
    std::cout << "Size: " << list3.getSize() << std::endl;
    return 0;
}
