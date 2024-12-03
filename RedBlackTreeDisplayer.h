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

    // Draws a circle for a node
    void drawCircle(int x, int y, int radius, color c, int value) {
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w;
                int dy = radius - h;
                if ((dx * dx + dy * dy) <= (radius * radius)) {
                    plotter.plotPixel(x + dx, y + dy, c.R, c.G, c.B);
                }
            }
        }
        drawNumber(x, y, value);
    }
    //Xiangyu added drawNumber in 11/20/2024
    //assume number is no more than 4 digits
    void drawNumber(int x, int y, int value) {
        color c = GREEN; // green digits are so cool!
        //int pixelLength = 7;
        string numberString = to_string(value);
        //add leading zeros if input values are less than 4 digits
        if (numberString.length() == 1) {
            numberString = "000" + numberString;
        }
        else if (numberString.length() == 2) {
            numberString = "00" + numberString;
        }
        else if (numberString.length() == 3) {
            numberString = "0" + numberString;
        }
        //write numbers
        for(int i = 0; i < 4; i++) { // for 4 digits
            char digit = numberString[i];
            int digitPosition = 0; //digitPosition
            
            //Look me: Since digit wedth is 5 pixels, choosing 7 pixels as the distance between two digits
            //allows for 2 pixels of space between them.
            //for x location. Plus, digit height is 9 pixels
            if(i == 0) {
                digitPosition = - 11 ;// location x - 11 for 0th digit
            }
            else if(i == 1) {
                digitPosition = - 4;// location x - 4 for 1th digit
            }
            else if(i == 2) {
                digitPosition = 3; // location x + 3 for 2nd digit
            }
            else if(i == 3) {
                digitPosition = 10;// location + 10 for 3rd digit
            }
            
            
            //Here is to visualize each digit
            if(digit == '0') {
                /* -III-
                 I   I
                 I   I
                 I   I
                 I x I //x is initial plot
                 I   I
                 I   I
                 I   I
                 -III-
                 
                 */
                plotter.plotPixel(x + digitPosition, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y+4, c.R, c.G, c.B);
            }
            else if(digit == '1') {
                /*
                 --I--   y-4
                 -II--   y-3
                 I-I--   y-2
                 --I--   y-1
                 --x--   y
                 --I--   y+1
                 --I--   y+2
                 --I--   y+3
                 IIIII   y+4
                 */
                plotter.plotPixel(x + digitPosition, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+4, c.R, c.G, c.B);
            }
            else if(digit == '2') {
                /*
                 -III-   y-4
                 I---I   y-3
                 ----I   y-2
                 ----I   y-1
                 --xI-   y
                 --I--   y+1
                 -I---   y+2
                 I----   y+3
                 IIIII   y+4
                 */
                plotter.plotPixel(x + digitPosition, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+4, c.R, c.G, c.B);
                
            }
            else if(digit == '3'){
                /*
                 -III-   y-4
                 I---I   y-3
                 ----I   y-2
                 ----I   y-1
                 -IxI-   y
                 ----I   y+1
                 ----I   y+2
                 I---I   y+3
                 -III-   y+4
                 */
                plotter.plotPixel(x + digitPosition, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+1, c.R, c.G, c.B);
                
            }
            else if(digit == '4'){
                /*
                 ---I-  y-4
                 --II-  y-3
                 -I-I-  y-2
                 I--I-  y-1
                 IIxII  y
                 ---I-  y+1
                 ---I-  y+2
                 ---I-  y+3
                 ---I-  y+4
                 */
                plotter.plotPixel(x + digitPosition + 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+4, c.R, c.G, c.B);
            }
            else if(digit == '5'){
                /*
                 IIIII  y-4
                 I----  y-3
                 I----  y-2
                 IIII-  y-1
                 --x-I  y
                 ----I  y+1
                 ----I  y+2
                 I---I  y+3
                 -III-  y+4
                 */
                plotter.plotPixel(x + digitPosition + 2, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y+4, c.R, c.G, c.B);
            }
            else if(digit == '6'){
                /*
                 -III-  y-4
                 I----  y-3
                 I----  y-2
                 I----  y-1
                 IIxI-  y
                 I---I  y+1
                 I---I  y+2
                 I---I  y+3
                 -III-  y+4
                 */
                plotter.plotPixel(x + digitPosition + 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+4, c.R, c.G, c.B);
            }
            else if(digit == '7'){
                /*
                 IIIII  y-4
                 ----I  y-3
                 ----I  y-2
                 ---I-  y-1
                 --x--  y
                 --I--  y+1
                 --I--  y+2
                 --I--  y+3
                 --I--  y+4
                 */
                plotter.plotPixel(x + digitPosition + 2, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+4, c.R, c.G, c.B);
            }
            else if(digit == '8'){
                /*
                 -III-  y-4
                 I---I  y-3
                 I---I  y-2
                 I---I  y-1
                 -IxI-  y
                 I---I  y+1
                 I---I  y+2
                 I---I  y+3
                 -III-  y+4
                 */
                plotter.plotPixel(x + digitPosition + 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+4, c.R, c.G, c.B);
            }
            else if(digit == '9'){ //Last brance is still else-if brance to avoid unexpected input in case
                /*
                 -III-  y-4
                 I---I  y-3
                 I---I  y-2
                 I---I  y-1
                 -IxI-  y
                 ----I  y+1
                 ----I  y+2
                 ----I  y+3
                 -III-  y+4
                 */
                plotter.plotPixel(x + digitPosition + 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y-4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 2, y-1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+3, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+2, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 2, y+1, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition + 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition - 1, y+4, c.R, c.G, c.B);
                plotter.plotPixel(x + digitPosition, y+4, c.R, c.G, c.B);
            }
            
        }
    }
//SOFIA ANIMATION CIRCLE
    /*
#include <ctime>
    void drawXXCircle(int x, int y, int radius, color c) {
        const int maxRadiusIncrease = 10; // Maximum amount circle grows
        const double speed = 2.0;
        static clock_t startTime = clock();
        double elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
        int dynamicRadius = radius + maxRadiusIncrease * fabs(sin(elapsedTime * speed));
        
            
            for (int w = 0; w < dynamicRadius * 2; w++) {
                for (int h = 0; h < dynamicRadius * 2; h++) {
                    int dx = dynamicRadius - w;
                    int dy = dynamicRadius - h;
                    if ((dx * dx + dy * dy) <= (dynamicRadius * dynamicRadius)) {
                        plotter.plotPixel(x + dx, y + dy, c.R, c.G, c.B);
                    }
                }
            }
            
        
        
    }
    */
    // Draws a line between two points (for edges between nodes)
    void drawLine(int x1, int y1, int x2, int y2, color c) {
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int sx = (x1 < x2) ? 1 : -1;
        int sy = (y1 < y2) ? 1 : -1;
        int err = dx - dy;

        while (true) {
            plotter.plotPixel(x1, y1, c.R, c.G, c.B);

            if (x1 == x2 && y1 == y2) break;
            int e2 = err * 2;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }

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

