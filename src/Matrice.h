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
    Matrice(int size);
};


#endif //CANDYCRUSH_MATRICE_H
