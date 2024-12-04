//cpp file
#include "RedBlackTreeDisplayer.h"
template <typename T>
void RedBlackTreeDisplayer<T>::drawLetter(int x, int y, char letter, int scale, color c){
    //Do not have whole alphabet only relevant letters for words:
    //Remove, Input, Insert, Red-Black Tree
    //EACH PIXEL IS A 2*2 CUBE found in helper funct cubeit
    if(letter == 'R'){
        /*
         IIII-  y-4
         I---I  y-3
         I---I  y-2
         I--I-  y-1
         III--  y
         I--I-  y+1
         I---I  y+2
         I---I  y+3
         I---I  y+4
         */
        cubeIt(x -2 *scale, y-4 *scale, c);
        cubeIt(x -1 *scale, y-4 *scale, c);
        cubeIt(x          , y-4 *scale, c);
        cubeIt(x +1 *scale, y-4 *scale, c);
        cubeIt(x -2 *scale, y-3 *scale, c);
        cubeIt(x +2 *scale, y-3 *scale, c);
        cubeIt(x -2 *scale, y-2 *scale, c);
        cubeIt(x +2 *scale, y-2 *scale, c);
        cubeIt(x -2 *scale, y-1 *scale, c);
        cubeIt(x +1 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x -1 *scale, y         , c);
        cubeIt(x          , y         , c);
        cubeIt(x -2* scale, y+1* scale, c);
        cubeIt(x +1* scale, y+1* scale, c);
        cubeIt(x -2* scale, y+2* scale, c);
        cubeIt(x +2* scale, y+2* scale, c);
        cubeIt(x -2* scale, y+3* scale, c);
        cubeIt(x +2* scale, y+3* scale, c);
        cubeIt(x -2* scale, y+4* scale, c);
        cubeIt(x +2* scale, y+4* scale, c);
    }else if(letter == 'e'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         -III-  y-1
         I---I  y
         IIII-  y+1
         I----  y+2
         I---I  y+3
         -III-  y+4
         */
        cubeIt(x -1 *scale, y-1 *scale, c);
        cubeIt(x          , y-1 *scale, c);
        cubeIt(x +1 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x +2 *scale, y         , c);
        cubeIt(x -2 *scale, y+1 *scale, c);
        cubeIt(x -1 *scale, y+1 *scale, c);
        cubeIt(x          , y+1 *scale, c);
        cubeIt(x +1 *scale, y+1 *scale, c);
        cubeIt(x -2 *scale, y+2 *scale, c);
        cubeIt(x -2 *scale, y+3 *scale, c);
        cubeIt(x +2 *scale, y+3 *scale, c);
        cubeIt(x -1 *scale, y+4 *scale, c);
        cubeIt(x          , y+4 *scale, c);
        cubeIt(x +1 *scale, y+4 *scale, c);
        
    }else if(letter == 'm'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         I---I  y-1
         II-II  y
         I-I-I  y+1
         I---I  y+2
         I---I  y+3
         I---I  y+4
         */
        cubeIt(x -2 *scale, y-1 *scale, c);
        cubeIt(x +2 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x -1 *scale, y         , c);
        cubeIt(x +1 *scale, y         , c);
        cubeIt(x +2 *scale, y         , c);
        cubeIt(x -2 *scale, y+1 *scale, c);
        cubeIt(x          , y+1 *scale, c);
        cubeIt(x +2 *scale, y+1 *scale, c);
        cubeIt(x -2 *scale, y+2 *scale, c);
        cubeIt(x +2 *scale, y+2 *scale, c);
        cubeIt(x -2 *scale, y+3 *scale, c);
        cubeIt(x +2 *scale, y+3 *scale, c);
        cubeIt(x -2 *scale, y+4 *scale, c);
        cubeIt(x +2 *scale, y+4 *scale, c);
    }else if(letter == 'o'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         -III-  y-1
         I---I  y
         I---I  y+1
         I---I  y+2
         I---I  y+3
         -III-  y+4
         */
        cubeIt(x -1 *scale, y-1 *scale, c);
        cubeIt(x          , y-1 *scale, c);
        cubeIt(x +1 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x +2 *scale, y         , c);
        cubeIt(x -2 *scale, y+1 *scale, c);
        cubeIt(x +2 *scale, y+1 *scale, c);
        cubeIt(x -2 *scale, y+2 *scale, c);
        cubeIt(x +2 *scale, y+2 *scale, c);
        cubeIt(x -2 *scale, y+3 *scale, c);
        cubeIt(x +2 *scale, y+3 *scale, c);
        cubeIt(x -1 *scale, y+4 *scale, c);
        cubeIt(x          , y+4 *scale, c);
        cubeIt(x +1 *scale, y+4 *scale, c);
    }else if(letter == 'v'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         I---I  y-1
         I---I  y
         I---I  y+1
         I---I  y+2
         -I-I-  y+3
         --I--  y+4
         */
        cubeIt(x -2 *scale, y-1 *scale, c);
        cubeIt(x +2 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x +2 *scale, y         , c);
        cubeIt(x -2 *scale, y+1 *scale, c);
        cubeIt(x +2 *scale, y+1 *scale, c);
        cubeIt(x -2 *scale, y+2 *scale, c);
        cubeIt(x +2 *scale, y+2 *scale, c);
        cubeIt(x -1 *scale, y+3 *scale, c);
        cubeIt(x +1 *scale, y+3 *scale, c);
        cubeIt(x          , y+4 *scale, c);
    }else if(letter == 'I'){
        /*
         IIIII  y-4
         --I--  y-3
         --I--  y-2
         --I--  y-1
         --I--  y
         --I--  y+1
         --I--  y+2
         --I--  y+3
         IIIII  y+4
         */
        cubeIt(x -2 *scale, y-4 *scale, c);
        cubeIt(x -1 *scale, y-4 *scale, c);
        cubeIt(x          , y-4 *scale, c);
        cubeIt(x +1 *scale, y-4 *scale, c);
        cubeIt(x +2 *scale, y-4 *scale, c);
        cubeIt(x          , y-3 *scale, c);
        cubeIt(x          , y-2 *scale, c);
        cubeIt(x          , y-1 *scale, c);
        cubeIt(x          , y         , c);
        cubeIt(x          , y+1 *scale, c);
        cubeIt(x          , y+2 *scale, c);
        cubeIt(x          , y+3 *scale, c);
        cubeIt(x -2 *scale, y+4 *scale, c);
        cubeIt(x -1 *scale, y+4 *scale, c);
        cubeIt(x          , y+4 *scale, c);
        cubeIt(x +1 *scale, y+4 *scale, c);
        cubeIt(x +2 *scale, y+4 *scale, c);
    }else if(letter == 'n'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         I----  y-1
         I-III  y
         II--I  y+1
         I---I  y+2
         I---I  y+3
         I---I  y+4
         */
        cubeIt(x -2 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x          , y         , c);
        cubeIt(x +1 *scale, y         , c);
        cubeIt(x +2 *scale, y         , c);
        cubeIt(x -2 *scale, y+1 *scale, c);
        cubeIt(x -1 *scale, y+1 *scale, c);
        cubeIt(x +2 *scale, y+1 *scale, c);
        cubeIt(x -2 *scale, y+2 *scale, c);
        cubeIt(x +2 *scale, y+2 *scale, c);
        cubeIt(x -2 *scale, y+3 *scale, c);
        cubeIt(x +2 *scale, y+3 *scale, c);
        cubeIt(x -2 *scale, y+4 *scale, c);
        cubeIt(x +2 *scale, y+4 *scale, c);
    }else if(letter == 'p'){
        /*
         I----  y-4
         IIII-  y-3
         I---I  y-2
         I---I  y-1
         I---I  y
         IIII-  y+1
         I----  y+2
         I----  y+3
         */
        cubeIt(x -2*scale, y-4 *scale, c);
        cubeIt(x -2*scale, y-3 *scale, c);
        cubeIt(x -1*scale, y-3 *scale, c);
        cubeIt(x         , y-3 *scale, c);
        cubeIt(x +1*scale, y-3 *scale, c);
        cubeIt(x -2*scale, y-2 *scale, c);
        cubeIt(x +2*scale, y-2 *scale, c);
        cubeIt(x -2*scale, y-1 *scale, c);
        cubeIt(x +2*scale, y-1 *scale, c);
        cubeIt(x -2*scale, y         , c);
        cubeIt(x +2*scale, y         , c);
        cubeIt(x -2*scale, y+1 *scale, c);
        cubeIt(x -1*scale, y+1 *scale, c);
        cubeIt(x         , y+1 *scale, c);
        cubeIt(x +1*scale, y+1 *scale, c);
        cubeIt(x -2*scale, y+2 *scale, c);
        cubeIt(x -2*scale, y+3 *scale, c);
    }else if(letter == 'u'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         I---I  y-1
         I---I  y
         I---I  y+1
         I---I  y+2
         I--II  y+3
         -II-I  y+4
         */
        cubeIt(x -2*scale, y-1 *scale, c);
        cubeIt(x +2*scale, y-1 *scale, c);
        cubeIt(x -2*scale, y         , c);
        cubeIt(x +2*scale, y         , c);
        cubeIt(x -2*scale, y+1 *scale, c);
        cubeIt(x +2*scale, y+1 *scale, c);
        cubeIt(x -2*scale, y+2 *scale, c);
        cubeIt(x +2*scale, y+2 *scale, c);
        cubeIt(x -2*scale, y+3 *scale, c);
        cubeIt(x +1*scale, y+3 *scale, c);
        cubeIt(x +2*scale, y+3 *scale, c);
        cubeIt(x -1*scale, y+4 *scale, c);
        cubeIt(x         , y+4 *scale, c);
        cubeIt(x +2*scale, y+4 *scale, c);
    }else if(letter == 't'){
        /*
         -I---  y-4
         -I---  y-3
         -I---  y-2
         IIII-  y-1
         -I---  y
         -I---  y+1
         -I---  y+2
         -I--I  y+3
         -III-  y+4
         */
        cubeIt(x -1*scale, y-4 *scale, c);
        cubeIt(x -1*scale, y-3 *scale, c);
        cubeIt(x -1*scale, y-2 *scale, c);
        cubeIt(x -2*scale, y-1 *scale, c);
        cubeIt(x -1*scale, y-1 *scale, c);
        cubeIt(x         , y-1 *scale, c);
        cubeIt(x +1*scale, y-1 *scale, c);
        cubeIt(x -1*scale, y         , c);
        cubeIt(x -1*scale, y+1 *scale, c);
        cubeIt(x -1*scale, y+2 *scale, c);
        cubeIt(x -1*scale, y+3 *scale, c);
        cubeIt(x +2*scale, y+3 *scale, c);
        cubeIt(x -1*scale, y+4 *scale, c);
        cubeIt(x         , y+4 *scale, c);
        cubeIt(x +1*scale, y+4 *scale, c);
    }else if(letter == 's'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         -III-  y-1
         I---I  y
         -II--  y+1
         ---II  y+2
         I---I  y+3
         -III-  y+4
         */
        cubeIt(x -1*scale, y-1 *scale, c);
        cubeIt(x         , y-1 *scale, c);
        cubeIt(x +1*scale, y-1 *scale, c);
        cubeIt(x -2*scale, y         , c);
        cubeIt(x +2*scale, y         , c);
        cubeIt(x -1*scale, y+1 *scale, c);
        cubeIt(x         , y+1 *scale, c);
        cubeIt(x +1*scale, y+2 *scale, c);
        cubeIt(x +2*scale, y+2 *scale, c);
        cubeIt(x -2*scale, y+3 *scale, c);
        cubeIt(x +2*scale, y+3 *scale, c);
        cubeIt(x -1*scale, y+4 *scale, c);
        cubeIt(x         , y+4 *scale, c);
        cubeIt(x +1*scale, y+4 *scale, c);
    }else if(letter == 'r'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         I-II-  y-1
         II--I  y
         I----  y+1
         I----  y+2
         I----  y+3
         I----  y+4
         */
        cubeIt(x -2*scale, y-1 *scale, c);
        cubeIt(x         , y-1 *scale, c);
        cubeIt(x +1*scale, y-1 *scale, c);
        cubeIt(x -2*scale, y         , c);
        cubeIt(x -1*scale, y         , c);
        cubeIt(x +2*scale, y         , c);
        cubeIt(x -2*scale, y+1 *scale, c);
        cubeIt(x -2*scale, y+2 *scale, c);
        cubeIt(x -2*scale, y+3 *scale, c);
        cubeIt(x -2*scale, y+4 *scale, c);
    }else if(letter == 'd'){
        /*
         ----I  y-4
         ----I  y-3
         ----I  y-2
         -IIII  y-1
         I---I  y
         I---I  y+1
         I---I  y+2
         I--II  y+3
         -II-I  y+4
         */
        cubeIt(x +2 *scale, y-4 *scale, c);
        cubeIt(x +2 *scale, y-3 *scale, c);
        cubeIt(x +2 *scale, y-2 *scale, c);
        cubeIt(x -1 *scale, y-1 *scale, c);
        cubeIt(x          , y-1 *scale, c);
        cubeIt(x +1 *scale, y-1 *scale, c);
        cubeIt(x +2 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x +2 *scale, y         , c);
        cubeIt(x -2 *scale, y+1 *scale, c);
        cubeIt(x +2 *scale, y+1 *scale, c);
        cubeIt(x -2 *scale, y+2 *scale, c);
        cubeIt(x +2 *scale, y+2 *scale, c);
        cubeIt(x -2 *scale, y+3 *scale, c);
        cubeIt(x +1 *scale, y+3 *scale, c);
        cubeIt(x +2 *scale, y+3 *scale, c);
        cubeIt(x -1 *scale, y+4 *scale, c);
        cubeIt(x          , y+4 *scale, c);
        cubeIt(x +2 *scale, y+4 *scale, c);
    }else if(letter == '-'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         -----  y-1
         IIIII  y
         -----  y+1
         -----  y+2
         -----  y+3
         -----  y+4
         */
        cubeIt(x -2 *scale, y, c);
        cubeIt(x -1 *scale, y, c);
        cubeIt(x          , y, c);
        cubeIt(x +1 *scale, y, c);
        cubeIt(x +2 *scale, y, c);
    }else if(letter == 'B'){
        /*
         IIII-  y-4
         I---I  y-3
         I---I  y-2
         I---I  y-1
         IIII-  y
         I---I  y+1
         I---I  y+2
         I---I  y+3
         IIII-  y+4
         */
        cubeIt(x -2 *scale, y-4 *scale, c);
        cubeIt(x -1 *scale, y-4 *scale, c);
        cubeIt(x          , y-4 *scale, c);
        cubeIt(x +1 *scale, y-4 *scale, c);
        cubeIt(x -2 *scale, y-3 *scale, c);
        cubeIt(x +2 *scale, y-3 *scale, c);
        cubeIt(x -2 *scale, y-2 *scale, c);
        cubeIt(x +2 *scale, y-2 *scale, c);
        cubeIt(x -2 *scale, y-1 *scale, c);
        cubeIt(x +2 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x -1 *scale, y         , c);
        cubeIt(x          , y         , c);
        cubeIt(x +1 *scale, y         , c);
        cubeIt(x -2 *scale, y+1 *scale, c);
        cubeIt(x +2 *scale, y+1 *scale, c);
        cubeIt(x -2 *scale, y+2 *scale, c);
        cubeIt(x +2 *scale, y+2 *scale, c);
        cubeIt(x -2 *scale, y+3 *scale, c);
        cubeIt(x +2 *scale, y+3 *scale, c);
        cubeIt(x -2 *scale, y+4 *scale, c);
        cubeIt(x -1 *scale, y+4 *scale, c);
        cubeIt(x          , y+4 *scale, c);
        cubeIt(x +1 *scale, y+4 *scale, c);
    }else if(letter == 'l'){
        /*
         -II--  y-4
         --I--  y-3
         --I--  y-2
         --I--  y-1
         --I--  y
         --I--  y+1
         --I--  y+2
         --I--  y+3
         -III-  y+4
         */
        cubeIt(x -1 *scale, y-4 *scale, c);
        cubeIt(x          , y-4 *scale, c);
        cubeIt(x          , y-3 *scale, c);
        cubeIt(x          , y-2 *scale, c);
        cubeIt(x          , y-1 *scale, c);
        cubeIt(x          , y         , c);
        cubeIt(x          , y+1 *scale, c);
        cubeIt(x          , y+2 *scale, c);
        cubeIt(x          , y+3 *scale, c);
        cubeIt(x -1 *scale, y+4 *scale, c);
        cubeIt(x          , y+4 *scale, c);
        cubeIt(x +1 *scale, y+4 *scale, c);
    }else if(letter == 'a'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         -III-  y-1
         I---I  y
         -IIII  y+1
         I---I  y+2
         I--II  y+3
         -II-I  y+4
         */
        cubeIt(x -1 *scale, y-1 *scale, c);
        cubeIt(x          , y-1 *scale, c);
        cubeIt(x +1 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x +2 *scale, y         , c);
        cubeIt(x -1 *scale, y+1 *scale, c);
        cubeIt(x          , y+1 *scale, c);
        cubeIt(x +1 *scale, y+1 *scale, c);
        cubeIt(x +2 *scale, y+1 *scale, c);
        cubeIt(x -2 *scale, y+2 *scale, c);
        cubeIt(x +2 *scale, y+2 *scale, c);
        cubeIt(x -2 *scale, y+3 *scale, c);
        cubeIt(x +1 *scale, y+3 *scale, c);
        cubeIt(x +2 *scale, y+3 *scale, c);
        cubeIt(x -1 *scale, y+4 *scale, c);
        cubeIt(x          , y+4 *scale, c);
        cubeIt(x +2 *scale, y+4 *scale, c);
    }else if(letter == 'c'){
        /*
         -----  y-4
         -----  y-3
         -----  y-2
         -III-  y-1
         I---I  y
         I----  y+1
         I----  y+2
         I---I  y+3
         -III-  y+4
         */
        cubeIt(x -1 *scale, y-1 *scale, c);
        cubeIt(x          , y-1 *scale, c);
        cubeIt(x +1 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x +2 *scale, y         , c);
        cubeIt(x -2 *scale, y+1 *scale, c);
        cubeIt(x -2 *scale, y+2 *scale, c);
        cubeIt(x -2 *scale, y+3 *scale, c);
        cubeIt(x +2 *scale, y+3 *scale, c);
        cubeIt(x -1 *scale, y+4 *scale, c);
        cubeIt(x          , y+4 *scale, c);
        cubeIt(x +1 *scale, y+4 *scale, c);
    }else if(letter == 'k'){
        /*
         I----  y-4
         I----  y-3
         I----  y-2
         I---I  y-1
         I--I-  y
         IIII-  y+1
         I---I  y+2
         I---I  y+3
         I---I  y+4
         */
        cubeIt(x -2 *scale, y-4 *scale, c);
        cubeIt(x -2 *scale, y-3 *scale, c);
        cubeIt(x -2 *scale, y-2 *scale, c);
        cubeIt(x -2 *scale, y-1 *scale, c);
        cubeIt(x +2 *scale, y-1 *scale, c);
        cubeIt(x -2 *scale, y         , c);
        cubeIt(x +1 *scale, y         , c);
        cubeIt(x -2 *scale, y+1 *scale, c);
        cubeIt(x -1 *scale, y+1 *scale, c);
        cubeIt(x          , y+1 *scale, c);
        cubeIt(x +1 *scale, y+1 *scale, c);
        cubeIt(x -2 *scale, y+2 *scale, c);
        cubeIt(x +2 *scale, y+2 *scale, c);
        cubeIt(x -2 *scale, y+3 *scale, c);
        cubeIt(x +2 *scale, y+3 *scale, c);
        cubeIt(x -2 *scale, y+4 *scale, c);
        cubeIt(x +2 *scale, y+4 *scale, c);
    }else if(letter == 'T'){
        /*
         IIIII  y-4
         I-I-I  y-3
         --I--  y-2
         --I--  y-1
         --I--  y
         --I--  y+1
         --I--  y+2
         --I--  y+3
         --I--  y+4
         */
        cubeIt(x -2 *scale, y-4 *scale, c);
        cubeIt(x -1 *scale, y-4 *scale, c);
        cubeIt(x          , y-4 *scale, c);
        cubeIt(x +1 *scale, y-4 *scale, c);
        cubeIt(x +2 *scale, y-4 *scale, c);
        //cubeIt(x -2 *scale, y-3 *scale, c);
        cubeIt(x          , y-3 *scale, c);
        //cubeIt(x +2 *scale, y-3 *scale, c);
        cubeIt(x          , y-2 *scale, c);
        cubeIt(x          , y-1 *scale, c);
        cubeIt(x          , y         , c);
        cubeIt(x          , y+1 *scale, c);
        cubeIt(x          , y+2 *scale, c);
        cubeIt(x          , y+3 *scale, c);
        cubeIt(x          , y+4 *scale, c);
    }
    
}

//Xiangyu added drawNumber in 11/20/2024
//assume number is no more than 4 digits
template <typename T>
void RedBlackTreeDisplayer<T>::drawNumber(int x, int y, int value){
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

            //Look me: Since digit width is 5 pixels, choosing 7 pixels as the distance between two digits
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

template class RedBlackTreeDisplayer<int>;
template class RedBlackTreeDisplayer<double>;
