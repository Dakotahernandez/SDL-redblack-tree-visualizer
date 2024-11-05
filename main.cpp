/*
* Authors:
   Dakota Hernandez
   Griffin Roe
   Sofia Amador
   Anjan Godavarti
* Assignment Title: CSI 3334 Group Project
* Assignment Description: Using SDL, create a red-black tree visualizer using SDL
* Due Date: 12/10/2024
* Date Created: 10/09/2024
* Date Last Modified: 10/16/2024
*/
// Custom libraries
#include "SDL_Plotter.h"
#include "Constants.h"
#include "Node.h"
#include "Red_Black_Tree.h"
#include "RedBlackTreeDisplayer.h"
// C++ standard libraries
#include <iostream>
#include <cassert>
#include <cmath>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(int argc, char** argv) {
    SDL_Plotter plotter(WINDOW_HEIGHT, WINDOW_WIDTH);
    Red_Black_Tree<int> tree;

    // Insert some values into the tree for demonstration
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(100);
    tree.insert(140);
    tree.insert(750);
    tree.insert(10);
    tree.insert(3);
    tree.insert(111923);
    tree.insert(5110);
    tree.insert(3110);
    tree.insert(7110);
    tree.insert(2110);
    tree.insert(4110);
    tree.insert(6110);
    tree.insert(8110);
    tree.insert(11100);
    tree.insert(11140);
    tree.insert(71150);
    tree.insert(1110);
    tree.insert(311);
    tree.insert(111923);

    RedBlackTreeDisplayer<int> displayer(plotter, WINDOW_WIDTH, WINDOW_HEIGHT);

    while (!plotter.getQuit()) {
        displayer.displayTree(tree); // Display the Red-Black Tree

        if (plotter.kbhit()) {
            char key = plotter.getKey();
            if (key == 'q') { // Quit if 'q' is pressed
                plotter.setQuit(true);
            }
        }
    }

    return 0;
}
