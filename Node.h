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
#ifndef Node_h
#define Node_h
#include <iostream>
using namespace std;


template <typename T>
struct Node{
    //data
    //left and right pointers for tree
    Node<T>* left;
    Node<T>* right;
    //holds data in the node
    T data;
    //color is represented as a char R for red B for black
    //in case of no color assigned us U for undecided
    char color;
    
    
    //functions
    
};
#endif /* Node_h */
