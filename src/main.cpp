//
// Created by alex on 20/11/21.
//

//#include "logic/Matrice.h"
#include "gui/Mainwindow.h"


int main(int argc, char *argv[]){
    /*
    Matrice m{3};

    std::cout<< m << std::endl;

    std::cout<< "Inversion (0,0) <-> (2,2): " << std::endl;
    m.swapCases({0,0},{2,2});
    std::cout<< m << std::endl;

    std::cout<< "Supression (1,1): " << std::endl;
    m.clearCase({1,1});
    std::cout<< "Supression (0,0): " << std::endl;
    m.clearCase({0,0});
    std::cout<< m << std::endl;
    std::cout<< "Inversion (1,1) <-> (1,2): " << std::endl;
    m.swapCases({1,1},{1,2});
    std::cout << m << std::endl;
    std::cout<< "Remplissage: " << std::endl;
    m.fillVoid();
    std::cout<< "Supression (2,0): " << std::endl;
    m.clearCase({2,0});
    m.fillVoid();
    std::cout << m << std::endl;
    */
    //Matrice m{"mat1.txt",3};
    auto mat=std::make_shared<Matrice>(10);
    MainWindow window{mat};
    window.show(argc, argv);
    return Fl::run();
}