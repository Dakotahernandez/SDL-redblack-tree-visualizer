/*
* Authors:
   Dakota Hernandez
   Sofia Amador
   Anjan Godavarti
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
        drawCircle(x, y, radius, nodeColor);

        // Draw and display the left child
        if (node->left != nullptr) {
            int childX = x - horizontal_gap;
            int childY = y + VERTICAL_GAP;
            drawLine(x, y, childX, childY, LINE_COLOR);
            displayNode(node->left, childX, childY, horizontal_gap / 2, radius * 0.8);
        }

        // Draw and display the right child
        if (node->right != nullptr) {
            int childX = x + horizontal_gap;
            int childY = y + VERTICAL_GAP;
            drawLine(x, y, childX, childY, LINE_COLOR);
            displayNode(node->right, childX, childY, horizontal_gap / 2, radius * 0.8);
        }
    }
};

#endif // REDBLACKTREEDISPLAYER_H

