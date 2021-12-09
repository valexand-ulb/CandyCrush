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
public:
    virtual void setFillColor(Fl_Color new_col){fillColor=new_col;}
};

class Rectangle: public virtual BasicShape, public  virtual Sketchable{
    int w,h;
public:
    Rectangle(Point center, int width=50, int height=50, Fl_Color fillColor=FL_WHITE, Fl_Color frameColor=FL_BLACK);
    void setPoint(Point new_p){center=new_p;}
    virtual void draw() const override;
};

class Circle:public virtual BasicShape, public  virtual Sketchable{
    int r;
public:
    Circle(Point center, Fl_Color fillColor, int rayon=22, Fl_Color frameColor=FL_BLACK);
    Circle(Point center, int fillColor, int rayon=22, Fl_Color frameColor=FL_BLACK);
    virtual void draw() const override;
};
#endif //CANDYCRUSH_BASICSHAPES_H
