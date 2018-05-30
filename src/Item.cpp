#include "../include/Item.h"

Item::Item(std::string n, std::string t, unsigned int b, unsigned int s)
{
    this->name = n;
    this->type = t;
    this->buyValue = b;
    this->sellValue = s;
    std::cout << "New Item"<< std::endl;
}

Item::~Item()
{
    std::cout << "Item nr. " << getIndex() << " DELETED" << std::endl;
}

void Item::showItem()
{
    std::cout << "Index: " << getIndex();
    std::cout << "Type: " << getType();
    std::cout << "\n Name: " << getName();
    std::cout << "Buy Value: " << getBuyValue() << std::endl;
    std::cout << "Sell Value: " << getSellValue() << std::endl;
}

const std::string &Item::getName() const { return this->name;}
const std::string &Item::getType() const {return this->type;}
const unsigned int &Item::getBuyValue() const { return this->buyValue; }
const unsigned int &Item::getSellValue() const { return this->sellValue; }
const unsigned int &Item::getIndex() const { return this->index; }

void Item::setIndex(unsigned int i)
{
    this->index = i;
}


