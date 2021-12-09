//
// Created by alex on 12/1/21.
//

#include "BasicShapes.h"



Rectangle::Rectangle(Point center, int width, int height, Fl_Color fillColor,Fl_Color frameColor)
    :w(width),h(height){
    this->center=center;
    this->frameColor=frameColor;
    this->fillColor=fillColor;
}

void Rectangle::draw() const {
    fl_begin_polygon();
    fl_draw_box(FL_FLAT_BOX, center.x-w/2, center.y-h/2, w, h, fillColor);
    fl_draw_box(FL_BORDER_FRAME, center.x-w/2, center.y-h/2, w, h, frameColor);
    fl_end_polygon();
}

Circle::Circle(Point center, Fl_Color fillColor, int rayon, Fl_Color frameColor)
    :r(rayon){
    this->center=center;
    this->frameColor=frameColor;
    this->fillColor=fillColor;
}
Circle::Circle(Point center, int fillColor, int rayon, Fl_Color frameColor):r(rayon) {
    this->center=center;
    this->frameColor=frameColor;
    switch (fillColor) {
        case 0:
            this->fillColor= FL_RED;
        case 1:
            this->fillColor= FL_GREEN;
        case 2:
            this->fillColor= FL_BLUE;
        case 3:
            this->fillColor= FL_YELLOW;
        case 4:
            this->fillColor= FL_CYAN;
        case 5:
            this->fillColor= FL_BLACK;
    }
    this->fillColor=fillColor;
}

void Circle::draw() const {
    fl_color(fillColor);
    fl_begin_polygon();
    fl_circle(center.x, center.y, r);
    fl_end_polygon();
}
