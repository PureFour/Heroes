#include "../include/Hero.h"

void Hero::status()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "HP: " << _HP << std::endl;
    std::cout << "MANA: " << _MANA << std::endl;
    std::cout << "AD: " << _AD << std::endl;
    std::cout << "DEF: " << _DEF << std::endl;
    std::cout << std::endl;
}

Hero::Hero(std::string n) :name(std::move(n)) {}
Hero::~Hero() = default;

unsigned int *Hero::getHP() { return &_HP;}
unsigned int *Hero::getMANA() { return &_MANA;}
unsigned int Hero::getAD() { return _AD;}
unsigned int Hero::getDEF() { return _DEF;}


