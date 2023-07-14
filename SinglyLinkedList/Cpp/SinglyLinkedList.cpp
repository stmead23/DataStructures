#include "SinglyLinkedList.hpp"

//Return the key
int SinglyLinkedList::Node::getKey() { return key; }

//Return the next value. Used for iterating the list
SinglyLinkedList::Node* SinglyLinkedList::Node::getNext(void) { return next; }

//Set the next value. Used when inserting or deleting a node
void SinglyLinkedList::Node::setNext(SinglyLinkedList::Node* n) { next = n; }

//Delete the entire list
SinglyLinkedList::~SinglyLinkedList(void) {
    //Keep deleting the first node while the list still exists
    while(head != nullptr) {
        removeFirst();
    }
}

//Return the current size of the list
int SinglyLinkedList::getSize(void) { return size; }

//Return true if the list is empty
bool SinglyLinkedList::isEmpty(void) { return size == 0; }

//Return the key of the first node
int SinglyLinkedList::first(void) {
    //If the list is empty, there is no key
    if(isEmpty()) {
        return 0;
    }
    //Produce the key
    return head->getKey();
}

//Return the key of the last node
int SinglyLinkedList::last(void) {
    //If the list is empty, there is no key
    if(tail == nullptr) {
        return 0;
    }
    //Produce the key
    return tail->getKey();
}
//Search for key in the list. Return true if found.
bool SinglyLinkedList::foundKey(int key) {
    //Iterate through list searching for key
    Node* current = head;
    while(current != nullptr) {
        //Found the key, so stop searching and return true
        if(current->getKey() == key) {
            return true;
        }
        current = current->getNext();
    }
    //The key is not in the list
    return false;
}

//Insert the key value at the front of the list
void SinglyLinkedList::insertFirst(int key) {
    //Create the new node
    Node* new_node = new Node(key);

    //If the list is empty, have both head and tail point to the new node
    if(head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        //Have the new first node point to the current first node, and make the new node the first
        new_node->setNext(head);
        head = new_node;
    }

    //Increase size
    size++;
}

//Insert the key value at the end of the list
void SinglyLinkedList::insertLast(int key) {
    //Create the new node
    Node* new_node = new Node(key);

    //If the list is empty, have both head and tail point to the new node
    if(tail == nullptr) {
        tail = new_node;
        head = new_node;
    } else {
        //Have the current last node point to the new last node, and make the new node the last
        tail->setNext(new_node);
        tail = new_node;
    }

    //Increase size
    size++;
}

//Insert the key value at a specific position in the list
void SinglyLinkedList::insertAtPosition(int position, int key) {
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
    current->setNext(new_node);

    //Increment size
    size++;
}

//Remove the first key in the list, and return it
int SinglyLinkedList::removeFirst(void) {
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
    }
    //Save the key to be returned, and delete the node
    key = temp->getKey();
    delete temp;
    //Update the size, and return the key
    size--;
    return key;
}

//Remove the last key in the list, and return it
int SinglyLinkedList::removeLast(void) {
    //If the list is empty, nothing to be done
    if(isEmpty()) {
        std::cout << "Empty. Instruction ignored.\n";
        return 0;
    }
    int key;
    //If there is only one node, update the head, delete the node, and update tail
    if(head == tail) {
        head = nullptr;
        key = tail->getKey();
        delete tail;
        tail = nullptr;
    } else {
        //Iterate through list to find the node before the tail
        Node* new_tail = head;
        while(new_tail->getNext() != tail) {
            new_tail = new_tail->getNext();
        }
        //Update tail, save the key, and delete the old tail
        new_tail->setNext(nullptr);
        key = tail->getKey();
        delete tail;
        tail = new_tail;
    }
    //Update the size, and return the key
    size--;
    return key;
}

//Remove the key at a specific position in the list, and return it
int SinglyLinkedList::removeAtPosition(int position) {
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
    //Iterate to right before the node to be removed
    Node* current = head;
    for(int i = 0; i < position-1; i++) {
        current = current->getNext();
    }
    //Update the list to skip the node to be removed
    Node* remove = current->getNext();
    current->setNext(remove->getNext());
    //Save the key, and delete the node
    int key = remove->getKey();
    delete remove;
    //Update the size, and return the key
    size--;
    return key;
}

//Remove a specific key from the list
void SinglyLinkedList::removeByKey(int key) {
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
//Print the list
void SinglyLinkedList::printLinkedList(void) {
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