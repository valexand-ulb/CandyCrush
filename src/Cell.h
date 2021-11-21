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
    //Constructeurs
    Cell(Position pos);

    // Méthodes
    void clear(){ delete item;}
    void setPosition(Position new_position ){position=new_position;}
    Item *getItem()const{return item;}
    Position getPosition()const{return position;}
    // surcharge
    friend std::ostream& operator<<(std::ostream& flux, const Cell& c);
};


#endif //CANDYCRUSH_CELL_H
