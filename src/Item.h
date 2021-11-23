//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_ITEM_H
#define CANDYCRUSH_ITEM_H
#include "Position.h"
#include <iostream>

// classe abstraite
class Item {
protected:
    Position position;
    int color=0;
public:
    //getter setter
    Position getPosition()const{return position;}
    void setPosition(Position new_pos){position=new_pos;}
    void setColor(int new_color){color=new_color;}
    int getColor()const{return color;}
    // opérateur
    // surcharge
    friend std::ostream& operator<<(std::ostream& flux, const Item &i);
    ~Item(){std::cout << "MORT DE ITEM" << std::endl;};
};

// Classe Bonbon
class Candy: public Item{
private:
public:
    Candy(int color){this->color=color;}
    ~Candy(){std::cout << "mort de item: (" << position.getPosX() << "," << position.getPosY() << ")\n";}
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
