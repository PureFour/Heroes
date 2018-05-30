#include "../include/Hero.h"
#include "../include/Warrior.h"

Warrior::Warrior(std::string n) : Hero(n)
{
    this->_X = 0;
    this->_Y = 0;

    this->_LVL = 1;
    this->_EXP = 0;
    this->_EXP2NEXTLVL = static_cast<unsigned int>( ( (50/3) * ( pow(this->_LVL, 3.0) ) - (6.0 * pow(this->_LVL, 3.0) ) + (17.0 * this->_LVL) - 11.0) ); //LVL^UP FORMULA

    this->_HP = 150;
    this->_MANA = 0;
    this->_AD = 12;
    this->_AP = 0;
    this->_DEF = 10;

    this->_Strenght = 6;
    this->_Vitality = 6;
    this->_Dexterity = 4;
    this->_Intelligence = 0;
    this->_Luck = 5;

    this->_inventory = {};
    this->_armor = {nullptr, nullptr, nullptr, nullptr};
    this->_weapon = nullptr;
    std::cout << "Warrior constructor works here...\n";
}

Warrior::~Warrior()
{
    std::cout << "Warrior destructor works here...\n";
}

void Warrior::attack(Hero &enemy)
{
    unsigned int damage, defence, attack;
    unsigned int HP = enemy.getHP();
    defence = ((rand() % (enemy.getDEF() - enemy.getDEF() / 2)) + enemy.getDEF() / 2);
    attack = ((rand() % (getAD() - getAD() / 2)) + getAD() / 2);
    damage = attack - defence;
    std::cout  << this->name << "(Warrior)" << " is performing attack!\n";
    if(Crit(getLuck()))
    {
        damage *= 2;
        std::cout << "Critical HIT! : " << damage << std::endl;
    }
    else printf("Warrior DMG= %i\n", damage);
    std::cout  << enemy.getName() << " DEF = " << defence << std::endl;
    std::cout  << "Inflicted damage: " << ((damage > defence) ? (damage - defence) : 0) << " to " << enemy.getName() << std::endl;
    if(defence < damage)
    {
        HP -= (damage - defence);
        enemy.setHP(HP);
    }
    if(damage > HP) enemy.setHP(0);
}

void Warrior::equip(Item &item)
{
    std::cout << "I equipping item!" << std::endl;
    _weapon = &item;
    _AD = (getAD() + 5);
}

const void Warrior::showItems() const
{
    std::cout << "WARRIOR EQUIPMENT...\n";
    std::cout << "WARRIOR ARMOR\n";
    for(auto i = 0; i < _armor.size(); i++) _armor[i] ->showItem();
    std::cout << "WARRIOR WEAPON\n";
    _weapon->showItem();
}

