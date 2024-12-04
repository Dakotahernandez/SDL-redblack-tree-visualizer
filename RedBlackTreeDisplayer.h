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
#ifndef REDBLACKTREEDISPLAYER_H
#define REDBLACKTREEDISPLAYER_H

#include "SDL_Plotter.h"
#include "Red_Black_Tree.h"
#include "Constants.h"
#include <cmath>

// Constants for color and spacing

// Class to display a Red-Black Tree using SDL_Plotter
template <typename T>
class RedBlackTreeDisplayer {
public:
    RedBlackTreeDisplayer(SDL_Plotter& plotter, int width, int height)
        : plotter(plotter), width(width), height(height) {}

    // Main function to display the Red-Black Tree
    void displayTree(Red_Black_Tree<int>& tree) {
        plotter.clear();
        displayNode(tree.getRoot(), WINDOW_WIDTH / 2, TOP_MARGIN + NODE_RADIUS, WINDOW_WIDTH / 4, NODE_RADIUS);
        plotter.update();
    }

private:
    SDL_Plotter& plotter;
    int width, height;

    //Basic functions to draw circle and line and square/rectangle
    // Draws a circle for a node
    void drawCircle(int x, int y, int radius, color c) {
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w;
                int dy = radius - h;
                if ((dx * dx + dy * dy) <= (radius * radius)) {
                    plotter.plotPixel(x + dx, y + dy, c.R, c.G, c.B);
                }
            }
        }
    }
   
    // Draws a line between two points (for edges between nodes)
   //changed to do-while got rid of break/true method
    void drawLine(int x1, int y1, int x2, int y2, color c) {
        int dx = abs(x2 - x1);          //horizontal distance
        int dy = abs(y2 - y1);          //vertical distance
        int sx = (x1 < x2) ? 1 : -1;    //-1 move left, 1 move right
        int sy = (y1 < y2) ? 1 : -1;    //-1 move up, 1 move down
        int err = dx - dy;              //determines whether to move horizontally/vertically
        do{
            plotter.plotPixel(x1, y1, c.R, c.G, c.B);
            int e2 = err * 2;               //error adjustment/movement
            if (e2 > -dy) {              
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {          
                err += dx;
                y1 += sy;
            }
        }while(x1 != x2 && y1 != y2);
    }
   void drawRectangle(int x, int y, int width, int height, color c){
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++) {
                plotter.plotPixel(x + i, y + j, c.R, c.G, c.B);
            }
        }
    }

    //Xiangyu added drawNumber in 11/20/2024
    //^^^Moved your drawNumber functions to the cpp file
    //moved to a cpp file because they got really long
    //bit weird with templated class, can move back if doesnt work
    //added template to bottom of cpp file so it runs, otherwise it wont
    void cubeIt(int x, int y, color c){
        int scale = 2;  //can change this for thickness
        //color c = GREEN;
        for(int i = 0; i < scale; i++){
            for(int j = 0; j < scale; j++){
                plotter.plotPixel(x + i, y + j, c.R, c.G, c.B);
            }
        }
    }
    void drawLetter(int x, int y, char letter, int scale, color c);
    void drawNumber(int x, int y, int value);

   //feel free to move the buttons around to a diff location/change color/size
   void removeButton(){
        int x = 100;
        int y = 650;
        drawRectangle(x-28, y-30, 120, 60, CUTE_PINK);
        drawLetter(x    , y, 'R', 2, DARK_PINK);
        drawLetter(x +12, y, 'e', 2, DARK_PINK);
        drawLetter(x +25, y, 'm', 2, DARK_PINK);
        drawLetter(x +37, y, 'o', 2, DARK_PINK);
        drawLetter(x +49, y, 'v', 2, DARK_PINK);
        drawLetter(x +61, y, 'e', 2, DARK_PINK);
    }
    void inputButton(){
        int x = 300;
        int y = 650;
        drawRectangle(x-28, y-30, 120, 60, CUTE_PINK);
        drawLetter(x    , y, 'I', 2, DARK_PINK);
        drawLetter(x +13, y, 'n', 2, DARK_PINK);
        drawLetter(x +26, y, 's', 2, DARK_PINK);
        drawLetter(x +38, y, 'e', 2, DARK_PINK);
        drawLetter(x +50, y, 'r', 2, DARK_PINK);
        drawLetter(x +60, y, 't', 2, DARK_PINK);
    }
   //wanted to move title in top middle but need to move whole tree down
    void titleName(){
        int x = 150;
        int y = 580;
        drawLetter(x    , y, 'R', 2, RED);
        drawLetter(x +12, y, 'e', 2, RED);
        drawLetter(x +24, y, 'd', 2, RED);
        drawLetter(x +37, y, '-', 2, N_GRAY);
        drawLetter(x +50, y, 'B', 2, BLACK);
        drawLetter(x +60, y, 'l', 2, BLACK);
        drawLetter(x +69, y, 'a', 2, BLACK);
        drawLetter(x +81, y, 'c', 2, BLACK);
        drawLetter(x +93, y, 'k', 2, BLACK);
        drawLetter(x+120, y, 'T', 2, N_GRAY);
        drawLetter(x+131, y, 'r', 2, N_GRAY);
        drawLetter(x+143, y, 'e', 2, N_GRAY);
        drawLetter(x+155, y, 'e', 2, N_GRAY);
    }
   void drawNodeCircle(int x, int y, int radius, color OutC, color InC, int value) {
        drawCircle(x, y, radius + 2, OutC);     //outline
        drawCircle(x, y, radius, InC);          //inside
        drawNumber(x, y, value);
    }
   void displayNewNode(const color nodeColor, int value){
        /*this is a green node in the top left that is created when a new node
         is created. during comparisons it should do the blue outline animation.
         it should be change color to black/red then glide to its new spot
         leaving the space blank/white*/
        int startX = 50;
        int startY = 50;
        drawNodeCircle(startX, startY, NODE_RADIUS, N_GROU, nodeColor, value);
    }
   void pulsateOutlineSofia(int x, int y, color OC, color IC, int value) {
        //NODE_RADIUS == 20
        for(int i = 0; i < 2; i++){     //two cycles
            for(int i = 0; i < 10; i++){    //grows
                plotter.update();
                plotter.Sleep(20);
                drawCircle(x, y, NODE_RADIUS + i, PO_BLUE);  //outline
                drawNodeCircle(x, y, NODE_RADIUS, OC, IC, value);
            }
            for(int i = 10; i > 0; i--){    //shrinks
                plotter.update();
                plotter.Sleep(20);
                drawCircle(x, y, NODE_RADIUS + i, _WHITE);  //outline
                drawNodeCircle(x, y, NODE_RADIUS, OC, IC, value); //node over
            }
        }
    }
   void drawSlowLine(int x1, int y1, int x2, int y2, color c) {
        int dx = abs(x2 - x1);          //horizontal distance
        int dy = abs(y2 - y1);          //vertical distance
        int sx = (x1 < x2) ? 1 : -1;    //-1 move left, 1 move right
        int sy = (y1 < y2) ? 1 : -1;    //-1 move up, 1 move down
        int err = dx - dy;              //determines whether to move horizontally/vertically
        do{
            plotter.plotPixel(x1, y1, c.R, c.G, c.B);
            plotter.update();
            plotter.Sleep(1);
            int e2 = err * 2;               //error adjustment/movement
            if (e2 > -dy) {                 //horizontal direction
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {                  //vertical direction
                err += dx;
                y1 += sy;
            }
        }while(x1 != x2 && y1 != y2);
    }



   //will update more stuff in a bit need to clean it up but its functional




    // Recursively displays each node in the tree
   void displayNode(Node<T>* node, int x, int y, int horizontal_gap, int radius) {
        if (node == nullptr) return;

        // Determine color based on node color
        color nodeColor;
        if (node->color == NODE_RED) {
            nodeColor = RED;
        } else {
            nodeColor = BLACK;
        }

        // Draw the current node
        drawCircle(x, y, radius, nodeColor, node->value);

        // Draw and display the left child
        if (node->left != nullptr) {
            int childX = x - horizontal_gap;
            int childY = y + VERTICAL_GAP;
            drawLine(x, y, childX, childY, LINE_COLOR);
            displayNode(node->left, childX, childY, horizontal_gap / 2, radius);//Change in 11/20/2024: previous 0.8 *radius let each next node
        }                                                                       //circle shrinks by 0.8.

        // Draw and display the right child
        if (node->right != nullptr) {
            int childX = x + horizontal_gap;
            int childY = y + VERTICAL_GAP;
            drawLine(x, y, childX, childY, LINE_COLOR);
            displayNode(node->right, childX, childY, horizontal_gap / 2, radius);//ditto
        }
    }
};

#endif // REDBLACKTREEDISPLAYER_H

