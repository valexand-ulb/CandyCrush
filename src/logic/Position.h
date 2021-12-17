//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_POSITION_H
#define CANDYCRUSH_POSITION_H
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

class Position {
private:
    int x, y;
public:
    Position(int x=-1, int y=-1):x(x),y(y){}
    int getPosX()const{return x;}
    int getPosY()const{return y;}
    void setPos(int new_x, int new_y){ x=new_x;y=new_y;}
    //surcharge
};


#endif //CANDYCRUSH_POSITION_H
