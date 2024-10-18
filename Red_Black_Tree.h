/*
* Authors:
   Dakota Hernandez
   Griffin Roe
   Sofia Amador
   Anjan Godavarti
   Mason Baxter
   Jonah Beck
* Assignment Title: CSI 3334 Group Project
* Assignment Description: Using SDL, create a red-black tree visualizer using SDL
* Due Date: 12/10/2024
* Date Created: 10/09/2024
* Date Last Modified: 10/16/2024
*/

#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class Red_Black_Tree {
private:
    Node<T>* root; //Pointer to the root of the tree

    /*
    * description: Balances the tree after insertion or deletion.
    * return: None.
    * precondition: A node has been inserted or deleted.
    * postcondition: The tree is balanced according to red-black tree properties.
    */
    void balance(Node<T>* node);

    /*
    * description: Performs a right rotation on the node.
    * return: None.
    * precondition: A node exists that requires a right rotation.
    * postcondition: The node has been right-rotated in the tree.
    */
    void rightRotate(Node<T>* node);

    /*
    * description: Performs a left rotation on the node.
    * return: None.
    * precondition: A node exists that requires a left rotation.
    * postcondition: The node has been left-rotated in the tree.
    */
    void leftRotate(Node<T>* node);

public:
    /*
    * description: Default constructor for the red-black tree.
    * return: None.
    * precondition: None.
    * postcondition: An empty red-black tree is created.
    */
    Red_Black_Tree();

    /*
    * description: Constructor with root initialization.
    * return: None.
    * precondition: A value for the root is provided.
    * postcondition: A red-black tree is created with the specified root value.
    */
    Red_Black_Tree(T rootValue);

    /*
    * description: Copy constructor for the red-black tree.
    * return: None.
    * precondition: An existing red-black tree is provided.
    * postcondition: A copy of the red-black tree is created.
    */
    Red_Black_Tree(const Red_Black_Tree& other);

    /*
    * description: Move constructor for the red-black tree.
    * return: None.
    * precondition: An rvalue reference to a red-black tree is provided.
    * postcondition: The red-black tree is moved, leaving the original empty.
    */
    Red_Black_Tree(Red_Black_Tree&& other);

    /*
    * description: Destructor for the red-black tree.
    * return: None.
    * precondition: A red-black tree exists.
    * postcondition: The red-black tree is deallocated and destroyed.
    */
    ~Red_Black_Tree();

    /*
    * description: Inserts a value into the red-black tree.
    * return: None.
    * precondition: A value is provided for insertion.
    * postcondition: The value is inserted and the tree is balanced.
    */
    void insert(T value);

    /*
    * description: Removes a value from the red-black tree.
    * return: None.
    * precondition: A value exists in the tree for removal.
    * postcondition: The value is removed and the tree is balanced.
    */
    void remove(T value);

    /*
    * description: Clears the entire red-black tree.
    * return: None.
    * precondition: The red-black tree exists.
    * postcondition: The tree is cleared and all nodes are deallocated.
    */
    void clear();
};

//function definitions
// Constructors
template <typename T>
Red_Black_Tree<T>::Red_Black_Tree(){
    
}

template <typename T>
Red_Black_Tree<T>::Red_Black_Tree(T rootValue){
    
}

template <typename T>
Red_Black_Tree<T>::Red_Black_Tree(const Red_Black_Tree& other){
    
}

template <typename T>
Red_Black_Tree<T>::Red_Black_Tree(Red_Black_Tree&& other){
    
}

// Destructor
template <typename T>
Red_Black_Tree<T>::~Red_Black_Tree(){
    
}

// Tree operations
template <typename T>
void Red_Black_Tree<T>::insert(T value){
    
}

template <typename T>
void Red_Black_Tree<T>::remove(T value){
    
}

template <typename T>
void Red_Black_Tree<T>::clear(){
    
}

#endif /* RED_BLACK_TREE_H */

