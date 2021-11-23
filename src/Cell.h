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
    Cell(const Cell &other); //copie

    // getter / setters
    Item *getItem()const{return item;}
    void setItem(Item *new_item){item=new_item;}
    Position getPosition()const{return position;}
    void setPosition(Position new_pos){position=new_pos;}

    // Méthodes
    bool isEmpty()const{return empty;}
    void clear(){ delete item; empty= true;}

    // surcharge
    friend std::ostream& operator<<(std::ostream& flux, const Cell& c);
};


#endif //CANDYCRUSH_CELL_H
