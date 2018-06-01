#include "../include/Shop.h"

Shop::Shop()  = default;
Shop::~Shop() = default;

void Shop::Initialize()
{
    Item *sword = new Item("sword", "melee weapon", 12, 5);
    addItem(sword);
    //this->addItem(new Item("shield", "armor", 20, 10));
    std::cout << "Shop has been initialized!" << std::endl;
}

const void Shop::Menu() const
{
    std::cout << "Welcome in my shop!" << std::endl;
    this->showInv();
}