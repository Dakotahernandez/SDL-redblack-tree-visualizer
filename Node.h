/*
* Authors:
   Dakota Hernandez
   Sofia Amador
   Anjan Godavarti
* Assignment Title: CSI 3334 Group Project
* Assignment Description: Using SDL, create a red-black tree visualizer using SDL
* Due Date: 12/10/2024
* Date Created: 10/09/2024
* Date Last Modified: 10/16/2024
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

// Constants for node color
constexpr char NODE_RED = 'R';
constexpr char NODE_BLACK = 'B';

template <typename T>
struct Node {
    T value;                // Data contained in the node
    Node<T>* left;          // Pointer to left child node
    Node<T>* right;         // Pointer to right child node
    Node<T>* parent;        // Pointer to parent node
    char color;             // 'R' for Red, 'B' for Black

    // Constructor with default arguments for left, right, parent, and color
    Node(T value, Node<T>* left = nullptr, Node<T>* right = nullptr, Node<T>* parent = nullptr, char color = NODE_RED)
        : value(value), left(left), right(right), parent(parent), color(color) {}
};

#endif /* NODE_H */
