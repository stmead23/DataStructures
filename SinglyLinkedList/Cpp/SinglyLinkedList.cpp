#include "SinglyLinkedList.hpp"

int SinglyLinkedList::Node::getKey() { return key; }

SinglyLinkedList::Node* SinglyLinkedList::Node::getNext(void) { return next; }

void SinglyLinkedList::Node::setNext(SinglyLinkedList::Node* n) { next = n; }

int SinglyLinkedList::getSize(void) { return size; }

bool SinglyLinkedList::isEmpty(void) { return size == 0; }

int SinglyLinkedList::first(void) {
    if(isEmpty()) {
        return 0;
    }
    return head->getKey();
}

int SinglyLinkedList::last(void) {
    if(tail == nullptr) {
        return 0;
    }
    return tail->getKey();
}

bool SinglyLinkedList::foundKey(int key) {
    Node* current = head;
    while(current != nullptr) {
        if(current->getKey() == key) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

void SinglyLinkedList::insertFirst(int key) {
    Node* new_node = new Node(key);
    if(head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->setNext(head);
        head = new_node;
    }
    size++;
}

void SinglyLinkedList::insertLast(int key) {
    Node* new_node = new Node(key);
    if(tail == nullptr) {
        tail = new_node;
        head = new_node;
    } else {
        tail->setNext(new_node);
        tail = new_node;
    }
    size++;
}

void SinglyLinkedList::insertAtPosition(int position, int key) {
    if(isEmpty() || position == 0) {
        insertFirst(key);
        return;
    } else if(position >= size) {
        insertLast(key);
        return;
    }
    Node* new_node = new Node(key);
    Node* current = head;
    for(int i = 0; i < position-1; i++) {
        current = current->getNext();
    }
    new_node->setNext(current->getNext());
    current->setNext(new_node);
    size++;
}

int SinglyLinkedList::removeFirst(void) {
    if(head == nullptr) {
        std::cout << "Empty. Instruction ignored.\n";
        return 0;
    }
    Node* temp = head;
    int key;
    head = head->getNext();
    if(head == nullptr) {
        tail = nullptr;
    }
    key = temp->getKey();
    delete temp;
    size--;
    return key;
}

int SinglyLinkedList::removeLast(void) {
    if(tail == nullptr) {
        std::cout << "Empty. Instruction ignored.\n";
        return 0;
    }
    int key;
    if(head == tail) {
        head = nullptr;
        key = tail->getKey();
        delete tail;
        tail = nullptr;
        size--;
        return key;
    } else {
        Node* new_tail = head;
        while(new_tail->getNext() != tail) {
            new_tail = new_tail->getNext();
        }
        new_tail->setNext(nullptr);
        key = tail->getKey();
        delete tail;
        tail = new_tail;
        size--;
        return key;
    }
}

int SinglyLinkedList::removeAtPosition(int position) {
    if(isEmpty()) {
        std::cout << "Empty. Instruction ignored.\n";
        return 0;
    } else if(position == 0) {
        return removeFirst();
    } else if(position == size-1) {
        return removeLast();
    } else if(position >= size) {
        std::cout << "List not that long. Removing last element.\n";
        return removeLast();
    }
    Node* current = head;
    for(int i = 0; i < position-1; i++) {
        current = current->getNext();
    }
    Node* remove = current->getNext();
    current->setNext(remove->getNext());
    int key = remove->getKey();
    delete remove;
    return key;
}

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