//
// Created by alex on 20/11/21.
//

#include "logic/Matrice.h"


int main(){
    Matrice m{3};

    std::cout<< m << std::endl;

    std::cout<< "Inversion (0,0) <-> (2,2): " << std::endl;
    m.swapCases({0,0},{2,2});
    std::cout<< m << std::endl;

    std::cout<< "Supression (1,1): " << std::endl;
    m.clearCase({1,1});
    std::cout<< "Supression (0,0): " << std::endl;
    m.clearCase({0,0});
    std::cout<< m << std::endl;
    std::cout<< "Inversion (1,1) <-> (1,2): " << std::endl;
    m.swapCases({1,1},{1,2});
    std::cout << m << std::endl;
    std::cout<< "Remplissage: " << std::endl;
    m.fillVoid();
    std::cout << m << std::endl;


    return 0;
}