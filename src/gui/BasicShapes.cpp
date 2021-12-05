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
    //std::cout << center.x+w/2 << ','<< center.y+h/2 << std::endl;
    fl_draw_box(FL_FLAT_BOX, center.x+w/2, center.y+h/2, w, h, fillColor);
    fl_draw_box(FL_BORDER_FRAME, center.x+w/2, center.y+h/2, w, h, frameColor);
}

Circle::Circle(Point center, int rayon, Fl_Color frameColor, Fl_Color fillColor)
    :r(rayon){
    this->center=center;
    this->frameColor=frameColor;
    this->fillColor=fillColor;
}

void Circle::draw() const {
    std::array<Point, 37> points;
    for (int i=0; i<36; i++)
        points[i]= {static_cast<int>(center.x+r*sin(i*10*std::numbers::pi/180)),
                    static_cast<int>(center.y+r*cos(i*10*std::numbers::pi/180))
        };
    points[36]=points[0];
    fl_color(fillColor);
    fl_begin_polygon();
    for (auto& point : points) {
        fl_vertex(point.x, point.y);
    }
    fl_end_polygon();
    fl_color(frameColor);
    fl_begin_line();
    for (auto& point : points) {
        fl_vertex(point.x, point.y);
    }
    fl_end_line();
}

RectangleAndCircle::RectangleAndCircle(Point center,int width, int height, int r,Fl_Color CframeColor,Fl_Color CfillColor,Fl_Color RframeColor,Fl_Color RfillColor)
:Rectangle(center, width, height, RframeColor, RfillColor),
Circle(center, r, CframeColor, CfillColor){
}

void RectangleAndCircle::draw() const {
    Rectangle::draw();
    Circle::draw();
}