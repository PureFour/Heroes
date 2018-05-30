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

const void Item::showItem() const
{
    if(this == nullptr) std::cout << "EMPTY" << std::endl;
    else
    {
        std::cout << std::string(50, '+') << std::endl;
        std::cout << std::setw(48) << "Index: " << getIndex();
        std::cout << std::setw(20) << "\nType: " << getType();
        std::cout << std::setw(20) << "\nName: " << getName();
        std::cout << std::setw(20) << "\nBuy Value: " << getBuyValue();
        std::cout << std::setw(20) << "\nSell Value: " << getSellValue() << std::endl;
        std::cout << std::string(50, '-') << std::endl;
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


