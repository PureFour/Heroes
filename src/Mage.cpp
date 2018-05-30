#include "../include/Hero.h"
#include "../include/Mage.h"

void Mage::attack(Hero &enemy)
{

}

Mage::Mage(std::string n) : Hero(n)
{
    this->_LVL = 1;
    this->_EXP = 0;
    this->_EXP2NEXTLVL = static_cast<unsigned int>((50/3) * (pow(_LVL, 3) - 6 * pow(_LVL, 3) + (17 * _LVL) - 11)); //LVL^UP FORMULA

    this->_HP = 100;
    this->_MANA = 100;
    this->_AD = 2;
    this->_AP = 5;
    this->_DEF = 3;

    this->_Strenght = 2;
    this->_Vitality = 3;
    this->_Dexterity = 3;
    this->_Intelligence = 6;
    this->_Luck = 0;
    std::cout << "Mage constructor works here...\n";
}

Mage::~Mage()
{
    std::cout << "Mage destructor works here...\n";
}

void Mage::equip(Item &)
{

}

const void Mage::showItems() const {}
