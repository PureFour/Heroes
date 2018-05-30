#include "Inventory.h"

#ifndef HEROES_SHOP_H
#define HEROES_SHOP_H

class Shop : public Inventory
{
    Inventory shop;
public:
    Shop();
    virtual ~Shop();
    void Initialize();

};

#endif //HEROES_SHOP_H
