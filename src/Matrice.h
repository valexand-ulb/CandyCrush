//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_MATRICE_H
#define CANDYCRUSH_MATRICE_H
# include <vector>
#include "Cell.h"
#include "Position.h"
using namespace std;

class Matrice {
private:
    const int size;
    vector<vector<Cell>> mat;
public:
    //constructeurs
    Matrice(int size);
    //getter setter:
    int getSize()const{return size;}
    //méthodes
    Cell getCell(Position p)const{return mat[p.getPosX()][p.getPosY()];}
    void clearCase(Position p);
    //surcharge
    friend std::ostream& operator<<(std::ostream& flux, const Matrice &m);
};


#endif //CANDYCRUSH_MATRICE_H
