//
// Created by alex on 12/1/21.
//

#include "BasicShapes.h"


/*
 Rectangle class
 */
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

void Rectangle::onClick() {
}

bool Rectangle::contains(Point p) const {
    return p.x>center.x-w/2 &&
        p.x<center.x+w/2 &&
        p.y>center.y-h/2 &&
        p.y<center.y+h/2;
}

/*
 Circle class
 */

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
            this->fillColor= fl_rgb_color(255,0,0); //rouge
            break;
        case 1:
            this->fillColor= fl_rgb_color(255,128,0); // orange
            break;
        case 2:
            this->fillColor= fl_rgb_color(255,255,0); // Jaune
            break;
        case 3:
            this->fillColor= fl_rgb_color(128,255,0); //vert
            break;
        case 4:
            this->fillColor= fl_rgb_color(0,128,128); //bleu
            break;
        case 5:
            this->fillColor= fl_rgb_color(128,0,255);
            break;
    }
}

void Circle::draw() const {
    fl_color(fillColor);
    fl_begin_polygon();
    fl_circle(center.x, center.y, r);
    fl_end_polygon();
}
