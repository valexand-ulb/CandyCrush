//
// Created by alex on 12/16/21.
//

#ifndef CANDYCRUSH_CANVAS_H
#define CANDYCRUSH_CANVAS_H
#include "../logic/Matrice.h"
#include "BasicShapes.h"

class Canvas {
private:
    Position p1, p2;
    std::vector<std::shared_ptr<BasicShape>> vect;
public:
    Canvas(std::shared_ptr<Matrice> mat);
    void update(std::shared_ptr<Matrice> mat);
    void draw();
    Position mouseClick(Point mouseLoc);

};


#endif //CANDYCRUSH_CANVAS_H
