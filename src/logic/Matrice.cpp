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
bool Matrice::isCellEmpty(Position p) const{
    return mat[p.x][p.y].isEmpty();
}

bool Matrice::isAdjacent(Position p1, Position p2)const{
    return Position{p1.x+1, p1.y} == p2
        || Position{p1.x-1, p1.y} == p2
        || Position{p1.x, p1.y+1} == p2
        || Position{p1.x, p1.y-1} == p2;
}

bool Matrice::isSwapable(Position p1, Position p2) const{
    Position dir;
    bool swapable= false;
    for (auto &p:v.direction){
        if (p2-p1 == p) dir = p;
    }
    for (auto &t:v.coord1){
        if (dir==Position{0,1}) {// swap vers droite
            if (
                getCellColor(p1) == getCellColor({std::get<0>(t).x + p1.x, std::get<0>(t).y + p1.y}) &&
                getCellColor(p1) == getCellColor({std::get<1>(t).x + p1.x, std::get<1>(t).y + p1.y}))
                return 1;
        }else if (dir==Position{0,-1}){// swap vers gauche
            if (
                getCellColor(p1) == getCellColor({std::get<0>(t).x + p1.x, -(std::get<0>(t).y) + p1.y}) &&
                getCellColor(p1) == getCellColor({std::get<1>(t).x + p1.x, -(std::get<1>(t).y) + p1.y}))
                return 1;
        }else if (dir==Position{1,0}){// swap vers bas
            if (
                getCellColor(p1) == getCellColor({std::get<0>(t).y + p1.x,std::get<0>(t).x + p1.y}) &&
                getCellColor(p1) == getCellColor({std::get<1>(t).y + p1.x,std::get<1>(t).x + p1.y}))
                return 1;
        }else{// swap vers haut
            if (
            getCellColor(p1) == getCellColor({-(std::get<0>(t).y) + p1.x,std::get<0>(t).x + p1.y}) &&
            getCellColor(p1) == getCellColor({-(std::get<1>(t).y) + p1.x,std::get<1>(t).x + p1.y}))
            return 1;
        }
    }
    for (auto &t:v.coord2){
        if (dir==Position{0,1}) {// swap vers droite
            if (
                getCellColor(p2) == getCellColor({std::get<0>(t).x + p1.x, std::get<0>(t).y + p1.y}) &&
                getCellColor(p2) == getCellColor({std::get<1>(t).x + p1.x, std::get<1>(t).y + p1.y}))
                return 1;
        }else if (dir==Position{0,-1}){// swap vers gauche
            if (
                getCellColor(p2) == getCellColor({std::get<0>(t).x + p1.x, -(std::get<0>(t).y) + p1.y}) &&
                getCellColor(p2) == getCellColor({std::get<1>(t).x + p1.x, -(std::get<1>(t).y) + p1.y}))
                return 1;
        }else if (dir==Position{1,0}){// swap vers bas
            if (
                getCellColor(p2) == getCellColor({std::get<0>(t).y + p1.x,std::get<0>(t).x + p1.y}) &&
                getCellColor(p2) == getCellColor({std::get<1>(t).y + p1.x,std::get<1>(t).x + p1.y}))
                return 1;
        }else{// swap vers haut
            if (
                getCellColor(p2) == getCellColor({-(std::get<0>(t).y) + p1.x,std::get<0>(t).x + p1.y}) &&
                getCellColor(p2) == getCellColor({-(std::get<1>(t).y) + p1.x,std::get<1>(t).x + p1.y}))
                return 1;
        }
    }
    return swapable;
}
bool Matrice::isInDelete(Position p) const {
    for (auto &pos:toDelete){
        if(pos==p) return 1;
    }
    return 0;
}


void Matrice::clearCase(Position p) {
    std::cout << "mort de " << p << std::endl;
    mat[p.x][p.y].clear();
    emptyCells.push_back(p);
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
    }else if(!c1.isEmpty() && c2.isEmpty()){
        c1.swap(c2);
        emptyCells.push_back(p1);
    }else if (c1.isEmpty() && c2.isEmpty()){
        emptyCells.push_back(p1);
        emptyCells.push_back(p2);
    }
    updateEmptyCells();
}

void Matrice::updateEmptyCells() {
    for (unsigned int i=0; i<emptyCells.size(); i++){
        if (!isCellEmpty(emptyCells[i])) emptyCells.erase(emptyCells.begin()+i);
    }
}

int Matrice::updateToDelete() {
    int num=0;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            std::vector<Position> temp1 = {Position{i,j}, Position {i,j-1}, Position {i,j+1}};
            std::vector<Position> temp2 = {Position{j,i}, Position {j-1,i}, Position {j+1,i}};
            bool same_color_hor=1;bool same_color_ver=1;
            for (unsigned int i=1; i<temp1.size(); i++){
                same_color_hor &= (getCellColor(temp1[0]) == getCellColor(temp1[i]));
                same_color_ver &= (getCellColor(temp2[0]) == getCellColor(temp2[i]));
            }
            if (same_color_hor){
                for (auto p:temp1){
                    toDelete.push_back(p);
                    num++;
                }
            }
            if (same_color_ver){
                for (auto p:temp2){
                    toDelete.push_back(p);
                    num++;
                }
            }
        }
    }
    return num;
}

void Matrice::updateOnClick(Position p1) {
    if (p1.x != -1) { // si la cellule est sur le tableau
        click1.x<0 ? click1=p1 : click2=p1;
    }
    if (!(click1.x<0 or click2.x<0)){
        if (isAdjacent(click1, click2) && isSwapable(click1,click2)){
            swapCases(click1, click2);
        }
        updateToDelete();
        while(toDelete.size()>0){
            clearCase(toDelete.back());
            toDelete.pop_back();
        }
        fillVoid();
        //reset les position
        click1.setPos(-1,-1);
        click2.setPos(-1,-1);
        std::cout << *this << std::endl;
    }
}

void Matrice::fillVoid() {
    Position p;
    for (auto &p1:emptyCells){
        std::cout << p1 << " ; ";
    }
    std::cout << std::endl;
    while (!emptyCells.empty()){
        p = emptyCells.back();
        emptyCells.pop_back();
        if (p.x !=0){
            std::cout << "swap de " << p << " et " << Position{p.x-1, p.y} << std::endl;
            swapCases(p, {p.x-1, p.y});
        }else{
            setCell(p);
        }
        std::cout << *this << std::endl;
    }
    for (auto &p1:emptyCells){
        std::cout << p1 << " ; ";
    }
    std::cout << std::endl;

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