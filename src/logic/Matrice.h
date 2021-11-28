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
    vector<Position> emptyCells;
public:
    //constructeurs
    Matrice(int size);
    Matrice(std::string file_path);
    //getter setter:
    int getSize()const{return size;}
    Cell getCell(Position p)const{ return mat[p.getPosX()][p.getPosY()];}
    void setCell(Position p){mat[p.getPosX()][p.getPosY()].setItem();}
    //méthodes
    bool isCellEmpty(Position p);
    void clearCase(Position p);
    void swapCases(Position p1, Position p2);
    void fillVoid();
    void updateEmptyCells();
    //surcharge
    friend std::ostream& operator<<(std::ostream& flux,const Matrice &m);
};


#endif //CANDYCRUSH_MATRICE_H
