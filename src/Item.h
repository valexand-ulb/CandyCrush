//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_ITEM_H
#define CANDYCRUSH_ITEM_H
#include "Position.h"

// classe abstraite
class Item {
private:
    Position position;
    int color=0;
public:
    void setPosition(Position new_position ){position=new_position;}
    Position getPosition()const{return position;}
    void setColor(int new_color){color=new_color;}
    int getColor()const{return color;}



};

// Classe Bonbon
class Candy: public Item{
private:
public:
};

// Classe Bonus
class PowerUp: public  Item{
private:
public:
};

// Classe Glacage
class Frosting:public Item{
private:
public:
};

#endif //CANDYCRUSH_ITEM_H
