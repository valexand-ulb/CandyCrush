//
// Created by alex on 20/11/21.
//
#include <iostream>
#include "Matrice.h"
Matrice::Matrice(int size):size(size){
    std::cout << "Construction de la matrice" << std::endl;
    for (int i=0; i<size; i++){
        mat.push_back({});
        for (int j=0; j<size; j++){
            mat[i].push_back(Cell{Position{i,j}});
        }
    }
}