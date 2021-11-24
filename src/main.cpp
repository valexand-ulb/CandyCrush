//
// Created by alex on 20/11/21.
//

#include "Matrice.h"
#include "Position.h"

int main(){
    Matrice m{10};
    std::cout<< m << std::endl;
    m.swap({0,0},{9,9});
    m.clearCase({1,1});
    std::cout << m.getPCell({1,1})->isEmpty() << std::endl;
    m.swap({1,1},{1,2});
    std::cout << m.getPCell({1,2})->isEmpty() << std::endl;
    std::cout << m << std::endl;


    return 0;
}