/*
* Authors:
   Dakota Hernandez
   Sofia Amador
   Xiangyu Wu
* Assignment Title: CSI 3334 Group Project
* Assignment Description: Using SDL, create a red-black tree visualizer using SDL
* Due Date: 12/10/2024
* Date Created: 10/09/2024
* Date Last Modified: 10/16/2024
*/
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include <functional>
#include "Node.h"

using namespace std;

template <typename T>
class Red_Black_Tree {
private:
    Node<T>* root; // Pointer to the root of the tree
    /*
     * description: Balances the tree after insertion to maintain Red-Black properties.
     * return: void
     * precondition: Node exists and has been inserted.
     * postcondition: Tree maintains Red-Black properties.
     */
    void balance(Node<T>* node);

    /*
     * description: Performs a right rotation around the given node.
     * return: void
     * precondition: Node exists and has a left child.
     * postcondition: Subtree is rotated to the right.
     */
    void rightRotate(Node<T>* node);

    /*
     * description: Performs a left rotation around the given node.
     * return: void
     * precondition: Node exists and has a right child.
     * postcondition: Subtree is rotated to the left.
     */
    void leftRotate(Node<T>* node);

    /*
     * description: Replaces one subtree with another in the tree.
     * return: void
     * precondition: Both nodes u and v are valid.
     * postcondition: Subtree rooted at u is replaced by subtree rooted at v.
     */
    void transplant(Node<T>* u, Node<T>* v);

    /*
     * description: Finds the minimum node in a subtree.
     * return: Node<T>*
     * precondition: Node exists.
     * postcondition: Returns the node with the smallest value in the subtree.
     */
    Node<T>* minimum(Node<T>* node);

    /*
     * description: Balances the tree after a deletion to maintain Red-Black properties.
     * return: void
     * precondition: A node has been removed.
     * postcondition: Tree maintains Red-Black properties.
     */
    void balanceAfterDelete(Node<T>* node, Node<T>* parent);

public:
    /*
     * description: Default constructor initializing an empty tree.
     * return: Constructor
     * precondition: None
     * postcondition: Tree is initialized with a null root.
     */
    Red_Black_Tree();

    /*
     * description: Constructor initializing a tree with a single root node.
     * return: Constructor
     * precondition: None
     * postcondition: Tree is initialized with a root node of the given value.
     */
    Red_Black_Tree(T rootValue);

    /*
     * description: Copy constructor creating a deep copy of another Red-Black Tree.
     * return: Constructor
     * precondition: Another tree exists.
     * postcondition: A deep copy of the tree is created.
     */
    Red_Black_Tree(const Red_Black_Tree& other);

    /*
     * description: Move constructor transferring ownership of another tree.
     * return: Constructor
     * precondition: Another tree exists.
     * postcondition: Ownership of the tree is transferred.
     */
    Red_Black_Tree(Red_Black_Tree&& other);

    /*
     * description: Destructor freeing all nodes in the tree.
     * return: Destructor
     * precondition: None
     * postcondition: All nodes are deleted, and memory is freed.
     */
    ~Red_Black_Tree();

    /*
     * description: Inserts a value into the tree and balances it.
     * return: void
     * precondition: Value is valid.
     * postcondition: Value is inserted, and tree maintains Red-Black properties.
     */
    void insert(T value);

    /*
     * description: Removes a value from the tree and balances it.
     * return: void
     * precondition: Value exists in the tree.
     * postcondition: Value is removed, and tree maintains Red-Black properties.
     */
    void remove(T value);

    /*
     * description: Clears the tree by deleting all nodes.
     * return: void
     * precondition: Tree exists.
     * postcondition: All nodes are deleted, and the tree is empty.
     */
    void clear();

    /*
     * description: Retrieves the root node of the tree.
     * return: Node<T>*
     * precondition: Tree exists.
     * postcondition: Returns a pointer to the root node.
     */
    Node<T>* getRoot() const;

