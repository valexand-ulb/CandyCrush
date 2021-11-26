//
// Created by alex on 20/11/21.
//

#include "Cell.h"
Cell::Cell(Position pos):position(pos){
}

Cell::Cell(const Cell &other): position(other.position), pItem(other.pItem), empty(other.empty) {
}

Cell::Cell(const Cell &&other): position(other.position), pItem(other.pItem), empty(other.empty) {
    delete other.pItem;
}

void Cell::clear() {
    delete pItem;
    empty = true;
    pItem = nullptr;
}

void Cell::swap(Cell* other) {
    Cell temp(*this);
    *this=*other;
    *other=temp;
    /*
    position = other->position;
    pItem = other->pItem;
    empty = other->empty;

    other->position = temp.position;
    other->pItem = temp.pItem;
    other->empty = temp.empty;
    */
}

Cell &Cell::operator=(Cell other) {
    position=other.position;
    pItem=other.pItem;
    empty=other.empty;
    return *this;
}

std::ostream& operator<<(std::ostream& flux, const Cell& c){
    c.getItem()!= nullptr ? flux << *c.getItem() : flux << '.';
    return flux;
}