//
// Created by alex on 20/11/21.
//

#include "Cell.h"
Cell::Cell(Position pos):position(pos){
    item = new Candy{pos, rand()%5};
    empty=true;
}

std::ostream& operator<<(std::ostream& flux, const Cell& c){
    flux << *c.getItem();
    return flux;
}