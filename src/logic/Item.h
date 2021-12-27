//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_ITEM_H
#define CANDYCRUSH_ITEM_H
#include "Position.h"

// classe abstraite
class Item {
protected:
    int color=0;
public:
    //constructeurs
    virtual ~Item(){};
    //getter setter
    void setColor(int new_color){color=new_color;}
    int getColor()const{return color;}
    // opérateur
    // surcharge
    friend std::ostream& operator<<(std::ostream& flux, const Item &i);
};

// Classe Bonbon
class Candy: public virtual Item{
private:
public:
    //constructeur
    Candy(int clr){color=clr;}
    ~Candy(){}

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
