#include "../include/Hero.h"

Hero::Hero(std::string n) :name(std::move(n)) {}
Hero::~Hero() = default;

const std::string &Hero::getName() const{
    return this->name;
}
const unsigned int &Hero::getHP() const {
    return this->_HP;
}

const unsigned int &Hero::getMANA() const {
    return this->_MANA;
}

const unsigned int &Hero::getAD() const {
    return this->_AD;
}

const unsigned int &Hero::getAP() const {
    return this->_AP;
}
const unsigned int &Hero::getDEF() const {
    return this->_DEF;
}
const unsigned int &Hero::getLVL() const {
    return this->_LVL;
}
const unsigned int &Hero::getEXP() const {
    return this->_EXP;
}
const unsigned int &Hero::getEXP2NEXTLVL() const {
    return this->_EXP2NEXTLVL;
}

void Hero::status()
{
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "HP: " << getHP() << std::endl;
    std::cout << "MANA: " << getMANA() << std::endl;
    std::cout << "AD: " << getAD() << std::endl;
    std::cout << "DEF: " << getDEF() << std::endl;
    std::cout << std::endl;
}

void Hero::LevelUp()
{

}





