#include "hash_table.hpp"
#include <__config>

int HashTable::Node::getKey(void) { return key; }

char HashTable::Node::getValue(void) { return value; }

HashTable::Node* HashTable::Node::getNext(void) { return next; }

void HashTable::Node::setNext(Node* n) { next = n; }

int HashTable::getSize(void) { return size; }

bool HashTable::isEmpty(void) { return size == 0; }

char HashTable::get(int key) {
    if (isEmpty()) {
        return '\0';
    }
    Node* current = hash_table[key%1000];
    while (current != nullptr) {
        if (current->getKey() == key) {
            return current->getValue();
        }
        current = current->getNext();
    }
    return '\0';
}

void HashTable::put(int key, char value) {
    Node* new_node = new Node(key, value);
    size++;
    if (hash_table[key%1000] == nullptr) {
        hash_table[key%1000] = new_node;
    } else {
        if (hash_table[key%1000]->getKey() > new_node->getKey()) {
            new_node->setNext(hash_table[key%1000]);
            hash_table[key%1000] = new_node;
        } else {
            Node* current = hash_table[key%1000];
            while (current->getNext() != nullptr) {
                if (current->getNext()->getKey() > new_node->getKey()) {
                    new_node->setNext(current->getNext());
                    current->setNext(new_node);
                    return;
                }
                current = current->getNext();
            }
            current->setNext(new_node);
        }
    }
}

char HashTable::remove(int key) {
    if (isEmpty()) {
        std::cout << "Empty. Ignored.\n";
        return '\0';
    }
    if (hash_table[key%1000] == nullptr) {
        std::cout << "Key not in table.\n";
        return '\0';
    }
    if (hash_table[key%1000]->getKey() == key) {
        char return_value = hash_table[key%1000]->getValue();
        Node* remove = hash_table[key%1000];
        hash_table[key%1000] = hash_table[key%1000]->getNext();
        delete remove;
        return return_value;
    }
    Node* current = hash_table[key%1000];
    while (current->getNext() != nullptr) {
        if (current->getNext()->getKey() == key) {
            char return_value = current->getNext()->getValue();
            Node* remove = current->getNext();
            current->setNext(current->getNext()->getNext());
            delete remove;
            return return_value;
        }
        current = current->getNext();
    }
    std::cout << "Key not in table.\n";
    return '\0';
}

std::vector<std::pair<int, char> > HashTable::entrySet(void) {
    if (isEmpty()) {
        std::cout << "Empty.\n";
        return {};
    }
    std::vector<std::pair<int, char> > set;
    int total = 0;
    for (int i = 0; i < 1000; i++) {
        Node* current = hash_table[i];
        while (current != nullptr) {
            set.emplace_back(current->getKey(), current->getValue());
            current = current->getNext();
            total++;
        }
        if (total == size) {
            break;
        }
    }
    return set;
}

std::vector<int> HashTable::keySet(void) {
    if (isEmpty()) {
        std::cout << "Empty.\n";
        return {};
    }
    std::vector<int> keys;
    int total = 0;
    for (int i = 0; i < 1000; i++) {
        Node* current = hash_table[i];
        while (current != nullptr) {
            keys.push_back(current->getKey());
            current = current->getNext();
            total++;
        }
        if (total == size) {
            break;
        }
    }
    return keys;
}

std::vector<char> HashTable::values(void) {
    if (isEmpty()) {
        std::cout << "Empty.\n";
        return {};
    }
    
    std::vector<char> values;
    int total = 0;
    for (int i = 0; i < 1000; i++) {
        Node* current = hash_table[i];
        while (current != nullptr) {
            values.push_back(current->getValue());
            current = current->getNext();
            total++;
        }
        if (total == size) {
            break;
        }
    }
    return values;
}

void HashTable::printHashTable(void) {
    if (isEmpty()) {
        std::cout << "Empty.\n";
        return;
    }
    int total = 0;
    for (int i = 0; i < 1000; i++) {
        Node* current = hash_table[i];
        std::cout << i << ": ";
        while (current != nullptr) {
            std::cout << "(" << current->getKey() << ", " << current->getValue() << ") ";
            current = current->getNext();
            total++;
        }
        std::cout << std::endl;
        if (total == size) {
            break;
        }
    }
}