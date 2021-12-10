//
// Created by alex on 12/1/21.
//

#include "Mainwindow.h"

MainWindow::MainWindow(std::shared_ptr <Matrice> mat):
Fl_Window(000, 000, windowWidth, windowHeight, "CandyCrush"), mat(mat) {
    Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
    resizable(this);
    int size = mat->getSize();
    for (int i=0; i< size; i++){
        for(int j=0; j<size; j++){
            // inversion i-j x-y pour correspondre a la matrice
            vect.push_back(std::make_shared<Rectangle>(Point{(j+1)*50,(i+1)*50}));
            vect.push_back(std::make_shared<Circle>(Point{(j+1)*50,(i+1)*50},mat->getCellColor({i,j})));
        }
    }
}

void MainWindow::draw() {
    Fl_Window::draw();
    for (auto &c:vect){
        c->draw();
    }
}

void MainWindow::Timer_CB(void *userdata) {
    MainWindow *o = (MainWindow *)userdata;
    o->redraw();
    Fl::repeat_timeout(1.0 / refreshPerSecond, Timer_CB, userdata);
}
