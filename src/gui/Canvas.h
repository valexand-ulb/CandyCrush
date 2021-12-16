//
// Created by alex on 12/16/21.
//

#ifndef CANDYCRUSH_CANVAS_H
#define CANDYCRUSH_CANVAS_H
#include "../logic/Matrice.h"
#include "BasicShapes.h"

class Canvas {
private:
    std::vector<std::shared_ptr<BasicShape>> vect;
public:
    Canvas(std::shared_ptr<Matrice> mat);
    void draw();
    void mouseClick(Point mouseLoc){
        for (auto &c:vect){
            auto x= std::dynamic_pointer_cast<Clickable>(c);
            if (x && x->contains(mouseLoc)) x->onClick();
        }
    }

};


#endif //CANDYCRUSH_CANVAS_H
