//
// Created by alex on 20/11/21.
//
#include "Matrice.h"
Matrice::Matrice(int size):size(size){
    for (int i=0; i<size; i++){
        mat.push_back({});
        for (int j=0; j<size; j++){
            mat[i].push_back(Cell{Position{i,j}});
        }
    }
}

std::ostream& operator<<(ostream &flux,const Matrice& M) {
    for (int i=0; i<M.getSize(); i++){
        for (int j=0;j<M.getSize();j++){
            flux << M.getCell(Position{i,j})<< ' ';
        }
        flux << endl;
    }
    return flux;
}

