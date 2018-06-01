#include "Inventory.h"

#ifndef HEROES_SHOP_H
#define HEROES_SHOP_H

class Shop : public Inventory
{
public:
    Shop();
    virtual ~Shop();
    void Initialize();
    const void Menu() const;

};

#endif //HEROES_SHOP_H
