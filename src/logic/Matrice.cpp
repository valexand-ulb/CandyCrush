//
// Created by alex on 20/11/21.
//
#include "Matrice.h"
//Constructeurs
Matrice::Matrice(int size):size(size){
    for (int i=0; i<size; i++){
        mat.push_back({});
        for (int j=0; j<size; j++){
            Cell c{Position{i,j}};
            mat[i].push_back(c);
        }
    }
}

Matrice::Matrice(std::string file_path, int size): size(size){
    std::fstream file;
    file.open(file_path,std::ios::in);
    if (file.is_open()){
        std::string line;
        int i=0;
        while (getline(file, line)){
            i+=1;
        }
        file.close();
    }

}

int Matrice::getCellColor(Position p) const {
    return (0<= p.x && p.x < size && 0<= p.y && p.y < size) ?
    mat[p.x][p.y].getCandyColor() : -1;
}
//Méthodes
bool Matrice::isCellEmpty(Position p) {
    return mat[p.x][p.y].isEmpty();
}

bool Matrice::isAdjacent(Position p1, Position p2){
    return Position{p1.x+1, p1.y} == p2
        || Position{p1.x-1, p1.y} == p2
        || Position{p1.x, p1.y+1} == p2
        || Position{p1.x, p1.y-1} == p2;
}

bool Matrice::isSideSwapable(Position p1, Position p2) {
    // pour click1
    return (getCellColor(p1) == getCellColor({p1.x, p1.y+2}) && getCellColor(p1) == getCellColor({p1.x, p1.y+3}))
    || (getCellColor(p1) == getCellColor({p1.x-1, p1.y+1}) && getCellColor(p1) == getCellColor({p1.x-2, p1.y+1}))
    || (getCellColor(p1) == getCellColor({p1.x+1, p1.y+1}) && getCellColor(p1) == getCellColor({p1.x+2, p1.y+1}))
    // pour click2
    || (getCellColor(p2) == getCellColor({p1.x, p1.y-1}) && getCellColor(p2) == getCellColor({p1.x, p1.y-2}))
    || (getCellColor(p2) == getCellColor({p1.x-1, p1.y}) && getCellColor(p2) == getCellColor({p1.x-2, p1.y}))
    || (getCellColor(p2) == getCellColor({p1.x+1, p1.y}) && getCellColor(p2) == getCellColor({p1.x+2, p1.y}));

}

void Matrice::clearCase(Position p) {
    mat[p.x][p.y].clear();
    emptyCells.push_back(p);
    fillVoid();
}

void Matrice::swapCases(Position p1, Position p2) {
    // echange le contenu des cases en p1 et p2
    Cell& c1= mat[p1.x][p1.y];
    Cell& c2= mat[p2.x][p2.y];
    if (!c1.isEmpty() && !c2.isEmpty()){
        c1.swap(c2); // si les deux cellules sont pas vide, échange les sans mettre a jour emptyCells
    }else if(c1.isEmpty() && !c2.isEmpty()){
        c1.swap(c2); // echange les cellules
        emptyCells.push_back(p2); //p1 est une cellule vide et son contenu est echangé en p2, ajoute p2 dans emptyCells
    }/*else if(!c1.isEmpty() && c2.isEmpty()){
        c1.swap(c2);
        emptyCells.push(p1);
    }*/
    updateEmptyCells();
}

void Matrice::updateEmptyCells() {
    for (unsigned long int i=0; i<emptyCells.size(); i++){
        if (!isCellEmpty(emptyCells[i])){
            emptyCells.erase(emptyCells.begin()+i);
        }
    }
}

void Matrice::fillVoid() {
    Position p;
    while (!emptyCells.empty()){
        p = emptyCells.back();
        emptyCells.pop_back();
        if (p.x !=0){
            swapCases(p, {p.x-1, p.y});
        }else{
            setCell(p);
        }
        std::cout << *this << std::endl;
    }
}

void Matrice::updateOnClick(Position p1) {
    if (p1.x != -1) { // si la cellule est sur le tableau
        click1.x<0 ? click1=p1 : click2=p1;
    }
    if (!(click1.x<0 or click2.x<0)){
        if (isAdjacent(click1, click2)&&isSideSwapable(click1, click2))swapCases(click1, click2);
        //reset les position
        click1.setPos(-1,-1);
        click2.setPos(-1,-1);
        std::cout << *this << std::endl;
    }
}

//Surcharge
std::ostream& operator<<(std::ostream &flux,const Matrice& M) {
    for (int i=0; i<M.getSize(); i++){
        for (int j=0;j<M.getSize();j++){
            flux << M.getCell(Position{i,j})<< ' ';
        }
        flux << std::endl;
    }
    return flux;
}