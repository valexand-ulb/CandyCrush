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

const int windowWidth = 500;
const int windowHeight = 500;
const double refreshPerSecond = 60;

class MainWindow : public Fl_Window {
public:
    MainWindow() : Fl_Window(000, 000, windowWidth, windowHeight, "CandyCrush") {
        Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
        resizable(this);
    }
    void draw() override {
        Fl_Window::draw();
    }
    static void Timer_CB(void *userdata) {
        MainWindow *o = (MainWindow *)userdata;
        o->redraw();
        Fl::repeat_timeout(1.0 / refreshPerSecond, Timer_CB, userdata);
    }
};

#endif //CANDYCRUSH_MAINWINDOW_H
