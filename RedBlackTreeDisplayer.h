/*
* Authors:
   Dakota Hernandez
   Sofia Amador
   Xiangyu Wu
* Assignment Title: CSI 3334 Group Project
* Assignment Description: Using SDL, create a red-black tree visualizer using SDL
* Due Date: 12/10/2024
* Date Created: 10/09/2024
* Date Last Modified: 12/08/2024
*/
#ifndef RedBlackTreeDisplayer_h
#define RedBlackTreeDisplayer_h
#include "SDL_Plotter.h"
#include "Red_Black_Tree.h"
#include "Constants.h"
#include <cmath>

// Class to display a Red-Black Tree using SDL_Plotter
template <typename T>
class RedBlackTreeDisplayer {
public:
    RedBlackTreeDisplayer(SDL_Plotter& plotter, int width, int height)
        : plotter(plotter), width(width), height(height) {}

    // Main function to display the Red-Black Tree
    void displayTree(Red_Black_Tree<T>& tree) {
        plotter.clear();
        displayNode(tree, tree.getRoot(), width / 2, NODE_RADIUS * 6, width / 4, NODE_RADIUS);
        plotter.update();
    }

private:
    SDL_Plotter& plotter;
    int width, height;

    //3 Main Basic Drawing Functions: Circle, Line, Rectangle
    /*
     * description: draw circle with given radius at specific coordinate
     * return: none
     * precondition: xy coordinates valid for window dimensions
     * postcondition: filled circle is displayed at desired location
     */
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
    
