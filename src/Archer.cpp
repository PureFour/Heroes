#include "../include/Hero.h"
#include "../include/Archer.h"

void Archer::attack(Hero &)
{

}

Archer::Archer(std::string n) : Hero(n)
{
    _HP = 120;
    _MANA = 0;
    _AD = 20;
    _DEF = 8;
    std::cout << "Archer constructor works here...\n";
}

Archer::~Archer()
{
    std::cout << "Archer destructor works here...\n";
}

void Archer::equip()
{

}

const void Archer::showItems() const {}