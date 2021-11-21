//
// Created by alex on 20/11/21.
//

#include "Item.h"

std::ostream& operator<<(std::ostream& flux, const Item &i){
    flux << i.getColor();
    return flux;
}