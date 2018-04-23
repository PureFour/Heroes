#include "../include/Item.h"

Item::Item()
{
    this->name = "Unknown";
    this->buyValue = 0;
    this->sellValue = 0;
    this->index = 0;
    std::cout << "New Item"<< std::endl;
}

Item::~Item()
{
    std::cout << "Item nr. " << getIndex() << " DELETED" << std::endl;
}

void Item::showItem()
{
    std::cout << "Index: " << getIndex();
    std::cout << " Name: " << getName();
    std::cout << "Buy Value: " << getBuyValue() << std::endl;
    std::cout << "Sell Value: " << getSellValue() << std::endl;
}

const std::string &Item::getName() const { return this->name;}
const unsigned int &Item::getBuyValue() const { return this->buyValue; }
const unsigned int &Item::getSellValue() const { return this->sellValue; }
const unsigned int &Item::getIndex() const { return this->index; }

void Item::setIndex(unsigned int i)
{
    this->index = i;
}


