#include "avl.hpp"

int main(int argc, char* argv[]) {
    AVLTree avl;
    for (int i = 1; i < 8; i++) {
        avl.insert(i);
        avl.printTree();
    }
    for (int i = 7; i > 0; i--) {
        avl.deleteNode(i);
        avl.printTree();
    }
    return 0;
}
