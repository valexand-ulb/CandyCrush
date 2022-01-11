//
// Created by alex on 12/1/21.
//

#include "Mainwindow.h"

MainWindow::MainWindow(std::shared_ptr <Matrice> mat):
Fl_Window(000, 000, windowWidth, windowHeight, "CandyCrush-par Vinovrski Alexandre-501.157"), mat(mat), canvas(Canvas{mat}){
    Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
    //resizable(this);
}

void MainWindow::draw() {
    Fl_Window::draw();
    canvas.draw();
}

int MainWindow::handle(int event) {
    switch (event) {
        case FL_PUSH:
            mat->updateOnClick(canvas.mouseClick(Point{Fl::event_x(), Fl::event_y()}));
            updateCanva();
            return 1;
    }
    return 0;
}

void MainWindow::Timer_CB(void *userdata) {
    MainWindow *o = (MainWindow *)userdata;
    o->redraw();
    Fl::repeat_timeout(1.0 / refreshPerSecond, Timer_CB, userdata);
}
