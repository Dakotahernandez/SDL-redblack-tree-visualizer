/*
* Authors:
   Dakota Hernandez
   Sofia Amador
   Xiangyu Wu
* Assignment Title: CSI 3334 Group Project
* Assignment Description: Using SDL, create a red-black tree visualizer using SDL
* Due Date: 12/10/2024
* Date Created: 10/09/2024
* Date Last Modified: 12/4/2024
*/
/*
 This file will contain all constants
 Comment what each constant is for
 Constants are in all caps and use _ as space
 example: CONSTANT_EXAMPLE
 */
#ifndef Constants_h
#define Constants_h

//size of screen displaying our redblack tree
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

//color constants so there are consitant colors throughout project
const color BROWN                      (165,42,42);
const color RED                        (255,0,0);
const color BLUE                       (0,0,255);
const color GREEN                      (0,255,0);
const color _WHITE                     (255,255,255);
const color BLACK                      (0,0,0);
const color LINE_COLOR                 (100, 100, 100); //changed to darker

//sofia colors feel free to change any of them
const color PO_BLUE     (84, 153, 227);  //pulsate outline
const color N_GREEN     (107, 171, 97);  //new node inside green
const color N_GROU      (30, 82, 36);    //new node outline green
const color N_GRAY      (45, 45, 45);    //black node inside
const color N_REDOU     (163, 35, 18);   //red node outline
const color DARK_PINK   (247, 89, 171);  //button text color
const color CUTE_PINK   (247, 176, 213); //button color

//stuff for nodes
const int NODE_RADIUS = 20; //change to 20 now for 4 digits space
const int VERTICAL_GAP = 50;

//stuff for red black tree displayer
const int TOP_MARGIN = WINDOW_HEIGHT / 10;

#endif /* Constants_h */
