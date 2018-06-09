#include "../include/Hero.h"
#include "../include/Archer.h"

void Archer::attack(Hero &)
{

}

Archer::Archer(std::string n) : Hero(n)
{
    this->_X = 0;
    this->_Y = 0;

    this->_GOLD = 100;
    this->_LVL = 1;
    this->_EXP = 20;
    this->_EXP2NEXTLVL = static_cast<unsigned int>((50/3) * (pow(_LVL, 3) - 6 * pow(_LVL, 3) + (17 * _LVL) - 11)); //LVL^UP FORMULA

    this->_maxHP = 50;
    this->_HP = _maxHP;

    this->_maxMANA = 0;
    this->_MANA = _maxMANA;
    this->_AD = 20;
    this->_AP = 0;
    this->_DEF = 8;

    this->_Strenght = 2;
    this->_Vitality = 3;
    this->_Dexterity = 3;
    this->_Intelligence = 6;
    this->_Luck = 0;

    this->_armor = {nullptr, nullptr, nullptr, nullptr};
    this->_weapon = nullptr;
    std::cout << "Archer constructor works here...\n";
}

Archer::~Archer()
{
    std::cout << "Archer destructor works here...\n";
}

void Archer::equip()
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
        std::cout << "I'm ARCHER I can't equip melee weapons!" << std::endl;
        return;
    }
    if(getItem(index)->getType() == "ranged")
    {
        std::cout << "I equipping weapon!(+5 AD)" << std::endl;
        if(_weapon == nullptr)
        {
            _weapon = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_weapon, getItem(index));
        _AD = (getAD() + 5);
        return;
    }
    if(getItem(index)->getType() == "magic")
    {
        std::cout << "I'm ARCHER I can't equip magic weapons!" << std::endl;
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

const void Archer::showItems() const
{
    std::cout << "ARCHER EQUIPMENT...\n";
    std::cout << "\nARCHER ARMOR\n";
    for(auto i : _armor) i->showItem();
    std::cout << "ARCHER BOW\n";
    _weapon->showItem();
}