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

// Custom libraries
#include "SDL_Plotter.h"
#include "Constants.h"
#include "Node.h"
#include "Red_Black_Tree.h"
#include "RedBlackTreeDisplayer.h"
#include "user_interface.h"
// C++ standard libraries
#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
    SDL_Plotter plotter(WINDOW_HEIGHT, WINDOW_WIDTH);
    Red_Black_Tree<int> tree;
    int input;
    char RorI;

    RedBlackTreeDisplayer<int> displayer(plotter, WINDOW_WIDTH, WINDOW_HEIGHT);

    while (!plotter.getQuit()) {
        displayer.displayTree(tree); // Display the Red-Black Tree

        cout << "Press I to insert and R to remove: ";
        cin >> RorI;
        cout << RorI << endl;
        cout << "Please enter the positive integer(within 4 digits) you would like to ";
        if(RorI == 'I' || RorI == 'R'){
            if(RorI == 'I'){
                cout << "insert :";
            }
            else{
                cout << "remove :";
            }
            cin >> input;
            cout << input << endl;
            while(input > 9999 || input < 0){
                cout <<"Error: please enter the positive integer within 4 digits" << endl;
                cout <<"New integer: ";
                cin >> input;
                cout << input << endl;
            }
            if(RorI == 'I'){
                tree.insert(input);
            }
            else{
                tree.remove(input);
            }
        }
        if (plotter.kbhit()) {
            char key = plotter.getKey();
            if (key == 'q') { // Quit if 'q' is pressed
                plotter.setQuit(true);
            }
        }
    }

    return 0;
}
