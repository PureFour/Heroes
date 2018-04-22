#include "../include/Functions.h" //including iostream...
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <ctime>
#include <cmath>
#ifndef HEROES_HERO_H
#define HEROES_HERO_H

class Hero  //BASE CLASS FOR HEROES
{
protected:
    //Basic Stats
    std::string name;
    unsigned int _HP;
    unsigned int _MANA;
    unsigned int _AD;
    unsigned int _AP; //Magic DMG
    unsigned int _DEF;
    unsigned int _LVL;
    unsigned int _EXP;
    unsigned int _EXP2NEXTLVL;
    //
    unsigned int _Strenght;
    unsigned int _Vitality;
    unsigned int _Dexterity;
    unsigned int _Intelligence;
    unsigned int _Luck;
    //
public:
    //getFunctions
    const std::string &getName() const;
    const unsigned int &getHP() const;
    const unsigned int &getMANA() const;
    const unsigned int &getAD() const;
    const unsigned int &getAP() const;
    const unsigned int &getDEF() const;
    const unsigned int &getLVL() const;
    const unsigned int &getEXP() const;
    const unsigned int &getEXP2NEXTLVL() const;
    const unsigned int &getStr() const;
    const unsigned int &getVit() const;
    const unsigned int &getDex() const;
    const unsigned int &getInt() const;
    const unsigned int &getLuck() const;
    //HeroFunctions
    void status();
    Hero *Initialize(std::string, unsigned int);
    void LevelUp();
    virtual void attack(Hero &) = 0;
    void Travel(); //TODO BARTEK!!!
    //
    explicit Hero(std::string name = "Unknown");
    virtual ~Hero();
    //
};

#endif //HEROES_HERO_H
