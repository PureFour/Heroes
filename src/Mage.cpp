#include "../include/Hero.h"
#include "../include/Mage.h"

void Mage::attack(Hero &enemy)
{

}

Mage::Mage(std::string n) : Hero(n)
{
    this->_X = 0;
    this->_Y = 0;

    this->_GOLD = 100;
    this->_LVL = 1;
    this->_EXP = 20;
    this->_EXP2NEXTLVL = static_cast<unsigned int>((50/3) * (pow(_LVL, 3) - 6 * pow(_LVL, 3) + (17 * _LVL) - 11)); //LVL^UP FORMULA

    this->_HP = 60;
    this->_maxHP = _HP;

    this->_MANA = 100;
    this->_maxMANA = _MANA;
    this->_AD = 2;
    this->_AP = 5;
    this->_DEF = 3;

    this->_Strenght = 2;
    this->_Vitality = 3;
    this->_Dexterity = 3;
    this->_Intelligence = 6;
    this->_Luck = 0;

    this->_armor = {nullptr, nullptr, nullptr, nullptr};
    this->_weapon = nullptr;
    std::cout << "Mage constructor works here...\n";
}

Mage::~Mage()
{
    std::cout << "Mage destructor works here...\n";
}

void Mage::equip()
{
    if(getSize() == 0)
    {
        std::cout << "Inventory is Empty!" << std::endl;
        return;
    }

    std::cout << "Enter item index: ";
    unsigned int index;
    std::cin >> index;

    if(getItem(index)->getType() == "melee")
    {
        std::cout << "I'm MAGE I can't equip melee weapons!" << std::endl;
        return;
    }
    if(getItem(index)->getType() == "ranged")
    {
        std::cout << "I'm MAGE I can't equip bows!" << std::endl;
        return;
    }
    if(getItem(index)->getType() == "magic")
    {
        std::cout << "I equipping weapon!(+5 AP)" << std::endl;
        if(_weapon == nullptr)
        {
            _weapon = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_weapon, getItem(index));
        _AP = (getAP() + 5);
        return;
    }
    if(getItem(index)->getType() == "helmet")
    {
        std::cout << "I equipping helmet!(+5 DEF)" << std::endl;
        if(_armor[0] == nullptr)
        {
            _armor[0] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[0], getItem(index));
        _DEF = (getDEF() + 5);
        return;
    }
    if(getItem(index)->getType() == "armor")
    {
        std::cout << "I equipping armor!(+15 VIT)" << std::endl;
        if(_armor[1] == nullptr)
        {
            _armor[1] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[1], getItem(index));
        _Vitality = (getVit() + 15);
        return;
    }
    if(getItem(index)->getType() == "boots")
    {
        std::cout << "I equipping boots!(+5 DEX)" << std::endl;
        if(_armor[2] == nullptr)
        {
            _armor[2] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[2], getItem(index));
        _Dexterity = (getDex() + 5);
        return;
    }
    if(getItem(index)->getType() == "shield")
    {
        std::cout << "I equipping shield!(+10 DEF)" << std::endl;
        if(_armor[3] == nullptr)
        {
            _armor[3] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[3], getItem(index));
        _DEF = (getDEF() + 10);
        return;
    }
}

const void Mage::showItems() const
{
    std::cout << "MAGE EQUIPMENT...\n";
    std::cout << "\nMAGE ARMOR\n";
    for(auto i : _armor) i->showItem();
    std::cout << "MAGE MAGIC WAND\n";
    _weapon->showItem();
}
