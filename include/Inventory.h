#include "Item.h"
#ifndef HEROES_INVENTORY_H
#define HEROES_INVENTORY_H

class Inventory //TODO ogarnac !
{
private:
    std::vector<Item *> _inventory;
    unsigned int Size;
    unsigned int maxSize;

public:
    Inventory(unsigned int size = 5);
    virtual ~Inventory();
    unsigned int &getSize();
    const unsigned int &setSize(unsigned int);
    const void showInv() const;
    const void addItem(Item*);
    Item* getItem(unsigned int) const;
    const void removeItem(Item*);
    const bool full_inventory() const;
};

#endif //HEROES_INVENTORY_H
