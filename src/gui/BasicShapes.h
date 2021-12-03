//
// Created by alex on 12/1/21.
//

#ifndef CANDYCRUSH_BASICSHAPES_H
#define CANDYCRUSH_BASICSHAPES_H

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#include "Functionable.h"

struct Point{
    int x,y;
};

class BasicShape{
protected:
    Point center;
    Fl_Color frameColor=FL_BLACK, fillColor=FL_WHITE;
public:
};

class Rectangle: public virtual BasicShape, public  virtual Sketchable{
    int w,h;
public:
    Rectangle(Point center, int width, int height, Fl_Color frameColor=FL_BLACK, Fl_Color fillColor=FL_WHITE);
    void draw() const override;
};

class Circle:public virtual BasicShape, public  virtual Sketchable{
    int r,w,h;
public:
    Circle(Point center, int rayon, Fl_Color frameColor=FL_BLACK, Fl_Color=FL_WHITE);
    void draw() const override;
};
#endif //CANDYCRUSH_BASICSHAPES_H
