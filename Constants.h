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
const color LINE_COLOR                 (150, 150, 150);

//stuff for nodes

const int NODE_RADIUS = 15;
const int VERTICAL_GAP = 50;
#endif /* Constants_h */
