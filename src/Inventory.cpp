#include "../include/Inventory.h"

Inventory::Inventory(unsigned int size)
{
    this->_inventory = {};
    this->Size = 0;
    this->maxSize = size;
}
Inventory::~Inventory() {}

unsigned int& Inventory::getSize() { return this->Size; }

const unsigned int& Inventory::setSize(unsigned int size) { this->maxSize = size; }

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

Item* Inventory::getItem(unsigned int index) const
{
    return _inventory[index]; // ??
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

const bool Inventory::full_inventory() const { return Size == maxSize; }