#include "../include/Item.h"

Item::Item(std::string n, std::string t, unsigned int b, unsigned int stats)
{
    this->name = n;
    this->type = t;
    this->buyValue = b;
    this->sellValue = b / 2;
    this->_lvl = 1;

    if(t == "melee" || "ranged")
    {
        this->_ap = 0;
        this->_hp = 0;
        this->_mana = 0;
        this->_def = 0;
        this->_ad = stats * 3;
        this->_luck = stats;
    }
    if(t == "magic")
    {
        this->_ad = 0;
        this->_hp = 0;
        this->_def = 0;
        this->_luck = 0;
        this->_ap = stats * 3;
        this->_mana = stats * 10;
    }
    if(t == "helmet")
    {
        this->_ap = 0;
        this->_ad = 0;
        this->_hp = 0;
        this->_mana = 0;
        this->_luck = 0;
        this->_def = stats;
    }
    if(t == "armor")
    {
        this->_ap = 0;
        this->_ad = 0;
        this->_mana = 0;
        this->_luck = 0;
        this->_def = stats * 3;
        this->_hp = stats * 20;
    }
    if(t == "boots")
    {
        this->_ap = 0;
        this->_ad = 0;
        this->_mana = 0;
        this->_luck = 0;
        this->_def = stats;
        this->_hp = stats * 5;
    }
    if(t == "shield")
    {
        this->_ap = 0;
        this->_ad = 0;
        this->_mana = 0;
        this->_luck = 0;
        this->_def = stats * 2;
        this->_hp = stats * 10;
    }

}

Item::~Item() {}

const void Item::showItem() const
{
    if(this == nullptr) std::cout << "EMPTY" << std::endl;
    else
    {
        std::cout << std::string(30, '+') << std::endl;
        std::cout << std::setw(28) << "Index:" << std::setw(2) << getIndex() << " ||" << std::setw(10) << " Attack damage + " << getad() << std::endl;
        std::cout << "Type: " << getType() << std::setw(static_cast<int>(27 - getType().length())) << " ||" << " Magic damage + " << getap();
        std::cout << "\nName: " << getName() << std::setw(static_cast<int>(27 - getName().length())) << " ||" << " Defence + " << getdef();
        std::cout << "\nBuy Value:" << std::setw(3) << getBuyValue() << std::setw(20) << " ||" << " Health points + " << gethp() << " |" << " Mana points + " << getmana();
        std::cout << "\nSell Value:" << std::setw(3) << getSellValue() << std::setw(19) << " ||" << " Luck + " << getluck() << std::endl;
        std::cout << std::string(30, '-') << std::endl;
    }
}

const std::string &Item::getName() const { return this->name; }
const std::string &Item::getType() const {return this->type;}
const unsigned int &Item::getBuyValue() const { return this->buyValue; }
const unsigned int &Item::getSellValue() const { return this->sellValue; }
const unsigned int &Item::getIndex() const { return this->index; }

const unsigned int& Item::getad() const { return this->_ad; }
const unsigned int& Item::getap() const { return this->_ap; }
const unsigned int& Item::getdef() const { return this->_def; }
const unsigned int& Item::gethp() const { return this->_hp; }
const unsigned int& Item::getmana() const { return this->_mana; }
const unsigned int& Item::getluck() const { return this->_luck; }
const unsigned int& Item::getlvl() const { return this->_lvl; }

void Item::setIndex(unsigned int i)
{
    this->index = i;
}

Item* Item::operator++()
{
    std::cout << "Upgrading item..." << std::endl;
    if(this->getType() == "melee")
    {
        std::cout << "UPGRADING MELEE WEAPON!\n";
        this->_ad += _lvl;
        this->_lvl += 1;
    }
    if(this->getType() == "ranged")
    {
        std::cout << "UPGRADING RANGED WEAPON!\n";
        this->_ad += _lvl;
        this->_lvl += 1;
    }
    if(this->getType() == "magic")
    {
        std::cout << "UPGRADING MAGIC WEAPON!\n";
        this->_ap += _lvl;
        this->_mana += 10 * _lvl;
        this->_lvl += 1;
    }
    if(this->getType() == "helmet")
    {
        std::cout << "UPGRADING HELMET!\n";
        this->_def += _lvl;
        this->_lvl += 1;
    }
    if(this->getType() == "armor")
    {
        std::cout << "UPGRADING BREASTPLATE!\n";
        this->_def += _lvl;
        this->_hp += 10 * _lvl;
        this->_lvl += 1;
    }
    if(this->getType() == "boots")
    {
        std::cout << "UPGRADING BOOTS!\n";
        this->_def += _lvl;
        this->_hp += 5 * _lvl;
        this->_lvl += 1;
    }
    if(this->getType() == "shield")
    {
        std::cout << "UPGRADING SHIELD!\n";
        this->_def += _lvl;
        this->_hp += 5 * _lvl;
        this->_lvl += 1;
    }
}