    /*
     * description: Searches for a value in the tree.
     * return: bool
     * precondition: Tree exists.
     * postcondition: Returns true if value is found, otherwise false.
     */
    bool search(const T& value) const;

};

// Constructors
template <typename T>
Red_Black_Tree<T>::Red_Black_Tree() : root(nullptr) {}

template <typename T>
Red_Black_Tree<T>::Red_Black_Tree(T rootValue) {
    root = new Node<T>(rootValue);
    root->color = NODE_BLACK; // Root is always black
}

template <typename T>
Red_Black_Tree<T>::Red_Black_Tree(const Red_Black_Tree& other) {
    // Deep copy logic here, if needed
}

template <typename T>
Red_Black_Tree<T>::Red_Black_Tree(Red_Black_Tree&& other) : root(other.root) {
    other.root = nullptr;
}

template <typename T>
Red_Black_Tree<T>::~Red_Black_Tree() {
    clear();
}

// Clear function to delete all nodes
template <typename T>
void Red_Black_Tree<T>::clear() {
    std::function<void(Node<T>*)> deleteNodes = [&](Node<T>* node) {
        if (!node) return;
        deleteNodes(node->left);
        deleteNodes(node->right);
        delete node;
    };
    deleteNodes(root);
    root = nullptr;
}

