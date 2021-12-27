//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_MATRICE_H
#define CANDYCRUSH_MATRICE_H
#include <vector>
#include <tuple>
#include "Cell.h"


class Matrice {
private:
    const int size;
    Position click1,click2;
    std::vector<std::vector<Cell>> mat;
    std::vector<Position> emptyCells;
    struct verifier{
        const std::vector<Position> direction={{0,1},{0,-1},{-1,0},{1,0}};
        const std::vector<std::tuple<Position,Position>> coord1={
                {{0,2},{0,3}},{{1,1},{2,1}},
                {{-1,1},{-2,1}},{{-1,1},{1,1}}};
        const std::vector<std::tuple<Position,Position>> coord2={
                {{0,-1},{0,-2}},{{1,0},{2,0}},
                {{-1,0},{-2,0}},{{-1,0},{1,0}}
        };
    };
public:
    //constructeurs
    Matrice(int size);
    Matrice(std::string file_path, int size);
    //getter setter:
    int getSize()const{return size;}
    Cell getCell(Position p)const{ return mat[p.x][p.y];}
    void setCell(Position p, int color=-1){mat[p.x][p.y].setItem(color);}
    int getCellColor(Position p)const;
    //méthodes
    bool isCellEmpty(Position p)const;
    bool isAdjacent(Position p1, Position p2)const;
    bool isSwapable(Position p1, Position p2)const;
    void clearCase(Position p);
    void swapCases(Position p1, Position p2);
    void fillVoid();
    void updateEmptyCells();
    void updateOnClick(Position p1);
    //surcharge
    friend std::ostream& operator<<(std::ostream& flux,const Matrice &m);
};


#endif //CANDYCRUSH_MATRICE_H
