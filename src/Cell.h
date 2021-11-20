//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_CELL_H
#define CANDYCRUSH_CELL_H
#include "Item.h"

class Cell {
private:
    Position position;
    Item *item;
    int frozen=0;
public:
    Cell(Position pos);
    void clear(){ delete item;}
    void setPosition(Position new_position ){position=new_position;}
    Position getPosition()const{return position;}
};


#endif //CANDYCRUSH_CELL_H
