#include "hash_table.hpp"

int main(int argc, char* argv[]) {
    HashTable hash_table;

    for (int i = 0; i < 10000; i++) {
        hash_table.put(i, 'a');
    }
    hash_table.printHashTable();
    std::cout << std::endl;
    for (int i = 0; i < 1000; i++) {
        hash_table.remove(i);
    }
    hash_table.printHashTable();
    return 0;
}
