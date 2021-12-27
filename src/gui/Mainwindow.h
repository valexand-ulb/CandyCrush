//
// Created by alex on 12/1/21.
//

#ifndef CANDYCRUSH_MAINWINDOW_H
#define CANDYCRUSH_MAINWINDOW_H

#include <FL/Fl.H>
#include <time.h>
#include "Canvas.h"


const int windowWidth = 500;
const int windowHeight = 500;
const double refreshPerSecond = 60;

class MainWindow : public Fl_Window {
private:
    std::shared_ptr<Matrice> mat;
    Canvas canvas;
public:
    MainWindow(std::shared_ptr<Matrice> mat);
    void draw() override;
    void updateCanva(){canvas.update(mat);};
    int handle(int event) override;
    static void Timer_CB(void *userdata);
};

#endif //CANDYCRUSH_MAINWINDOW_H
