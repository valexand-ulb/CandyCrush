//
// Created by alex on 12/1/21.
//

#include "BasicShapes.h"
Rectangle::Rectangle(Point center, int width, int height, Fl_Color frameColor, Fl_Color fillColor)
    :w(width),h(height){
    this->center=center;
    this->frameColor=frameColor;
    this->fillColor=fillColor;
}

void Rectangle::draw() const {
    fl_draw_box(FL_FLAT_BOX, center.x, center.y, w, h, fillColor);
}

Circle::Circle(Point center, int rayon, Fl_Color frameColor, Fl_Color)
    :r(rayon){
    this->center=center;
    this->frameColor=frameColor;
    this->fillColor=fillColor;
}

void Circle::draw() const {
    fl_draw_box(FL_FLAT_BOX, center.x, center.y, w, h, fillColor);
}