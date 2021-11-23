//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_CELL_H
#define CANDYCRUSH_CELL_H
#include "Item.h"

class Cell {
private:
    Position position;
    Item *pItem=new Candy{rand()%6};
    bool empty= true;
    int frozen=0;
public:
    //Constructeurs
    Cell(Position pos);
    Cell(const Cell &other); //copie

    // getter / setters
    Item *getItem()const{return pItem;}
    void setItem(Item *new_item){pItem=new_item;}
    Position getPosition()const{return position;}
    void setPosition(Position new_pos){position=new_pos;}

    // Méthodes
    bool isEmpty()const{return empty;}
    void clear(){ delete pItem; empty= true; pItem= nullptr;}
    void swap(Cell *other);

    // surcharge
    friend std::ostream& operator<<(std::ostream& flux, const Cell& c);
};


#endif //CANDYCRUSH_CELL_H
