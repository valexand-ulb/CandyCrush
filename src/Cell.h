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
    bool empty= true;
    int frozen=0;
public:
    //Constructeurs
    Cell(Position pos);
    // getter / setters
    bool isEmpty()const{return empty;}
    // Méthodes
    void clear(){ delete item; empty= true;}
    Item *getItem()const{return item;}
    Position getPosition()const{return position;}
    // surcharge
    friend std::ostream& operator<<(std::ostream& flux, const Cell& c);
};


#endif //CANDYCRUSH_CELL_H
