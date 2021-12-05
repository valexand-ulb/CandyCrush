//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_CELL_H
#define CANDYCRUSH_CELL_H
#include "Item.h"
#include "../gui/BasicShapes.h"

class Cell{
private:
    Position position;
    std::shared_ptr<Item> pItem= std::make_shared<Candy>(rand()%6);
    //Item *pItem=new Candy{rand()%6};
    bool empty= false;
    int frozen=0;
public:
    //Constructeurs
    Cell(Position pos, int i=-1);
    Cell(const Cell &other); //copie
    Cell(Cell &&other); //deplacement

    // getter / setters
    Item getItem()const{return *pItem;}
    void setItem(int clr=-1){clr==-1 ? pItem=std::make_shared<Candy>(rand()%6) : pItem=std::make_shared<Candy>(clr);}
    //void setItem(Item* new_item){pItem = new_item;}
    Position getPosition()const{return position;}
    void setPosition(Position new_pos){position=new_pos;}

    // Méthodes
    bool isEmpty()const{return pItem==nullptr;}
    void clear();
    void swap(Cell& other);
    void draw();
    // surcharge
    friend std::ostream& operator<<(std::ostream& flux, const Cell& c);
    Cell &operator=(const Cell &other);
    Cell &operator=(Cell &&other);
};


#endif //CANDYCRUSH_CELL_H
