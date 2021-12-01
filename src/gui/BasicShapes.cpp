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

Circle::Circle(Point center, int rayon, Fl_Color frameColor, Fl_Color)
    :r(rayon){
    this->center=center;
    this->frameColor=frameColor;
    this->fillColor=fillColor;
}