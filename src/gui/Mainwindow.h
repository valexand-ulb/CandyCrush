//
// Created by alex on 12/1/21.
//

#ifndef CANDYCRUSH_MAINWINDOW_H
#define CANDYCRUSH_MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <math.h>
#include <time.h>
#include <vector>
#include <memory>
#include "../logic/Matrice.h"
#include "Canvas.h"


const int windowWidth = 500;
const int windowHeight = 500;
const double refreshPerSecond = 60;

class MainWindow : public Fl_Window {
private:
    Canvas canvas;
public:
    MainWindow(std::shared_ptr<Matrice>mat);
    void draw();
    int handle(int event) override;
    static void Timer_CB(void *userdata);
};

#endif //CANDYCRUSH_MAINWINDOW_H
