//
// Created by alex on 20/11/21.
//

#include "Position.h"

std::ostream& operator<<(std::ostream &flux,const Position& p) {
    flux << p.x << ',' << p.y;
    return flux;
}