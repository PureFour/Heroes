#include "../include/Inventory.h"

Inventory::Inventory(unsigned int size)
{
    this->_inventory = {};
    this->Size = 0;
    this->maxSize = size;
}
Inventory::~Inventory() {}

const unsigned int & Inventory::getSize()const { return this->Size; }

const unsigned int& Inventory::setSize(unsigned int size) { this->maxSize = size; }

const void Inventory::showInv() const
{
    if(Size == 0) std::cout << "Inventory is empty!" << std::endl;
    else
    {
        for(auto i = 0; i < Size; i++) _inventory[i]->showItem();
    }
}

Item * Inventory::searchItem(std::string name) const
{
    for(auto i : _inventory)
    {
        if(i->getName() == name)
            return i;
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

void Inventory::swapItems(Item *a, Item *b)
{
    Item temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int Inventory::removeItem(Item *item)
{
    if(Size == 0) std::cout << "Inventory is empty!" << std::endl;
    else
    {
        _inventory.erase(_inventory.begin() + item->getIndex()); //TODO moze byc zle ??
        Size -= 1;
        return 1;
    }
}

const bool Inventory::full_inventory() const { return Size == maxSize; }