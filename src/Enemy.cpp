
#include "../include/Enemy.h"

Enemy::Enemy(std::string n) : Hero(n)
{
    this->_LVL = 1;
    this->_EXP = 0;
    this->_EXP2NEXTLVL = 0;

    this->_HP = 20;
    this->_MANA = 0;
    this->_AD = 2;
    this->_AP = 0;
    this->_DEF = 1;

    this->_Strenght = 1;
    this->_Vitality = 1;
    this->_Dexterity = 1;
    this->_Intelligence = 0;
    this->_Luck = 0;
}

Enemy::~Enemy() {}

void Enemy::attack(Hero &)
{

}