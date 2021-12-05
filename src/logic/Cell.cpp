//
// Created by alex on 20/11/21.
//

#include "Cell.h"
Cell::Cell(Position pos, int i):position(pos) {
    if (i!=-1) pItem=std::make_shared<Candy>(i);
    //std::cout << p.x << ',' << p.y << std::endl;
}

Cell::Cell(const Cell &other): position(other.position), pItem(other.pItem), empty(other.empty) {
}

Cell::Cell(Cell &&other): position(other.position), pItem(other.pItem), empty(other.empty) {
    other.pItem.reset();
}

void Cell::clear() {
    pItem.reset();
    empty = true;
    pItem = nullptr;
}

void Cell::swap(Cell& other) {
    Cell temp(*this);
    *this=std::move(other);
    other=std::move(temp);
}

void Cell::draw() {
}

Cell &Cell::operator=(const Cell& other) {
    position=other.position;
    pItem=other.pItem;
    empty=other.empty;
    return *this;
}

Cell &Cell::operator=(Cell&& other) {
    position=other.position;
    pItem=other.pItem;
    empty=other.empty;
    other.pItem.reset();
    return *this;
}

std::ostream& operator<<(std::ostream& flux, const Cell& c){
    !c.isEmpty()? flux << c.getItem() : flux << '.';
    return flux;
}