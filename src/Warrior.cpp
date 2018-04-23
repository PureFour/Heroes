#include "../include/Hero.h"
#include "../include/Warrior.h"

void Warrior::attack(Hero &enemy)
{
    unsigned int damage, defence;
    unsigned int HP = enemy.getHP();
    defence = ((rand() % (enemy.getDEF() - enemy.getDEF() / 2)) + enemy.getDEF() / 2);
    damage = ((rand() % (getAD() - getAD() / 2)) + getAD() / 2);
    printf("Warrior DMG= %i\n", damage);
    printf("Mage DEF= %i\n", defence);
    std::cout  << this->name << "(Warrior)" << " is performing attack!" << std::endl;
    HP -= (damage - defence);
    enemy.setHP(HP);
    printf("Inflicted damage: %i =>", (damage - defence));
    printf("Mage HP= %i\n", enemy.getHP());
}

Warrior::Warrior(std::string n) : Hero(n)
{
    this->_LVL = 1;
    this->_EXP = 0;
    this->_EXP2NEXTLVL = static_cast<unsigned int>((50/3) * (pow(this->_LVL, 3) - 6 * pow(this->_LVL, 3) + (17 * this->_LVL) - 11)); //LVL^UP FORMULA

    this->_HP = 150;
    this->_MANA = 0;
    this->_AD = 12;
    this->_AP = 0;
    this->_DEF = 10;

    this->_Strenght = 6;
    this->_Vitality = 6;
    this->_Dexterity = 4;
    this->_Intelligence = 0;
    this->_Luck = 0;

    std::cout << "Warrior constructor works here...\n";
}

Warrior::~Warrior()
{
    std::cout << "Warrior destructor works here...\n";
}

