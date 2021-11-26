//
// Created by alex on 20/11/21.
//

#ifndef CANDYCRUSH_CELL_H
#define CANDYCRUSH_CELL_H
#include "Item.h"

class Cell {
private:
    Position position;
    std::shared_ptr<Item> pItem= std::make_shared<Candy>(rand()%6);
    //Item *pItem=new Candy{rand()%6};
    bool empty= false;
    int frozen=0;
public:
    //Constructeurs
    Cell(Position pos);
    Cell(const Cell &other); //copie
    Cell(Cell &&other); //deplacement

    // getter / setters
    Item getItem()const{return *pItem;}
    void setItem(){pItem= std::make_shared<Candy>(rand()%6);}
    //void setItem(Item* new_item){pItem = new_item;}
    Position getPosition()const{return position;}
    void setPosition(Position new_pos){position=new_pos;}

    // Méthodes
    bool isEmpty()const{return pItem==nullptr;}
    void clear();
    void swap(Cell& other);

    // surcharge
    friend std::ostream& operator<<(std::ostream& flux, const Cell& c);
    Cell &operator=(Cell other);
};


#endif //CANDYCRUSH_CELL_H
