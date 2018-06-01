#include "Item.h"
#ifndef HEROES_INVENTORY_H
#define HEROES_INVENTORY_H

class Inventory
{
private:
    std::vector<Item *> _inventory;
    unsigned int Size;
    unsigned int maxSize;

public:
    Inventory(unsigned int size = 5);
    virtual ~Inventory();
    const unsigned int &setSize(unsigned int);
    const void showInv() const;
    const void addItem(Item*);
    const void removeItem(Item*);
};

#endif //HEROES_INVENTORY_H