// Insert function with balancing
template <typename T>
void Red_Black_Tree<T>::insert(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!root) {
        root = newNode;
        root->color = NODE_BLACK;
        return;
    }

    Node<T>* parent = nullptr;
    Node<T>* current = root;

    while (current) {
        parent = current;
        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;
    if (value < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

    newNode->color = NODE_RED;
    balance(newNode); // Balance the tree after insertion
}

// Balance function to maintain red-black properties
template <typename T>
void Red_Black_Tree<T>::balance(Node<T>* node) {
    while (node != root && node->parent->color == NODE_RED) {
        Node<T>* parent = node->parent;
        Node<T>* grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node<T>* uncle = grandparent->right;

            if (uncle && uncle->color == NODE_RED) {
                parent->color = NODE_BLACK;
                uncle->color = NODE_BLACK;
                grandparent->color = NODE_RED;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    leftRotate(parent);
                    node = parent;
                    parent = node->parent;
                }
                rightRotate(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            Node<T>* uncle = grandparent->left;

            if (uncle && uncle->color == NODE_RED) {
                parent->color = NODE_BLACK;
                uncle->color = NODE_BLACK;
                grandparent->color = NODE_RED;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rightRotate(parent);
                    node = parent;
                    parent = node->parent;
                }
                leftRotate(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = NODE_BLACK;
}

// Left rotation
template <typename T>
void Red_Black_Tree<T>::leftRotate(Node<T>* x) {
    Node<T>* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Right rotation
template <typename T>
void Red_Black_Tree<T>::rightRotate(Node<T>* y) {
    Node<T>* x = y->left;
    y->left = x->right;
    if (x->right) x->right->parent = y;
    x->parent = y->parent;
    if (!y->parent) root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}

// Helper function to replace one subtree with another
template <typename T>
void Red_Black_Tree<T>::transplant(Node<T>* u, Node<T>* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}

// Helper function to find the minimum node in a subtree
template <typename T>
Node<T>* Red_Black_Tree<T>::minimum(Node<T>* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Remove function with balancing after deletion
template <typename T>
void Red_Black_Tree<T>::remove(T value) {
    Node<T>* node = root;
    Node<T>* to_delete = nullptr;
    Node<T>* child = nullptr;
    Node<T>* parent = nullptr;
    char original_color;

    // Find the node to delete
    while (node != nullptr) {
        if (value == node->value) {
            to_delete = node;
            break;
        } else if (value < node->value) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    // If the node wasn't found, return
    if (to_delete == nullptr) return;

    original_color = to_delete->color;

    if (to_delete->left == nullptr) {
        child = to_delete->right;
        transplant(to_delete, to_delete->right);
    } else if (to_delete->right == nullptr) {
        child = to_delete->left;
        transplant(to_delete, to_delete->left);
    } else {
        Node<T>* successor = minimum(to_delete->right);
        original_color = successor->color;
        child = successor->right;

        if (successor->parent == to_delete) {
            if (child != nullptr) {
                child->parent = successor;
            }
        } else {
            transplant(successor, successor->right);
            successor->right = to_delete->right;
            successor->right->parent = successor;
        }
        transplant(to_delete, successor);
        successor->left = to_delete->left;
        successor->left->parent = successor;
        successor->color = to_delete->color;
    }

    delete to_delete;

    if (original_color == NODE_BLACK) {
        balanceAfterDelete(child, parent);
    }
}

// Balancing the tree after deletion to maintain red-black properties
template <typename T>
void Red_Black_Tree<T>::balanceAfterDelete(Node<T>* node, Node<T>* parent) {
    while (node != root && (node == nullptr || node->color == NODE_BLACK)) {
        if (parent == nullptr) break; // Ensure parent is not null

        if (node == parent->left) {
            Node<T>* sibling = parent->right;

            // Ensure sibling is not nullptr
            if (sibling != nullptr) {
                if (sibling->color == NODE_RED) {
                    sibling->color = NODE_BLACK;
                    parent->color = NODE_RED;
                    leftRotate(parent);
                    sibling = parent->right;
                }

                if ((sibling->left == nullptr || sibling->left->color == NODE_BLACK) &&
                    (sibling->right == nullptr || sibling->right->color == NODE_BLACK)) {
                    sibling->color = NODE_RED;
                    node = parent;
                    parent = node->parent;
                } else {
                    if (sibling->right == nullptr || sibling->right->color == NODE_BLACK) {
                        if (sibling->left != nullptr) sibling->left->color = NODE_BLACK;
                        sibling->color = NODE_RED;
                        rightRotate(sibling);
                        sibling = parent->right;
                    }
                    sibling->color = parent->color;
                    parent->color = NODE_BLACK;
                    if (sibling->right != nullptr) sibling->right->color = NODE_BLACK;
                    leftRotate(parent);
                    node = root;
                }
            } else {
                // Handle case where sibling is nullptr
                node = parent;
                parent = node->parent;
            }
        } else {
            Node<T>* sibling = parent->left;

            if (sibling != nullptr) {
                if (sibling->color == NODE_RED) {
                    sibling->color = NODE_BLACK;
                    parent->color = NODE_RED;
                    rightRotate(parent);
                    sibling = parent->left;
                }

                if ((sibling->left == nullptr || sibling->left->color == NODE_BLACK) &&
                    (sibling->right == nullptr || sibling->right->color == NODE_BLACK)) {
                    sibling->color = NODE_RED;
                    node = parent;
                    parent = node->parent;
                } else {
                    if (sibling->left == nullptr || sibling->left->color == NODE_BLACK) {
                        if (sibling->right != nullptr) sibling->right->color = NODE_BLACK;
                        sibling->color = NODE_RED;
                        leftRotate(sibling);
                        sibling = parent->left;
                    }
                    sibling->color = parent->color;
                    parent->color = NODE_BLACK;
                    if (sibling->left != nullptr) sibling->left->color = NODE_BLACK;
                    rightRotate(parent);
                    node = root;
                }
            } else {
                // Handle case where sibling is nullptr
                node = parent;
                parent = node->parent;
            }
        }
    }

    if (node != nullptr) {
        node->color = NODE_BLACK;
    }
}


// Helper function to get root
template <typename T>
Node<T>* Red_Black_Tree<T>::getRoot() const {
    return root;
}

// Search function to find a value in the tree
template <typename T>
bool Red_Black_Tree<T>::search(const T& value) const {
    Node<T>* current = root;
    while (current != nullptr) {
        if (value == current->value) {
            return true;
        } else if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

#endif /* RED_BLACK_TREE_H */
