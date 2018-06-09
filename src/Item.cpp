#include "../include/Item.h"

Item::Item(std::string n, std::string t, unsigned int b)
{
    this->name = n;
    this->type = t;
    this->buyValue = b;
    this->sellValue = b / 2;
}

Item::~Item() {}

const void Item::showItem() const
{
    if(this == nullptr) std::cout << "EMPTY" << std::endl;
    else
    {
        std::cout << std::string(30, '+') << std::endl;
        std::cout << std::setw(28) << "Index: " << getIndex();
        std::cout << std::setw(10) << "\nType: " << getType();
        std::cout << std::setw(10) << "\nName: " << getName();
        std::cout << std::setw(10) << "\nBuy Value: " << getBuyValue();
        std::cout << std::setw(10) << "\nSell Value: " << getSellValue() << std::endl;
        std::cout << std::string(30, '-') << std::endl;
    }
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
