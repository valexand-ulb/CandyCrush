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
#include "Point.h"

class BasicShape:public virtual Sketchable{
protected:
    Point center;
    Fl_Color frameColor=FL_BLACK, fillColor=FL_WHITE;
public:
    virtual void setFillColor(Fl_Color new_col){fillColor=new_col;}
    virtual Point getCenter()const{return center;}
    void draw() const=0;
};

class Rectangle: public virtual BasicShape, public virtual Clickable{
    int w,h;
public:
    Rectangle(Point center, int width=50, int height=50, Fl_Color fillColor=FL_WHITE, Fl_Color frameColor=FL_WHITE);
    void setPoint(Point new_p){center=new_p;}
    void draw() const override;
    void onClick() override;
    bool contains(Point p) const override;
};

class Circle:public virtual BasicShape{
    int r;
public:
    Circle(Point center, Fl_Color fillColor, int rayon=22, Fl_Color frameColor=FL_BLACK);
    Circle(Point center, int fillColor, int rayon=22, Fl_Color frameColor=FL_BLACK);
    void draw() const override;
};
#endif //CANDYCRUSH_BASICSHAPES_H
