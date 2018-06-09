#include "../include/Functions.h" //including iostream...
#include <iomanip>
#include <string>
#include <utility>
#include <ctime>
#include <algorithm>
#include <unistd.h>
#include <cmath>
#include "Inventory.h"
#ifndef HEROES_HERO_H
#define HEROES_HERO_H

class Hero : public Inventory   //BASE CLASS FOR HEROES //public: inv
{
protected:
    //Hero position on map
    unsigned int _X;
    unsigned int _Y;
    unsigned int _GOLD;
    //Basic Stats
    std::string name;
    unsigned int _HP;
    unsigned int _maxHP;
    unsigned int _MANA;
    unsigned int _maxMANA;
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
    //Hero equipment
    std::array<Item*, 4> _armor; //helmet, breastplate, shield, boots
    Item* _weapon;
    unsigned int _Arrows;
    //
    //Functions
    bool Crit(unsigned int);
    void addPoints(int);
public:
    //getFunctions
    const unsigned int &getX() const;
    const unsigned int &getY() const;
    const unsigned int &getGold() const;
    const std::string &getName() const;
    const unsigned int &getHP() const;
    const unsigned int &getMaxHP() const;
    const unsigned int &getMANA() const;
    const unsigned int &getMaxMANA() const;
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
    const unsigned int &getArrows() const;
    //SetFunctions
    void setName(std::string);
    void setHP(unsigned int);
    void setMaxHP(unsigned int);
    void setMANA(unsigned int);
    void setMaxMANA(unsigned int);
    void setLVL(unsigned int);
    void setEXP(unsigned int);
    void setEXP2NEXTLV(unsigned int);
    void setGold(unsigned int);
    void setAD(unsigned int);
    void setAP(unsigned int);
    void setDEF(unsigned int);
    void setStr(unsigned int);
    void setVit(unsigned int);
    void setDex(unsigned int);
    void setInt(unsigned int);
    void setLuck(unsigned int);
    void setArrows(unsigned int);
    //
    //HeroFunctions
    void status();
    Hero *Initialize(std::string, unsigned int);
    void LevelUp();
    virtual void attack(Hero &) = 0;
    virtual void equip() = 0;
    virtual const void showItems() const = 0;
  //  void Travel();
    //
    explicit Hero(std::string name = "Unknown");
    virtual ~Hero();
    //
};

#endif //HEROES_HERO_H
