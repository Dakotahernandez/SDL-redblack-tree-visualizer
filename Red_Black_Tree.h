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
#ifndef Red_Black_Tree_h
#define Red_Black_Tree_h
#include <iostream>
#include "Node.h"

using namespace std;
template <typename T>
class Red_Black_Tree{
    private:
    Node<T>* Root;
    
    public:
    void balance(){};
    void insert(){};
    void remove(){};
    void erase(){};
    void Right_rotate(){};
    void Left_rotate(){};
};

#endif /* Red_Black_Tree_h */