    /*
     * description: draw line between two points
     * return: none
     * precondition: xy coordinates valid for window dimensions
     * postcondition: line is drawn at desired location
     */
    void drawLine(int x1, int y1, int x2, int y2, color c) {
        int dx = abs(x2 - x1);         //horizontal distance
        int dy = abs(y2 - y1);         //vertical distance
        int sx = (x1 < x2) ? 1 : -1;   //-1 move left, 1 move right
        int sy = (y1 < y2) ? 1 : -1;   //-1 move up, 1 move down
        int err = dx - dy;             //determines whether to move horizontally/vertically
        do{
            plotter.plotPixel(x1, y1, c.R, c.G, c.B);
            int e2 = err * 2;          //error adjustment/movement
            if (e2 > -dy) {            //horizontal direction
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {             //vertical direction
                err += dx;
                y1 += sy;
            }
        }while(x1 != x2 && y1 != y2);
    }
    
    /*
     * description: draw rectangle with given width and height
     * return: none
     * precondition: xy coordinates valid for window dimensions
     * postcondition: filled rectangle is displayed at desired location
     */
    void drawRectangle(int x, int y, int width, int height, color c){
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++) {
                plotter.plotPixel(x + i, y + j, c.R, c.G, c.B);
            }
        }
    }
    
    /*
     * description: increases pixel size from 1 pixel = 4 pixels
     * return: none
     * precondition: xy coordinates are scaled seperately if needed
     * postcondition: pixels are drawn at desired location
     */
    void cubeIt(int x, int y, color c){
        int scale = 2;  //can change this for thickness
        for(int i = 0; i < scale; i++){
            for(int j = 0; j < scale; j++){
                plotter.plotPixel(x + i, y + j, c.R, c.G, c.B);
            }
        }
    }
    
    /*
     * description: draws letter
     * return: none
     * precondition: letter is included in the selected group in func
     * postcondition: letter is drawn at desired location
     */
    void drawLetter(int x, int y, char letter, int scale, color c);
    /*
     * description: draws number
     * return: none
     * precondition: number is 4 digits or less
     * postcondition: number is drawn at desired location
     */
    void drawNumber(int x, int y, int value);
    
    /*
     * description: draws the labeled remove button
     * return: none
     * precondition: means of drawing letters, scale is 2
     * postcondition: text is drawn at desired location
     */
    void removeLabel(){
        int x = 90;
        int y = 610;
        drawLetter(x    , y, 'P', 2, DARK_PINK);
        drawLetter(x +12, y, 'r', 2, DARK_PINK);
        drawLetter(x +24, y, 'e', 2, DARK_PINK);
        drawLetter(x +36, y, 's', 2, DARK_PINK);
        drawLetter(x +48, y, 's', 2, DARK_PINK);
        drawLetter(x +68, y, '[', 2, DARK_PINK); //+20
        drawLetter(x +78, y, 'R', 2, DARK_PINK);
        drawLetter(x +88, y, ']', 2, DARK_PINK);
        drawLetter(x+106, y, 't', 2, DARK_PINK); //+18
        drawLetter(x+118, y, 'o', 2, DARK_PINK);
        drawLetter(x+138, y, 'R', 2, DARK_PINK); //+18
        drawLetter(x+150, y, 'e', 2, DARK_PINK); //+12
        drawLetter(x+162, y, 'm', 2, DARK_PINK); //+12
        drawLetter(x+174, y, 'o', 2, DARK_PINK); //+12
        drawLetter(x+186, y, 'v', 2, DARK_PINK); //+12
        drawLetter(x+198, y, 'e', 2, DARK_PINK); //+12
    }
    
    /*
     * description: draws the labeled insert button
     * return: none
     * precondition: means of drawing letters, scale is 2
     * postcondition: button is drawn at desired location
     */
    void inputLabel(){
        int x = 90;
        int y = 640;
        drawLetter(x    , y, 'P', 2, DARK_PINK);
        drawLetter(x +12, y, 'r', 2, DARK_PINK);
        drawLetter(x +24, y, 'e', 2, DARK_PINK);
        drawLetter(x +36, y, 's', 2, DARK_PINK);
        drawLetter(x +48, y, 's', 2, DARK_PINK);
        drawLetter(x +68, y, '[', 2, DARK_PINK); //+20
        drawLetter(x +78, y, 'I', 2, DARK_PINK);
        drawLetter(x +88, y, ']', 2, DARK_PINK);
        drawLetter(x+106, y, 't', 2, DARK_PINK); //+18
        drawLetter(x+118, y, 'o', 2, DARK_PINK);
        drawLetter(x+138, y, 'I', 2, DARK_PINK); //+18
        drawLetter(x+150, y, 'n', 2, DARK_PINK); //+12
        drawLetter(x+162, y, 's', 2, DARK_PINK); //+12
        drawLetter(x+174, y, 'e', 2, DARK_PINK); //+12
        drawLetter(x+186, y, 'r', 2, DARK_PINK); //+12
        drawLetter(x+198, y, 't', 2, DARK_PINK); //+12
    }
    
    /*
     * description: draws the title "Red-Black Tree"
     * return: none
     * precondition: means of drawing letters, scale is 2
     * postcondition: phrase is drawn at desired location
     */
    void titleName(){
        int x = 515;
        int y = 60;
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
    
    /*
     * description: draws "Inserting"
     * return: none
     * precondition: all letters have means of displaying
     * postcondition: phrase is drawn at desired location
     */
    void newNodeText1(){
        int x = 600;
        int y = 610;
        drawLetter(x   , y, 'I', 2, N_GROU); //+18
        drawLetter(x+12, y, 'n', 2, N_GROU); //+12
        drawLetter(x+24, y, 's', 2, N_GROU); //+12
        drawLetter(x+36, y, 'e', 2, N_GROU); //+12
        drawLetter(x+48, y, 'r', 2, N_GROU); //+12
        drawLetter(x+60, y, 't', 2, N_GROU); //+12
        drawLetter(x+69, y, 'i', 2, N_GROU); //+12
        drawLetter(x+80, y, 'n', 2, N_GROU); //+12
        drawLetter(x+92, y+6, 'g', 2, N_GROU); //+12
    }
    /*
     * description: draws "New Node:"
     * return: none
     * precondition: all letters have means of displaying
     * postcondition: phrase is drawn at desired location
     */
    void newNodeText2(){
        int x = 600 + 2;
        int y = 640;
        drawLetter(x   , y, 'N', 2, N_GROU); //+12
        drawLetter(x+12, y, 'e', 2, N_GROU); //+12
        drawLetter(x+24, y, 'w', 2, N_GROU); //+12
        drawLetter(x+36+7, y, 'N', 2, N_GROU); //+12
        drawLetter(x+48+7, y, 'o', 2, N_GROU); //+12
        drawLetter(x+60+7, y, 'd', 2, N_GROU); //+12
        drawLetter(x+72+7, y, 'e', 2, N_GROU); //+12
        drawLetter(x+81+7, y +1, ':', 2, N_GROU); //+12
    }
    
    /*
     * description: draws a filled node circle with outline and num value
     * return: none
     * precondition: valid xy coordinates, value digits 4 or less
     * postcondition: node is drawn at desired location
     */
    void drawNodeCircle(int x, int y, int radius, color OutC, color InC, int value) {
        drawCircle(x, y, radius + 2, OutC);     //outline
        drawCircle(x, y, radius, InC);          //inside
        drawNumber(x, y, value);
    }
    
    /*
     * description: draws new node with value in top left corner before sort
     * return: none
     * precondition: value digits 4 or less
     * postcondition: node is drawn at inital location before placement
     */
    void displayNewNode(const color nodeColor, int value){
        int startX = 60;
        int startY = 60;
        drawNodeCircle(startX, startY, NODE_RADIUS, N_GROU, nodeColor, value);
    }
    
    /*
     * description: deletes a circle by drawing white
     * return: none
     * precondition: valid xy coordinates
     * postcondition: previous circle should be completely gone
     */
    void clearCircle(int x, int y, int radius) {
        drawCircle(x, y, radius, _WHITE);
    }
    
    /*
     * description: indicates which node is being currently viewed
     * return: none
     * precondition: valid xy coordinates
     * postcondition: blue outline animation around node 2 times
     */
    void pulsateOutline(int x, int y, color OC, color IC, int value){
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
    void PUSLATECIRCLE(Node<T>* node, int x, int y, int horizontal_gap, color OC, color IC) {
        //NODE_RADIUS == 20
        for(int i = 0; i < 2; i++){     //two cycles
            for(int i = 0; i < 10; i++){    //grows
                plotter.update();
                plotter.Sleep(20);
                drawCircle(x, y, NODE_RADIUS + i, PO_BLUE);  //outline
                drawNodeCircle(x, y, NODE_RADIUS, OC, IC, node->value);
            }
            for(int i = 10; i > 0; i--){    //shrinks
                plotter.update();
                plotter.Sleep(20);
                drawCircle(x, y, NODE_RADIUS + i, _WHITE);  //deletes
                redrawNodes(node, x, y, horizontal_gap, true);
                drawNodeCircle(x, y, NODE_RADIUS, OC, IC, node->value); //node over
            }
        }
    }
    
    
    /*
     * description: draws line with slow animation for arrows
     * return: none
     * precondition: valid xy coordinates
     * postcondition: line is incrementally drawn from one point to next
     */
    void drawSlowLine(int x1, int y1, int x2, int y2, color c, Node<T>* node, color OC, color IC) {
        int dx = abs(x2 - x1);          //horizontal distance
        int dy = abs(y2 - y1);          //vertical distance
        int sx = (x1 < x2) ? 1 : -1;    //-1 move left, 1 move right
        int sy = (y1 < y2) ? 1 : -1;    //-1 move up, 1 move down
        int err = dx - dy;              //determines whether to move horizontally/vertically
        int x = x1;
        int y = y1;
        do{
            plotter.plotPixel(x1, y1, c.R, c.G, c.B);
            drawNodeCircle(x, y, NODE_RADIUS, OC, IC, node->value);
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
    
    /*
     * description: helper function to draw filled triangle using
     * a line between two points and a given y-coordinate
     * return: interpolated x-coordinate
     * precondition: valid xy coordinates, y1-y0 != 0
     * postcondition: previous circle should be completely gone
     */
    int interpolateX(int x0, int y0, int x1, int y1, int y){
        if (y1 == y0) return x0;
        return x0 + ((x1 - x0) * (y - y0)) / (y1 - y0);
    }
    /*
     * description: draws a filled triangle for arrowheads
     * return: none
     * precondition: three valid points xy coordinates of triangle
     * postcondition: triangle is drawn pointing in specific direction
     */
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
    
    /*
     * description: calculates 3 coordinates of triangle for arrow
     * return: none
     * precondition: two valid points xy coordinates of a line
     * postcondition: triangle is drawn at end of a line
     */
    void drawArrowhead(int x1, int y1, int x2, int y2, int r, color c) {
        int dx = x2 - x1;       //direction
        int dy = y2 - y1;
        double length = sqrt(dx * dx + dy * dy);
        if (length == 0) return;
        double ux = dx / length;
        double uy = dy / length;
        double width = r / sqrt(3.0);
        //added this to move the arrows so theyre not hidden by node circles
        int x = x2;
        int y = y2;
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
        
        drawLine(x, y, x2, y2, _WHITE);
        drawLine(x, y, x2+1, y2+1, _WHITE);
        drawLine(x, y, x2-1, y2-1, _WHITE);
        //this actually draws it using the three points
        drawFilledTriangle(Px1, Py1, Px2, Py2, Px3, Py3, c);
    }
    /*
     * description: draws an animated arrow
     * return: none
     * precondition: valid points xy coordinates
     * postcondition: arrow is drawn pointing in specific direction
     */
    void drawArrow(int x1, int y1, int x2, int y2, color c, Node<T>* node, color OC, color IC){
        drawSlowLine(x1, y1, x2, y2, c, node, OC, IC);
        drawArrowhead(x1, y1, x2, y2, 17, c);
    }
    //draws an arrow with no animation
    void drawArrowFLAT(int x1, int y1, int x2, int y2, color c){
        drawLine(x1, y1, x2, y2, c);
        drawArrowhead(x1, y1, x2, y2, 17, c);
    }

    /*
     * description: redraws parent and/or child node
     * return: none
     * precondition: node tree exists
     * postcondition: used inbetween other animation frames to redraw
     */
    void redrawNodes(Node<T>* node, int x, int y, int horizontal_gap, bool display){
        color nodeColor, nodeOutline;
        if (node->color == NODE_RED) {
            nodeOutline = N_REDOU;
            nodeColor = RED;
        } else {
            nodeOutline = BLACK;
            nodeColor = N_GRAY;
        }
        int parentX = 0;
        int parentY = y - VERTICAL_GAP;
        //goal is to redraw the arrow from parent node to current node after pulse animation
        if(node->parent != nullptr){    //if current node is not the root node
            if(node->parent->left == node){
                //current node is left child of its parent
                parentX = x + (horizontal_gap * 2);
            }else if(node->parent->right == node){
                //current node is right child of its parent
                parentX = x - (horizontal_gap * 2);
            }
            //redraw arrow that was erased
            drawArrowFLAT(parentX, parentY, x, y, LINE_COLOR);
            
            color parentColor, parentOutline;
            if (node->parent->color == NODE_RED) {
                parentOutline = N_REDOU;
                parentColor = RED;
            } else {
                parentOutline = BLACK;
                parentColor = N_GRAY;
            }
            //redraw parent and child that was covered by arrow lines
            drawNodeCircle(parentX, parentY, NODE_RADIUS, parentOutline, parentColor, (node->parent)->value);
            if(display){
                //child
                drawNodeCircle(x, y, NODE_RADIUS, nodeOutline, nodeColor, node->value);
            }
        }
    }

    /*
     * description: moves a node smoothly from one place to next
     * return: none
     * precondition: node tree exists
     * postcondition: a node stays at its final location
     */
    void glideNodeNUM(int x1, int y1, int x2, int y2, color OUTc, color INc, Node<T>* node, int horizontal_gap){
        float dx = x2 - x1;         //horizontal distance
        float dy = y2 - y1;         //vertical distance
        float steps = max(abs(dx), abs(dy));
        
        float xRate = dx / steps;
        float yRate = dy / steps;
        float x = x1;
        float y = y1;

        
        for(int i = 0; i <= steps; i++){
            drawNodeCircle(x, y, NODE_RADIUS, OUTc, INc, node->value);
            plotter.update();
            if(i < steps){
                drawCircle(x, y, NODE_RADIUS+2, _WHITE);
                redrawNodes(node, x2, y2, horizontal_gap, false);
                newNodeText1();
                newNodeText2();
            }
            x += xRate;
            y += yRate;
            plotter.Sleep(1);
        }
    }
    /*
     * description: recursively displays each node in the tree
     * return: none
     * precondition: tree's logic has been pre arranged and made
     * postcondition: tree is drawn
     */
    void displayNode(Red_Black_Tree<T>& tree, Node<T>* node, int x, int y, int horizontal_gap, int radius) {
        titleName();
        removeLabel();
        inputLabel();
        if (node == nullptr) return;
        
        // Determine color based on node color
        color nodeColor, nodeOutline;
        if (node->color == NODE_RED) {
            nodeOutline = N_REDOU;
            nodeColor = RED;
        } else {
            nodeOutline = BLACK;
            nodeColor = N_GRAY;
        }
        
        newNodeText1();
        newNodeText2();
        
        pulsateOutline(750, 630, N_GROU, N_GREEN, node->value);
        clearCircle(750, 630, radius+5);
        //drawRectangle(590, 600, 150, 100, _WHITE);
        
        glideNodeNUM(750, 630, x, y, N_GROU, N_GREEN, node, horizontal_gap);
        PUSLATECIRCLE(node, x, y, horizontal_gap, nodeOutline, nodeColor);
        
        // Draw and display the left child
        if (node->left != nullptr) {
            int childX = x - horizontal_gap;
            int childY = y + VERTICAL_GAP;
            drawArrow(x, y, childX, childY, LINE_COLOR, node, nodeOutline, nodeColor);
            drawNodeCircle(x, y, radius, nodeOutline, nodeColor, node->value);
            displayNode(tree, node->left, childX, childY, horizontal_gap / 2, radius);
        }

        // Draw and display the right child
        if (node->right != nullptr) {
            int childX = x + horizontal_gap;
            int childY = y + VERTICAL_GAP;
            drawArrow(x, y, childX, childY, LINE_COLOR, node, nodeOutline, nodeColor);
            drawNodeCircle(x, y, radius, nodeOutline, nodeColor, node->value);
            displayNode(tree, node->right, childX, childY, horizontal_gap / 2, radius);
        }
    }
};

#endif /* RedBlackTreeDisplayer_h */
