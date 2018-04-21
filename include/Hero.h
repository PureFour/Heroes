#include <iostream>
#include <utility>
#include <string>
#include <vector>

#ifndef HEROES_HERO_H
#define HEROES_HERO_H

class Hero  //BASE CLASS FOR HEROES
{
protected:
    unsigned int _HP;
    unsigned int _MANA;
    unsigned int _AD;
    unsigned int _AP; //Magic DMG
    unsigned int _DEF;
    std::string name;

public:
    void status();
    //getFunctions
    const std::string &getName() const;
    const unsigned int &getHP() const;
    const unsigned int &getMANA() const;
    const unsigned int &getAD() const;
    const unsigned int &getAP() const;
    const unsigned int &getDEF() const;
    //

    virtual void attack(Hero &) = 0;

    explicit Hero(std::string name = "Unknown");
    virtual ~Hero();

};

#endif //HEROES_HERO_H
