#include "../include/Hero.h"
#include "../include/Warrior.h"

#include <ctime>

void Warrior::attack(Hero &enemy)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    unsigned int damage;
    unsigned int *HP = enemy.getHP();
    damage = static_cast<unsigned int>(((rand() % (getAD() - getAD() / 2)) + getAD() / 2) - enemy.getDEF() * 0.01);
    std::cout  << name << "(Warrior)" << " is performing attack!" << std::endl;
    *HP -= damage;
    std::cout << "Inflicted damage: " << damage << std::endl;
}

Warrior::Warrior(std::string n) : Hero(n)
{
    _HP = 150;
    _MANA = 0;
    _AD = 12;
    _DEF = 10;
    std::cout << "Warrior constructor works here...\n";
}

Warrior::~Warrior()
{
    std::cout << "Warrior destructor works here...\n";
}

