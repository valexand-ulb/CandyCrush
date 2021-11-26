//
// Created by alex on 20/11/21.
//
#include "Matrice.h"
Matrice::Matrice(int size):size(size){
    for (int i=0; i<size; i++){
        mat.push_back({});
        for (int j=0; j<size; j++){
            Cell c{Position{i,j}};
            mat[i].push_back(c);
        }
    }
}

void Matrice::clearCase(Position p) {
    getPCell(p)->clear();
}


void Matrice::swap(Position p1, Position p2) {
    Cell* c1= getPCell(p1);
    Cell* c2= getPCell(p2);
    c1->swap(c2);
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

