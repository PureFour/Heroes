#include "../include/Hero.h"
#include "../include/Mage.h"

#include <ctime>

void Mage::attack(Hero &enemy)
{

}

Mage::Mage(std::string n) : Hero(n)
{
    _HP = 110;
    _MANA = 100;
    _AD = 2;
    _DEF = 5;
    std::cout << "Mage constructor works here...\n";
}

Mage::~Mage()
{
    std::cout << "Mage destructor works here...\n";
}


