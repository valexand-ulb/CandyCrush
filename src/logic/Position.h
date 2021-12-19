//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_POSITION_H
#define CANDYCRUSH_POSITION_H
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

struct Position {
    int x, y;
    Position(int x=-1, int y=-1):x(x),y(y){}
    void setPos(int new_x, int new_y){ x=new_x;y=new_y;}

    //surcharge
    bool operator==(Position other){return x==other.x && y==other.y;}
};


#endif //CANDYCRUSH_POSITION_H
