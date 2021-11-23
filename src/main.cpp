//
// Created by alex on 20/11/21.
//

#include "Matrice.h"
#include "Position.h"

int main(){
    Matrice m{3};
    std::cout<< m << std::endl;
    m.clearCase({0,0});
    std::cout<< m << std::endl;
    return 0;
}