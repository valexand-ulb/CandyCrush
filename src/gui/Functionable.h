//
// Created by alex on 12/1/21.
//

#ifndef CANDYCRUSH_FUNCTIONABLE_H
#define CANDYCRUSH_FUNCTIONABLE_H

#include "Point.h"
#include <iostream>

class Sketchable {
public:
    virtual void draw()const=0;
};

class Clickable{
public:
    virtual bool contains (Point p) const =0;
    virtual void onClick()=0;
};

#endif //CANDYCRUSH_FUNCTIONABLE_H
