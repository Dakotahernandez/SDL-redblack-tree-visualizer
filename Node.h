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
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    Node<T>* left;          // Pointer to left child node
    Node<T>* right;         // Pointer to right child node
    T data;                 // Data contained in the node
    char color;             // 'R' for Red, 'B' for Black, 'U' for undecided

    // Constructor with default arguments for left, right, and color
    Node(T data, Node<T>* left = nullptr, Node<T>* right = nullptr, char color = 'U')
        : data(data), left(left), right(right), color(color) {}
};

#endif /* NODE_H */


