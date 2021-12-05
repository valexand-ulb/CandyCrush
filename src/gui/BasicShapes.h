//
// Created by alex on 12/1/21.
//

#ifndef CANDYCRUSH_BASICSHAPES_H
#define CANDYCRUSH_BASICSHAPES_H

#include <iostream>
#include <math.h>
#include <array>
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
};

class Rectangle: public virtual BasicShape, public  virtual Sketchable{
    int w,h;
public:
    Rectangle(Point center, int width=50, int height=50, Fl_Color frameColor=FL_BLACK, Fl_Color fillColor=FL_WHITE);
    void setPoint(Point new_p){center=new_p;}
    void draw() const override;
};

class Circle:public virtual BasicShape, public  virtual Sketchable{
    int r;
public:
    Circle(Point center, int rayon=50, Fl_Color frameColor=FL_BLACK, Fl_Color fillColor=FL_WHITE);
    void draw() const override;
};

class RectangleAndCircle: public virtual Rectangle, public virtual Circle{
public:
    RectangleAndCircle(Point center, int width, int height, int r, Fl_Color CframeColor, Fl_Color CfillColor,Fl_Color RframeColor=FL_BLACK, Fl_Color RfillColor=FL_WHITE);
    void draw() const override;
};
#endif //CANDYCRUSH_BASICSHAPES_H
