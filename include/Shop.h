#include "Inventory.h"
#include "Hero.h"
#ifndef HEROES_SHOP_H
#define HEROES_SHOP_H

class Shop : public Inventory
{
public:
    Shop();
    virtual ~Shop();
    void Initialize();
    const void Menu(Hero *) const;
    void Buy(Hero *) const;
    void Sell(Hero *) const;

};

#endif //HEROES_SHOP_H
