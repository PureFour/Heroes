#include "../include/Hero.h"
#include "../include/Warrior.h"
#include "../include/Mage.h"
#include "../include/Archer.h"

Hero::Hero(std::string n) :name(std::move(n)) {}
Hero::~Hero() = default;

const std::string &Hero::getName() const{ return this->name; }
const unsigned int &Hero::getHP() const { return this->_HP; }
const unsigned int &Hero::getMANA() const { return this->_MANA; }
const unsigned int &Hero::getAD() const { return this->_AD; }
const unsigned int &Hero::getAP() const { return this->_AP; }
const unsigned int &Hero::getDEF() const { return this->_DEF; }
const unsigned int &Hero::getLVL() const { return this->_LVL; }
const unsigned int &Hero::getEXP() const { return this->_EXP; }
const unsigned int &Hero::getEXP2NEXTLVL() const { return this->_EXP2NEXTLVL; }

const unsigned int &Hero::getStr() const { return this->_Strenght; }
const unsigned int &Hero::getVit() const { return this->_Vitality; }
const unsigned int &Hero::getDex() const { return this->_Dexterity; }
const unsigned int &Hero::getInt() const { return this->_Intelligence; }
const unsigned int &Hero::getLuck() const { return this->_Luck; }

const unsigned int& Hero::setHP(unsigned int hp)
{
    _HP = hp;
}

const unsigned int& Hero::setLVL(unsigned int lv)
{
    _LVL = lv;
}

Hero *Hero::Initialize(std::string n, unsigned int choice)
{
    switch(choice)
    {
        case 1:
            return new Warrior(n);
        case 2:
            return new Mage(n);
        case 3:
            return new Archer(n);
        default:
            break;
    }
}

void Hero::status()
{
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Lvl: " << getLVL() << std::endl;
    std::cout << "Exp: " << getEXP() << std::endl;
    std::cout << "Exp to next Lvl: " << getEXP2NEXTLVL() << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "HP: " << getHP() << std::endl;
    std::cout << "MANA: " << getMANA() << std::endl;
    std::cout << "AD: " << getAD() << std::endl;
    std::cout << "AP: " << getAP() << std::endl;
    std::cout << "DEF: " << getDEF() << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Strenght: " << getStr() << std::endl;
    std::cout << "Vitality: " << getVit() << std::endl;
    std::cout << "Dexterity: " << getDex() << std::endl;
    std::cout << "Intelligence: " << getInt() << std::endl;
    std::cout << "Luck: " << getLuck() << std::endl;
    std::cout << std::string(50, '-') << std::endl;
}

void Hero::LevelUp()
{
    this->_LVL += 1;
}





