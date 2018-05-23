#include "Item.h"
#ifndef HEROES_INVENTORY_H
#define HEROES_INVENTORY_H

class Inventory
{
    std::vector<Item *> _inventory;
    unsigned int Size;
    unsigned int maxSize;

public:
    Inventory();
    virtual ~Inventory();
    const void showInv() const;
    const void addItem(Item*);
    const void removeItem(Item*);
    const Item* getPointer(unsigned int) const;
};

#endif //HEROES_INVENTORY_H
