//
// Created by alex on 20/11/21.
//

#include "Matrice.h"
#include "Position.h"

int main(){
    Matrice m{10};
    std::cout<< m << std::endl;
    m.swap({0,0},{9,9});
    std::cout<< m << std::endl;


    return 0;
}