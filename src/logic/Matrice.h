//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_MATRICE_H
#define CANDYCRUSH_MATRICE_H
# include <vector>
#include "Cell.h"
#include "Position.h"

class Matrice {
private:
    const int size;
    Position click1,click2;
    std::vector<std::vector<Cell>> mat;
    std::vector<Position> emptyCells;
public:
    //constructeurs
    Matrice(int size);
    Matrice(std::string file_path, int size);
    //getter setter:
    int getSize()const{return size;}
    Cell getCell(Position p)const{ return mat[p.getPosX()][p.getPosY()];}
    void setCell(Position p, int color=-1){mat[p.getPosX()][p.getPosY()].setItem(color);}
    int getCellColor(Position p)const;
    //méthodes
    bool isCellEmpty(Position p);
    bool isAdjacent(Position p1, Position p2);
    bool isSideSwapable(Position p1, Position p2);
    void clearCase(Position p);
    void swapCases(Position p1, Position p2);
    void fillVoid();
    void updateEmptyCells();
    void updateOnClick(Position p1);
    //surcharge
    friend std::ostream& operator<<(std::ostream& flux,const Matrice &m);
};


#endif //CANDYCRUSH_MATRICE_H
