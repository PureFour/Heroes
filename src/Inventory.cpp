#include "../include/Inventory.h"

Inventory::Inventory()
{
    this->_inventory = {};
    this->Size = 0;
    this->maxSize = 8;
}
Inventory::~Inventory() {}

const void Inventory::showInv() const
{
    if(Size == 0) std::cout << "Inventory is empty!" << std::endl;
    else
    {
        for(auto i = 0; i < Size; i++) _inventory[i]->showItem();
    }
}

const void Inventory::addItem(Item *item)
{
    if(Size == maxSize) std::cout << "Inventory is Full!" << std::endl;
    else
    {
        _inventory.push_back(item);
        item->setIndex(Size);
        Size += 1;
    }
}

const void Inventory::removeItem(Item *item)
{
    if(Size == 0) std::cout << "Inventory is empty!" << std::endl;
    else
    {
        _inventory.erase(_inventory.begin() + item->getIndex()); //TODO memory leaks ????? Check it!
        Size -= 1;
    }
}