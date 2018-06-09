#include "Item.h"
#ifndef HEROES_INVENTORY_H
#define HEROES_INVENTORY_H

class Inventory
{
protected:
    std::vector<Item *> _inventory;
    unsigned int Size;
    unsigned int maxSize;

public:
    Inventory(unsigned int size = 5);
    virtual ~Inventory();
    //get F
    const unsigned int & getSize()const;
    Item* getItem(unsigned int) const;
    //set F
    const unsigned int &setSize(unsigned int);
    //
    virtual const void showInv() const;
    Item * searchItem(std::string) const;
    const void addItem(Item*);
    void swapItems(Item *, Item *);
    int removeItem(Item*);
    const bool full_inventory() const;
};

#endif //HEROES_INVENTORY_H
