//
// Created by alex on 20/11/21.
//

#include "Cell.h"
Cell::Cell(Position pos):position(pos){
    pItem->setPosition(pos);
    empty=true;
}

Cell::Cell(const Cell &other): position(other.position), pItem(other.pItem) {
}

void Cell::swap(Cell &other) {
}

std::ostream& operator<<(std::ostream& flux, const Cell& c){
    c.getItem()!= nullptr ? flux << *c.getItem() : flux << '.';
    return flux;
}