#include <vector>
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
    const void show() const;
    const void addItem(Item*);
    const void removeItem(Item*);
};

#endif //HEROES_INVENTORY_H
