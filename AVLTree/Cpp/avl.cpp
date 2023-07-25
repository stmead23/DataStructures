#include "avl.hpp"

int AVLTree::Node::getKey(void) { return key; }

void AVLTree::Node::setKey(int k) { key = k; }

AVLTree::Node* AVLTree::Node::getLeft(void) { return left; }

void AVLTree::Node::setLeft(Node* l) { left = l; }

AVLTree::Node* AVLTree::Node::getRight(void) { return right; }

void AVLTree::Node::setRight(Node* r) { right = r; }

int AVLTree::getDepth(Node* current) {
    if (current == nullptr) {
        return 0;
    }
    return 1 + std::max(getDepth(current->getLeft()), getDepth(current->getRight()));
}

int AVLTree::getBalance(Node* current) {
    return getDepth(current->getLeft()) - getDepth(current->getRight());
}

AVLTree::Node* AVLTree::leftRotate(Node* last_root) {
    Node* new_root = last_root->getRight();
    Node* new_left = last_root;
    Node* new_left_right = new_root->getLeft();
    new_left->setRight(new_left_right);
    new_root->setLeft(new_left);
    return new_root;
}

AVLTree::Node* AVLTree::rightRotate(Node* last_root) {
    Node* new_root = last_root->getLeft();
    Node* new_right = last_root;
    Node* new_right_left = new_root->getRight();
    new_root->setRight(new_right);
    new_right->setLeft(new_right_left);
    return new_root;
}

AVLTree::Node* AVLTree::rebalance(Node* current) {
    int balance = getBalance(current);
    if (balance > 1) {
        if (getBalance(current->getLeft()) < 0) {
            current->setLeft(leftRotate(current->getLeft()));
        }
        return rightRotate(current);
    } else if (balance < -1) {
        if (getBalance(current->getRight()) > 0) {
            current->setRight(rightRotate(current->getRight()));
        }
        return leftRotate(current);
    }
    return current;
}

void AVLTree::swapNodes(Node* last_root, Node* new_root) {
    int temp = last_root->getKey();
    last_root->setKey(new_root->getKey());
    new_root->setKey(temp);
}

AVLTree::Node* AVLTree::insert(Node* current, int key) {
    if (current == nullptr) {
        return new Node(key);
    }
    if (key <= current->getKey()) {
        current->setLeft(insert(current->getLeft(), key));
    } else {
        current->setRight(insert(current->getRight(), key));
    }
    return rebalance(current);
}

AVLTree::Node* AVLTree::deleteNode(Node* current, int key) {
    if (current == nullptr) {
        std::cout << "Didn't find key.\n";
        return nullptr;
    }
    if (key < current->getKey()) {
        current->setLeft(deleteNode(current->getLeft(), key));
    } else if (key > current->getKey()) {
        current->setRight(deleteNode(current->getRight(), key));
    } else {
        if (current->getLeft() == nullptr && current->getRight() == nullptr) {
            delete current;
            return nullptr;
        } else if (current->getLeft() != nullptr && current->getRight() == nullptr) {
            swapNodes(current, current->getLeft());
            delete current->getLeft();
            current->setLeft(nullptr);
        } else if (current->getLeft() == nullptr && current->getRight() != nullptr) {
            swapNodes(current, current->getRight());
            delete current->getRight();
            current->setRight(nullptr);
        } else {
            if (current->getRight()->getLeft() == nullptr) {
                swapNodes(current, current->getRight());
                delete current->getRight();
                current->setRight(nullptr);
            } else {
                Node* temp = current->getRight();
                while (temp->getLeft()->getLeft() != nullptr) {
                    temp = current->getLeft();
                }
                swapNodes(temp->getLeft(), current);
                delete temp->getLeft();
                temp->setLeft(nullptr);
            }
        }
    }
    return rebalance(current);
}

void AVLTree::printInOrder(Node* current) {
    if(current == nullptr) {
        std::cout << "Empty ";
        return;
    }
    printInOrder(current->getLeft());
    std::cout << current->getKey() << " ";
    printInOrder(current->getRight());
}

void AVLTree::printLevelOrder(Node* current) {
    if(current == nullptr) {
        return;
    }
    std::cout << current->getKey() << " ";
    printLevelOrder(current->getLeft());
    printLevelOrder(current->getRight());
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

void AVLTree::deleteNode(int key) { 
    if (root == nullptr) {
        std::cout << "Empty.\n";
        return;
    }
    root = deleteNode(root, key);
}

void AVLTree::printTree(void) {
    if(root == nullptr) {
        std::cout << "Empty.\n";
        return;
    }
    //printInOrder(root);
    printLevelOrder(root);
    std::cout << "\n";
}