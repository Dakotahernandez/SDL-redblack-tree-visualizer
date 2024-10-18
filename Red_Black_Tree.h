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
    Node<T>* root;//Pointer to the root of the tree

    //Helper functions
    void balance(Node<T>* node); //Balances the tree after insertion or deletion
    //rotations- these will be called by balance
    void rightRotate(Node<T>* node);//Performs a right rotation on the node
    void leftRotate(Node<T>* node); //Performs a left rotation on the node

public:
    // Constructors
    Red_Black_Tree();//Default constructor
    Red_Black_Tree(T rootValue);//Constructor with root initialization
    Red_Black_Tree(const Red_Black_Tree& other);//Copy constructor
    Red_Black_Tree(Red_Black_Tree&& other);//Move constructor

    // Destructor
    ~Red_Black_Tree();//Destructor to deallocate the tree

    // Tree operations
    void insert(T value);//Inserts a value into the tree
    void remove(T value);//Removes a value from the tree
    void clear();//Clears the entire tree
};

//function defintions
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

