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
   
    //helper function for drawing filled triangle
    int interpolateX(int x0, int y0, int x1, int y1, int y){
        if (y1 == y0) return x0;
        return x0 + ((x1 - x0) * (y - y0)) / (y1 - y0);
    }
    void drawFilledTriangle(int x1, int y1, int x2, int y2, int x3, int y3, color c){
        if(y1 > y2){
            swap(x1, x2);
            swap(y1, y2);
        }
        if(y1 > y3){
            swap(x1, x3);
            swap(y1, y3);
        }
        if(y2 > y3){
            swap(x2, x3);
            swap(y2, y3);
        }

        //draws lines between edges of the triangle
        for (int y = y1; y <= y3; y++){
            int xStart, xEnd;
            if(y <= y2){
                xStart = interpolateX(x1, y1, x2, y2, y);
                xEnd = interpolateX(x1, y1, x3, y3, y);
            }else{
                xStart = interpolateX(x2, y2, x3, y3, y);
                xEnd = interpolateX(x1, y1, x3, y3, y);
            }
            if(xStart > xEnd){
                swap(xStart, xEnd);
            }

            for(int x = xStart; x <= xEnd; x++){
                plotter.plotPixel(x, y, c.R, c.G, c.B);
            }
        }
    }
    
    //this function calculates the 3 coordinates of the triangle for arrow
    void drawArrowhead(int x1, int y1, int x2, int y2, int r, color c) {
        int dx = x2 - x1;       //direction
        int dy = y2 - y1;
        double length = sqrt(dx * dx + dy * dy);
        if (length == 0) return;
        double ux = dx / length;
        double uy = dy / length;
        double width = r / sqrt(3.0);
        //added this to move the arrows so theyre not hidden by node circles
        x2 = x2 - static_cast<int>(r * ux);
        y2 = y2 - static_cast<int>(r * uy);
        
        //perpendicular rotate 90 degrees clockwise
        double vx = -uy;
        double vy = ux;
        
        //P1
        int Px1 = x2;
        int Py1 = y2;
        //P2
        int Px2 = x2 - static_cast<int>(r * ux) + static_cast<int>(width * vx);
        int Py2 = y2 - static_cast<int>(r * uy) + static_cast<int>(width * vy);
        //P3
        int Px3 = x2 - static_cast<int>(r * ux) - static_cast<int>(width * vx);
        int Py3 = y2 - static_cast<int>(r * uy) - static_cast<int>(width * vy);
        
        //this actually draws it using the three points
        drawFilledTriangle(Px1, Py1, Px2, Py2, Px3, Py3, c);
    }
    
    void drawArrow(int x1, int y1, int x2, int y2, color c){
        drawSlowLine(x1, y1, x2, y2, c);
        drawArrowhead(x1, y1, x2, y2, 17, c);
    }
    


    // Recursively displays each node in the tree
   void displayNode(Node<T>* node, int x, int y, int horizontal_gap, int radius) {
        titleName();
        removeButton();
        inputButton();
        if (node == nullptr) return;

        // Determine color based on node color
        color nodeColor;
        if (node->color == NODE_RED) {
            nodeColor = RED;
        } else {
            nodeColor = BLACK;
        }

        // Draw the current node
        drawNodeCircle(x, y, radius, nodeOutline, nodeColor, node->value);

      //new stuffz
      //new node in top left corner
      displayNewNode(N_GREEN, node->value);
      //blue line for green new node
        pulsateOutlineSofia(50, 50, N_GROU, N_GREEN, node->value);
        
        //blue outline for node in tree
        pulsateOutlineSofia(x, y, nodeOutline, nodeColor, node->value);

      
        // Draw and display the left child
        if (node->left != nullptr) {
            int childX = x - horizontal_gap;
            int childY = y + VERTICAL_GAP;
            drawArrow(x, y, childX, childY, LINE_COLOR);
            displayNode(node->left, childX, childY, horizontal_gap / 2, radius);//Change in 11/20/2024: previous 0.8 *radius let each next node
        }                                                                       //circle shrinks by 0.8.

        // Draw and display the right child
        if (node->right != nullptr) {
            int childX = x + horizontal_gap;
            int childY = y + VERTICAL_GAP;
            drawArrow(x, y, childX, childY, LINE_COLOR);
            displayNode(node->right, childX, childY, horizontal_gap / 2, radius);//ditto
        }
    }
};

#endif // REDBLACKTREEDISPLAYER_H

