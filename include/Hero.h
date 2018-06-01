#include "../include/Functions.h" //including iostream...
#include <iomanip>
#include <string>
#include <utility>
#include <ctime>
#include <unistd.h>
#include <cmath>
#include "Inventory.h"
#ifndef HEROES_HERO_H
#define HEROES_HERO_H

class Hero : public Inventory  //BASE CLASS FOR HEROES
{
protected:
    //Hero position on map
    unsigned int _X;
    unsigned int _Y;
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
    Inventory _inventory; //Hero backpack
    std::array<Item*, 4> _armor; //helmet, breastplate, shield, boots
    Item* _weapon;
    //
    //Functions
    bool Crit(unsigned int);
    void addPoints(int);
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
    const std::array<Item*, 4> & getArmor() const;
    const Item* getWeapon() const;
    //SetFunctions
    const unsigned int &setHP(unsigned int);
    const unsigned int &setLVL(unsigned int);
    const unsigned int &setEXP(unsigned int);

    //
    //HeroFunctions
    void status();
    Hero *Initialize(std::string, unsigned int);
    void LevelUp();
    virtual void attack(Hero &) = 0;
    virtual void equip(Item &) = 0;
    virtual const void showItems() const = 0;
  //  void Travel();
    //
    explicit Hero(std::string name = "Unknown");
    virtual ~Hero();
    //
};

#endif //HEROES_HERO_H
