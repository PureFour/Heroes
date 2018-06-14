#include "../include/Inventory.h"

Inventory::Inventory(unsigned int size)
{
    this->_inventory = {};
    this->Size = 0;
    this->maxSize = size;
}
Inventory::~Inventory() {}

const unsigned int& Inventory::getSize()const { return this->Size; }

const unsigned int& Inventory::setSize(unsigned int size) { this->maxSize = size; }

const void Inventory::showInv() const
{
    if(Size == 0) std::cout << "Inventory is empty!" << std::endl;
    else
    {
        unsigned int j = 0;
        for(auto i : _inventory)
        {
            i->setIndex(j);
            i->showItem();
            j++;
        }
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
        if(item->getIndex() == 0) item->setIndex(Size);
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
}

int Inventory::removeItem(Item *item)
{
    if(Size == 0) std::cout << "Inventory is empty!" << std::endl;
    else
    {
        unsigned int index = item->getIndex();
        delete item;
        this->_inventory[index] = this->_inventory[index + 1];
        Size -= 1;
        return 1;
    }
}

const bool Inventory::full_inventory() const { return Size == maxSize; }