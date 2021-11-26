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

void Matrice::fillVoid() {
    for (int i = size - 1; i >= 0; i--)
        for (int j = size - 1; j >= 0; j--)
            if (mat[i][j].isEmpty()) {
                i != 0 ? swapCases({i, j}, {i - 1, j}) : setCell({i, j});
            }
}

void Matrice::clearCase(Position p) {
    mat[p.getPosX()][p.getPosY()].clear();
}

void Matrice::swapCases(Position p1, Position p2) {
    Cell& c1= mat[p1.getPosX()][p1.getPosY()];
    Cell& c2= mat[p2.getPosX()][p2.getPosY()];
    c1.swap(c2);
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

