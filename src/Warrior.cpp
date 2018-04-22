#include "../include/Hero.h"
#include "../include/Warrior.h"


void Warrior::attack(Hero &enemy) //TODO naprawic!
{
    unsigned int damage;
    unsigned int HP = enemy.getHP();
    damage = static_cast<unsigned int>(((rand() % (getAD() - getAD() / 2)) + getAD() / 2) - enemy.getDEF() * 0.01);
    std::cout  << name << "(Warrior)" << " is performing attack!" << std::endl;
    HP -= damage;
    std::cout << "Inflicted damage: " << damage << std::endl;
}

Warrior::Warrior(std::string n) : Hero(n)
{
    _LVL = 1;
    _EXP = 0;
    _EXP2NEXTLVL = static_cast<unsigned int>((50/3) * (pow(_LVL, 3) - 6 * pow(_LVL, 3) + (17 * _LVL) - 11)); //LVL^UP FORMULA

    _HP = 150;
    _MANA = 0;
    _AD = 12;
    _AP = 0;
    _DEF = 10;

    _Strenght = 6;
    _Vitality = 6;
    _Dexterity = 4;
    _Intelligence = 0;
    _Luck = 0;

    std::cout << "Warrior constructor works here...\n";
}

Warrior::~Warrior()
{
    std::cout << "Warrior destructor works here...\n";
}

