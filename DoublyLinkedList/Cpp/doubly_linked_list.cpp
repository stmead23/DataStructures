#include "doubly_linked_list.hpp"

int DoublyLinkedList::Node::getKey() { return key; }

DoublyLinkedList::Node* DoublyLinkedList::Node::getNext() { return next; }

void DoublyLinkedList::Node::setNext(DoublyLinkedList::Node* n) { next = n; }

DoublyLinkedList::Node* DoublyLinkedList::Node::getPrev() { return prev; }

void DoublyLinkedList::Node::setPrev(DoublyLinkedList::Node* p) { prev = p; }

DoublyLinkedList::~DoublyLinkedList(void) {
    //Keep deleting the first node while the list still exists
    while(head != nullptr) {
        removeFirst();
    }
}

int DoublyLinkedList::getSize(void) { return size; }

//Return true if the list is empty
bool DoublyLinkedList::isEmpty(void) { return size == 0; }

//Return the key of the first node
int DoublyLinkedList::first(void) {
    if(isEmpty()) {
        return 0;
    }
    return head->getKey();
}

//Return the key of the last node
int DoublyLinkedList::last(void) {
    if(isEmpty()) {
        return 0;
    }
    return tail->getKey();
}

//Search for key in the list. Return true if found.
bool DoublyLinkedList::foundKey(int key) {
    if(isEmpty()) {
        return false;
    }
    Node* current = head;
    while (current != nullptr) {
        if (current->getKey() == key) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

//Insert the key value at the front of the list
void DoublyLinkedList::insertFirst(int key) {

    //Create the new node
    Node* new_node = new Node(key);

    //If the list is empty, have both head and tail point to the new node
    if(head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        //Have the new first node point to the current first node, and make the new node the first
        new_node->setNext(head);
        head->setPrev(new_node);
        head = new_node;
    }

    //Increase size
    size++;
}

//Insert the key value at the end of the list
void DoublyLinkedList::insertLast(int key) {
    //Create the new node
    Node* new_node = new Node(key);

    //If the list is empty, have both head and tail point to the new node
    if(tail == nullptr) {
        tail = new_node;
        head = new_node;
    } else {
        //Have the current last node point to the new last node, and make the new node the last
        tail->setNext(new_node);
        new_node->setPrev(tail);
        tail = new_node;
    }

    //Increase size
    size++;
}

//Insert the key value at a specific position in the list
void DoublyLinkedList::insertAtPosition(int position, int key) {
    //If the list is empty or the position specified is the first node, add in front
    if(isEmpty() || position == 0) {
        insertFirst(key);
        return;
    //If the position specified is the last in the list/greater than the size of the list, insert in the last spot
    } else if(position >= size) {
        insertLast(key);
        return;
    }

    //Create the new node
    Node* new_node = new Node(key);

    //Iterate through list until pointer is at spot right before insertion
    Node* current = head;
    for(int i = 0; i < position-1; i++) {
        current = current->getNext();
    }

    //Insert new node in between the two existing nodes
    new_node->setNext(current->getNext());
    new_node->setPrev(current);
    new_node->getNext()->setPrev(new_node);
    current->setNext(new_node);

    //Increment size
    size++;
}

//Remove the first key in the list, and return it
int DoublyLinkedList::removeFirst(void) {
    //If the list is empty, nothing to be done
    if(isEmpty()) {
        std::cout << "Empty. Instruction ignored.\n";
        return 0;
    }

    //Set pointer to node to be removed
    Node* temp = head;
    int key;
    //Update head, and update tail if there will be no remaining nodes
    head = head->getNext();
    if(head == nullptr) {
        tail = nullptr;
    } else {
        head->setPrev(nullptr);
    }
    //Save the key to be returned, and delete the node
    key = temp->getKey();
    delete temp;
    //Update the size, and return the key
    size--;
    return key;
}

//Remove the last key in the list, and return it
int DoublyLinkedList::removeLast(void) {
    //If the list is empty, nothing to be done
    if(isEmpty()) {
        std::cout << "Empty. Instruction ignored.\n";
        return 0;
    }
    //Set pointer to node to be removed
    Node* temp = tail;
    int key;
    //Update head, and update tail if there will be no remaining nodes
    tail = tail->getPrev();
    if(tail == nullptr) {
        head = nullptr;
    } else {
        tail->setNext(nullptr);
    }
    //Save the key to be returned, and delete the node
    key = temp->getKey();
    delete temp;
    //Update the size, and return the key
    size--;
    return key;
}

//Remove the key at a specific position in the list, and return it
int DoublyLinkedList::removeAtPosition(int position) {
    //If the list is empty, nothing to be done
    if(isEmpty()) {
        std::cout << "Empty. Instruction ignored.\n";
        return 0;
    //Deleting the first position
    } else if(position == 0) {
        return removeFirst();
    } else if(position == size-1) {
    //Deleting the last position
        return removeLast();
    //Error in position entered, but still delete the last position
    } else if(position >= size) {
        std::cout << "List not that long. Removing last element.\n";
        return removeLast();
    }
    //Iterate to the node to be removed
    Node* current = head;
    for(int i = 0; i < position; i++) {
        current = current->getNext();
    }
    //Save the key, and delete the node
    int key = current->getKey();
    current->getPrev()->setNext(current->getNext());
    current->getNext()->setPrev(current->getPrev());
    delete current;
    //Update the size, and return the key
    size--;
    return key;
}

//Remove a specific key from the list
void DoublyLinkedList::removeByKey(int key) {
    //If the list is empty, nothing to be done
    if(isEmpty()) {
        std::cout << "Empty. Instruction ignored.\n";
        return;
    }
    //Deleting the first position
    if(head->getKey() == key) {
        removeFirst();
        return;
    }
    //Deleting the last position
    if(tail->getKey() == key) {
        removeLast();
        return;
    }
    //Iterate through position to find key
    Node* current = head->getNext();
    int position = 1;
    while(current != nullptr) {
        //If the key is found, remove it
        if(current->getKey() == key) {
            removeAtPosition(position);
            return;
        }
        current = current->getNext();
        position++;
    }
    //Key was not in list
    std::cout << "Error, key not found. Instruction ignored.\n";
}

void DoublyLinkedList::printLinkedListForward(void) {
    if(isEmpty()) {
        std::cout << "Empty.\n";
        return;
    }
    Node* current = head;
    while(current != nullptr) {
        std::cout << current->getKey();
        if(current->getNext() != nullptr) {
            std::cout << " -> ";
        }
        current = current->getNext();
    }
    std::cout << std::endl;
}

void DoublyLinkedList::printLinkedListReverse(void) {
    if(isEmpty()) {
        std::cout << "Empty.\n";
        return;
    }
    Node* current = tail;
    while(current != nullptr) {
        std::cout << current->getKey();
        if(current->getPrev() != nullptr) {
            std::cout << " -> ";
        }
        current = current->getPrev();
    }
    std::cout << std::endl;
}