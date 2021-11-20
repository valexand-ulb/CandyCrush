//
// Created by alex on 20/11/21.
//

#include "Cell.h"
#include <random>
#include <iostream>

Cell::Cell(Position pos):position(pos){
    std::cout << "Construction de cell (" << pos.getPosX() << ',' << pos.getPosY() << ")" << endl;
    item = new Candy{pos, rand()%5};
}