//
// Created by alex on 20/11/21.
//
#include "gui/Mainwindow.h"

int main(int argc, char *argv[]){
    auto mat=std::make_shared<Matrice>(9);
    MainWindow window{mat};
    window.show(argc, argv);
    return Fl::run();

}