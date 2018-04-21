#include <iostream>
#include <utility>
#include <string>
#include <vector>

#ifndef HEROES_HERO_H
#define HEROES_HERO_H

class Hero  //BASE CLASS
{
protected:
    unsigned int _HP;
    unsigned int _MANA;
    unsigned int _AD;
    unsigned int _DEF;
    std::string name;

public:
    void status();
    unsigned int *getHP();
    unsigned int *getMANA();
    unsigned int getAD();
    unsigned int getDEF();
    virtual void attack(Hero &) = 0;

    explicit Hero(std::string name = "Unknown");
    virtual ~Hero();

};

#endif //HEROES_HERO_H
