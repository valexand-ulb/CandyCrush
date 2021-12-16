//
// Created by alex on 12/16/21.
//

#include "Canvas.h"

Canvas::Canvas(std::shared_ptr <Matrice> mat) {
    int size = mat->getSize();
    for (int i=0; i< size; i++){
        for(int j=0; j<size; j++){
            // inversion i-j x-y pour correspondre a la matrice
            vect.push_back(std::make_shared<Rectangle>(Point{(j+1)*50,(i+1)*50}));
            vect.push_back(std::make_shared<Circle>(Point{(j+1)*50,(i+1)*50},mat->getCellColor({i,j})));
        }
    }
}

void Canvas::draw() {
    for (auto &d:vect){
        d->draw();
    }
}