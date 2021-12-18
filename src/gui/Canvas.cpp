//
// Created by alex on 12/16/21.
//

#include "Canvas.h"

Canvas::Canvas(std::shared_ptr <Matrice> mat) {
    update(mat);
    /*
    int size = mat->getSize();
    for (int i=0; i< size; i++){
        for(int j=0; j<size; j++){
            // inversion i-j x-y pour correspondre a la matrice
            vect.push_back(std::make_shared<Rectangle>(Point{(j+1)*50,(i+1)*50}));
            if (!mat->isCellEmpty({i,j})) {
                vect.push_back(std::make_shared<Circle>(Point{(j+1)*50,(i+1)*50},mat->getCellColor({i, j})));
            }else{
                std::cout << i << ',' << j << std::endl;
            }
        }
    }
     */
}

void Canvas::update(std::shared_ptr <Matrice> mat) {
    vect.clear();
    std::cout << vect.size() << std::endl;
    int size = mat->getSize();
    for (int i=0; i< size; i++){
        for(int j=0; j<size; j++){
            // inversion i-j x-y pour correspondre a la matrice
            vect.push_back(std::make_shared<Rectangle>(Point{(j+1)*50,(i+1)*50}));
            if (!mat->isCellEmpty({i,j})) {
                vect.push_back(std::make_shared<Circle>(Point{(j+1)*50,(i+1)*50},mat->getCellColor({i, j})));
            }
        }
    }
}

void Canvas::draw() {
    for (auto &d:vect){
        d->draw();
    }
}

Position Canvas::mouseClick(Point mouseLoc) {
    for (auto &c:vect){
        auto x= std::dynamic_pointer_cast<Clickable>(c);
        if (x && x->contains(mouseLoc)) {
            x->onClick();
            return Position{(c->getCenter().y/50)-1, (c->getCenter().x/50)-1};
        }
    }
    return Position{-1, -1};
}