//
// Created by alex on 20/11/21.
//

#include "logic/Matrice.h"


int main(){
    Matrice m{3};

    std::cout<< m << std::endl;

    std::cout<< "Inversion (0,0) <-> (2,2): " << std::endl;
    m.swap({0,0},{2,2});
    std::cout<< m << std::endl;

    std::cout<< "Supression (1,1): " << std::endl;
    m.clearCase({1,1});
    std::cout<< m << std::endl;
    std::cout << "Cellule {1,1} vide ? " <<m.getPCell({1,1})->isEmpty() << std::endl;
    std::cout<< "Inversion (1,1) <-> (1,2): " << std::endl;
    m.swap({1,1},{1,2});
    std::cout << m << std::endl;
    std::cout <<  "Cellule {1,2} vide ? " << m.getPCell({1,2})->isEmpty() << std::endl;

    return 0;
}