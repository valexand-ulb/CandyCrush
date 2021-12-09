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
            for (int j=0; j<size; j++){
                if (line.c_str()){
                    std::cout << "oui" << std::endl;
                }

            }
        }
        file.close();
        i+=1;
    }

}

//Méthodes
bool Matrice::isCellEmpty(Position p) {
    return mat[p.getPosX()][p.getPosY()].isEmpty();
}

void Matrice::clearCase(Position p) {
    mat[p.getPosX()][p.getPosY()].clear();
    emptyCells.push_back(p);
}

void Matrice::swapCases(Position p1, Position p2) {
    // echange le contenu des cases en p1 et p2
    Cell& c1= mat[p1.getPosX()][p1.getPosY()];
    Cell& c2= mat[p2.getPosX()][p2.getPosY()];
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
        if (p.getPosX() !=0){
            swapCases(p, {p.getPosX()-1, p.getPosY()});
        }else{
            setCell(p);
        }
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

